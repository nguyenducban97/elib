/**
 * @file Pcd_Ipw.c
 * @brief Proximity Coupling Device IPW (Intelligent Power management) source file.
 * @details This module provides the implementation for proximity coupling device
 *          intelligent power management functionality, wrapping lower-level IP calls.
 *
 * @author [Your Name]
 * @date 2024
 * @version 1.0.0
 *
 * @copyright [Your Company]
 * @license [Your License]
 */

/*==================================================================================================
*                                         INCLUDE FILES
==================================================================================================*/
#include "Pcd_Ipw.h"
#include "Pcd_Ip.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

Pcd_StatusType Pcd_Ipw_Init (const Pcd_Type* pConfig)
{
    Pcd_StatusType Status;
    uint8_t u8CmdStatus = 0;
    uint32_t u32TickStart = HAL_GetTick();

    if (PCD_STATUS_OK == Pcd_Ip_TriggerCmd(MFRC522_COMMAND_SOFT_RESET))
    {
        do
        {
            (void) Pcd_Ip_GetStatus(&u8CmdStatus);
        }
        while (((HAL_GetTick() - u32TickStart) < TIMEOUT) && (MFRC522_COMIRQ_IDLE_IRQ != (u8CmdStatus & MFRC522_COMIRQ_IDLE_IRQ)));

        if (MFRC522_COMIRQ_IDLE_IRQ == (u8CmdStatus & MFRC522_COMIRQ_IDLE_IRQ))
        {
            Status |= Pcd_Ip_WriteRegister(MFRC522_REG_TXMODE, pConfig->u8TxModReg);
            Status |= Pcd_Ip_WriteRegister(MFRC522_REG_RXMODE, pConfig->u8RxModReg);
            /*TODO: remove hardcode */
            if (0 != pConfig->u8ComIEnReg)
            {
                Status |=Pcd_Ip_WriteRegister(MFRC522_REG_DIVIEN, 0x80);
                Status |= Pcd_Ip_WriteRegister(MFRC522_REG_COMIEN, pConfig->u8ComIEnReg);
            }
        }
        else
        {
            Status = PCD_STATUS_TIMEOUT;
        }
    }
    else
    {
        Status = PCD_STATUS_ERROR;
    }

    return Status;
}

/**
 * @brief Sets the transmission mode for the PCD.
 *
 * @param[in] u8TxModReg Value to be written to the TxMode register.
 * @return Pcd_StatusType Status of the operation.
 */
Pcd_StatusType Pcd_Ipw_SetTxMod(uint8_t u8TxModReg)
{
    Pcd_StatusType Status;

    /* Wrapper for writing to the TxMode register */
    Status = Pcd_Ip_WriteRegister(MFRC522_REG_TXMODE, u8TxModReg);

    return Status;
}

/**
 * @brief Sets the reception mode for the PCD.
 *
 * @param[in] u8RxModReg Value to be written to the RxMode register.
 * @return Pcd_StatusType Status of the operation.
 */
Pcd_StatusType Pcd_Ipw_SetRxMod(uint8_t u8RxModReg)
{
    Pcd_StatusType Status;

    /* Wrapper for writing to the RxMode register */
    Status = Pcd_Ip_WriteRegister(MFRC522_REG_RXMODE, u8RxModReg);

    return Status;
}

/**
 * @brief Enables the specified interrupts for the PCD.
 *
 * @param[in] u8ComIEnReg Interrupt enable bitmask for the ComIEn register.
 * @return Pcd_StatusType Status of the operation.
 */
Pcd_StatusType Pcd_Ipw_EnableInterrupts(uint8_t u8ComIEnReg)
{
    Pcd_StatusType Status;

    /* Wrapper for writing to the ComIEn register */
    Status = Pcd_Ip_WriteRegister(MFRC522_REG_COMIEN, u8ComIEnReg);

    return Status;
}

/**
 * @brief Deinitializes the PCD IPW module.
 * @details Performs a soft reset to put the device in a known state.
 *
 * @return Pcd_StatusType Status of the deinitialization.
 */
Pcd_StatusType Pcd_Ipw_Deinit(void)
{
    Pcd_StatusType Status;

    /* Trigger soft reset command to clear hardware state */
    Status = Pcd_Ip_TriggerCmd(MFRC522_COMMAND_SOFT_RESET);

    return Status;
}
