/**
  ******************************************************************************
  * @file    mfrc522.h
  * @author  BanND
  * @brief   Header file for MFRC module.
  ******************************************************************************
  */

#ifdef __cplusplus
extern "C" {
#endif

/*-------------------------------- Includes ----------------------------------*/
#include <stdbool.h>
#include "Pcd_Ip.h"
#ifdef STM32F103xB
    #include "spi.h"
#endif
/*----------------------------- Global typedefs ------------------------------*/
/*------------------------------- Definitions --------------------------------*/
#define MFRC522_SPI_ADDR_WRITE_MASK (0x7EU)
#define MFRC522_SPI_ADDR_READ_MASK  (0xFEU)
#define MFRC522_SPI_ADDR_READ_FLAG  (0x80U)
#define MFRC522_FLUSH_CODE (0x80U)
#define TIMEOUT (500U)
/*----------------------------- Global variables -----------------------------*/
/*---------------------------- Global prototypes -----------------------------*/
static bool IsMfrcFifoEmpty(void);
static bool IsMfrcFifoFull(void);
static bool IsMfrcFifoEmpty(void)
{
    uint8_t RetVal = 0;
    
    MFRC522_ReadRegister(MFRC522_REG_FIFOLEVEL, &RetVal);
    if(0 == RetVal)
    {
        return true;
    }

    return false;
}

static bool IsMfrcFifoFull(void)
{
    uint8_t RetVal = 0;
    
    MFRC522_ReadRegister(MFRC522_REG_FIFOLEVEL, &RetVal);
    if(0x3FU == RetVal) /* MFRC522 has 64 Fifo elements */
    {
        return true;
    }

    return false;
}

/**
 * @brief  Writes a single byte to an MFRC522 register via SPI.
 * @param  u8Addr   Register address to write to
 * @param  u8Val    Value to write to the register
 * @return Pcd_StatusType - PCD_STATUS_OK if successful, PCD_STATUS_ERROR otherwise
 */
Pcd_StatusType Pcd_Ip_WriteRegister(uint8_t u8Addr, uint8_t u8Val)
{
    Pcd_StatusType RetVal = PCD_STATUS_OK;
    uint8_t au8TransData[2] = {((u8Addr<<1) & MFRC522_SPI_ADDR_WRITE_MASK), u8Val};

    HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_RESET);
    if(HAL_OK == HAL_SPI_Transmit(&hspi1, au8TransData, 2, 100))
    {
        RetVal = PCD_STATUS_ERROR;
    }
    HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_SET);

    return RetVal;
}

/**
 * @brief  Reads a single byte from an MFRC522 register via SPI.
 * @param  u8Addr   Register address to read from
 * @param  buff     Pointer to buffer where the read value will be stored
 * @return Pcd_StatusType - PCD_STATUS_OK if successful, PCD_STATUS_ERROR otherwise
 */
Pcd_StatusType Pcd_Ip_ReadRegister(uint8_t u8Addr, uint8_t *buff)
{
    Pcd_StatusType RetVal = PCD_STATUS_OK;
    uint8_t au8Tmp[2];
    uint8_t au8TempAddr[2] = { (((u8Addr<<1) | MFRC522_SPI_ADDR_READ_FLAG )& MFRC522_SPI_ADDR_READ_MASK), /*First data using to trigger reading*/
                               (((u8Addr<<1) | MFRC522_SPI_ADDR_READ_FLAG )& MFRC522_SPI_ADDR_READ_MASK)
                             };

    HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_RESET);
    if(HAL_OK == HAL_SPI_TransmitReceive(&hspi1, au8TempAddr, au8Tmp, 2, 500))
    {
        *buff = au8Tmp[1]; /*Do not care the first byte, following RM*/
    }
    else
    {
        RetVal = PCD_STATUS_ERROR;
    }
    HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_SET);

    return RetVal;
}

/**
 * @brief  Writes data to the MFRC522 FIFO buffer.
 * @param  pData    Pointer to the data buffer to write
 * @param  u8Size   Number of bytes to write
 * @return Pcd_StatusType - Returns PCD_STATUS_OK
 */
Pcd_StatusType Pcd_Ip_WriteFIFO(uint8_t *pData, uint8_t u8Size)
{
    uint8_t addr = (MFRC522_REG_FIFODATA << 1) & MFRC522_SPI_ADDR_WRITE_MASK;
    uint8_t u8CommandStatus = 0;
    uint32_t u32TickStart = HAL_GetTick();
    Pcd_StatusType RetVal = PCD_STATUS_OK;

    if(!IsMfrcFifoFull())
    {
        do
        {
            Pcd_Ip_ReadRegister(MFRC522_REG_COMIRQ, &u8CommandStatus);
        } while (((HAL_GetTick() - u32TickStart) < TIMEOUT) && (MFRC522_COMIRQ_IDLE_IRQ != (u8CommandStatus & MFRC522_COMIRQ_IDLE_IRQ)));

        if (MFRC522_COMIRQ_IDLE_IRQ == (u8CommandStatus & MFRC522_COMIRQ_IDLE_IRQ))
        {
            HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_RESET);
            assert_param(HAL_OK == HAL_SPI_Transmit(&hspi1, &addr, 1, 100));
            assert_param(HAL_OK == HAL_SPI_Transmit(&hspi1, pData, u8Size, (u8Size * 10)));
            HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_SET);
        }
        else
        {
            RetVal = PCD_STATUS_TIMEOUT;
        }
    }
    else
    {
        RetVal = PCD_STATUS_ERROR;
    }

    return RetVal;
}

/**
 * @brief  Reads data from the MFRC522 FIFO buffer using interrupt mode.
 * @param  au8Buff  Pointer to the buffer where FIFO data will be stored
 * @param  u8Size   Number of bytes to read
 * @return Pcd_StatusType - Returns PCD_STATUS_OK
 */
Pcd_StatusType Pcd_Ip_ReadFIFO(uint8_t *au8Buff, uint8_t u8Size)
{
    uint8_t u8CommandStatus = 0;
    Pcd_StatusType RetVal = PCD_STATUS_OK;
    uint8_t au8ReadAddr[65];
    uint8_t au8Tmp[65];
    uint8_t u8Idx;
    uint32_t u32TickStart = HAL_GetTick();
    
    if(!IsMfrcFifoEmpty())
    {
        /*prepare command to read*/
        for(u8Idx = 0; u8Idx < 65;u8Idx++)
        {
            au8ReadAddr[u8Idx] = (((MFRC522_REG_FIFODATA<<1) | MFRC522_SPI_ADDR_READ_FLAG )& MFRC522_SPI_ADDR_READ_MASK);
        }

        do
        {
            Pcd_Ip_ReadRegister(MFRC522_REG_COMIRQ, &u8CommandStatus);
        } while (((HAL_GetTick() - u32TickStart) < TIMEOUT) && (MFRC522_COMIRQ_IDLE_IRQ != (u8CommandStatus & MFRC522_COMIRQ_IDLE_IRQ)));

        if (MFRC522_COMIRQ_IDLE_IRQ == (u8CommandStatus & MFRC522_COMIRQ_IDLE_IRQ))
        {
            HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_RESET);
            if(HAL_OK == HAL_SPI_TransmitReceive(&hspi1, au8ReadAddr, au8Tmp, (u8Size+1), (u8Size*10)))
            {
                for(u8Idx = 0; u8Idx < u8Size; u8Idx++)
                {
                    *(au8Buff + u8Idx) = au8Tmp[u8Idx];
                }
            }
            else
            {
                RetVal = PCD_STATUS_ERROR;
            }
            HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_SET);
        }
        else
        {
            RetVal = PCD_STATUS_TIMEOUT;
        }
    }
    else
    {
        RetVal = PCD_STATUS_ERROR;
    }

    return RetVal;
}

/**
 * @brief  Triggers an MFRC522 command execution.
 * @param  u8Cmd    Command to execute
 * @return Pcd_StatusType - PCD_STATUS_OK if modem is idle and command is issued, PCD_STATUS_ERROR otherwise
 */
Pcd_StatusType Pcd_Ip_TriggerCmd(uint8_t u8Cmd)
{
    uint8_t u8CommandStatus = 0;
    Pcd_StatusType RetVal = PCD_STATUS_ERROR;
    uint32_t u32TickStart = HAL_GetTick();

    do
    {
        Pcd_Ip_ReadRegister(MFRC522_REG_COMIRQ, &u8CommandStatus);
    } while (((HAL_GetTick() - u32TickStart) < TIMEOUT) && (MFRC522_COMIRQ_IDLE_IRQ != (u8CommandStatus & MFRC522_COMIRQ_IDLE_IRQ)));

    if (MFRC522_COMIRQ_IDLE_IRQ == (u8CommandStatus & MFRC522_COMIRQ_IDLE_IRQ))
    {
        RetVal = Pcd_Ip_WriteRegister(MFRC522_REG_COMMAND, u8Cmd);
    }
    else
    {
        RetVal = PCD_STATUS_TIMEOUT;
    }

    return RetVal;
}

/**
 * @brief  Writes data to the internal buffer and triggers the memory command.
 * @param  buff     Pointer to the data buffer to write
 * @param  u8Size   Number of bytes to write
 * @return Pcd_StatusType - Returns PCD_STATUS_OK
 */
Pcd_StatusType Pcd_Ip_WriteIntBuffer(uint8_t *buff, uint8_t u8Size)
{
    if(PCD_STATUS_OK == Pcd_Ip_WriteFIFO(buff, u8Size))
    {
        if(PCD_STATUS_OK == Pcd_Ip_TriggerCmd(MFRC522_COMMAND_MEM))
        {
            return PCD_STATUS_OK;
        }
    }
    return PCD_STATUS_ERROR;
}

Pcd_StatusType Pcd_Ip_FlushFIFO(void)
{
    return (Pcd_Ip_WriteRegister(MFRC522_REG_FIFOLEVEL, MFRC522_FIFOLEVEL_FLUSH_BUFFER) ? PCD_STATUS_OK : PCD_STATUS_ERROR);
}

Pcd_StatusType Pcd_Ip_GetStatus (uint8_t *u8CommandStatus)
{
    return (Pcd_Ip_ReadRegister(MFRC522_REG_COMIRQ, &u8CommandStatus));
}

#ifdef __cplusplus
}
#endif