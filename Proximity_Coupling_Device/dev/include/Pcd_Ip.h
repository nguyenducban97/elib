/**
 * @file    Pcd_Ip.h
 * @author  BanND
 * @brief   MFRC522 proximity coupling device register definitions and API
 *          declarations.
 */

#ifndef PCD_IP_H
#define PCD_IP_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
==================================================================================================*/
#include "Pcd_Type.h"

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* Register addresses */
#define MFRC522_REG_RESERVED_00             0x00U
#define MFRC522_REG_COMMAND                 0x01U
#define MFRC522_REG_COMIEN                  0x02U
#define MFRC522_REG_DIVIEN                  0x03U
#define MFRC522_REG_COMIRQ                  0x04U
#define MFRC522_REG_DIVIRQ                  0x05U
#define MFRC522_REG_ERROR                   0x06U
#define MFRC522_REG_STATUS1                 0x07U
#define MFRC522_REG_STATUS2                 0x08U
#define MFRC522_REG_FIFODATA                0x09U
#define MFRC522_REG_FIFOLEVEL               0x0AU
#define MFRC522_REG_WATERLEVEL              0x0BU
#define MFRC522_REG_CONTROL                 0x0CU
#define MFRC522_REG_BITFRAMING              0x0DU
#define MFRC522_REG_COLL                    0x0EU
#define MFRC522_REG_RESERVED_0F             0x0FU
#define MFRC522_REG_RESERVED_10             0x10U
#define MFRC522_REG_MODE                    0x11U
#define MFRC522_REG_TXMODE                  0x12U
#define MFRC522_REG_RXMODE                  0x13U
#define MFRC522_REG_TXCONTROL               0x14U
#define MFRC522_REG_TXASK                   0x15U
#define MFRC522_REG_TXSEL                   0x16U
#define MFRC522_REG_RXSEL                   0x17U
#define MFRC522_REG_RXTHRESHOLD             0x18U
#define MFRC522_REG_DEMOD                   0x19U
#define MFRC522_REG_RESERVED_1A             0x1AU
#define MFRC522_REG_RESERVED_1B             0x1BU
#define MFRC522_REG_MFTX                    0x1CU
#define MFRC522_REG_MFRX                    0x1DU
#define MFRC522_REG_RESERVED_1E             0x1EU
#define MFRC522_REG_SERIALSPEED             0x1FU
#define MFRC522_REG_RESERVED_20             0x20U
#define MFRC522_REG_CRCRESULT_MSB           0x21U
#define MFRC522_REG_CRCRESULT_LSB           0x22U
#define MFRC522_REG_RESERVED_23             0x23U
#define MFRC522_REG_MODWIDTH                0x24U
#define MFRC522_REG_RESERVED_25             0x25U
#define MFRC522_REG_RFCFG                   0x26U
#define MFRC522_REG_GSN                     0x27U
#define MFRC522_REG_CWGSP                   0x28U
#define MFRC522_REG_MODGSP                  0x29U
#define MFRC522_REG_TMODE                   0x2AU
#define MFRC522_REG_TPRESCALER              0x2BU
#define MFRC522_REG_TRELOAD_HI              0x2CU
#define MFRC522_REG_TRELOAD_LO              0x2DU
#define MFRC522_REG_TCOUNTERVAL_HI          0x2EU
#define MFRC522_REG_TCOUNTERVAL_LO          0x2FU
#define MFRC522_REG_RESERVED_30             0x30U
#define MFRC522_REG_TESTSEL1                0x31U
#define MFRC522_REG_TESTSEL2                0x32U
#define MFRC522_REG_TESTPINEN               0x33U
#define MFRC522_REG_TESTPINVALUE            0x34U
#define MFRC522_REG_TESTBUS                 0x35U
#define MFRC522_REG_AUTOTEST                0x36U
#define MFRC522_REG_VERSION                 0x37U
#define MFRC522_REG_ANALOGTEST              0x38U
#define MFRC522_REG_TESTDAC1                0x39U
#define MFRC522_REG_TESTDAC2                0x3AU
#define MFRC522_REG_TESTADC                 0x3BU
#define MFRC522_REG_RESERVED_3C             0x3CU
#define MFRC522_REG_RESERVED_3D             0x3DU
#define MFRC522_REG_RESERVED_3E             0x3EU
#define MFRC522_REG_RESERVED_3F             0x3FU

/* Bit masks for individual registers */

/* CommandReg (0x01) */
#define MFRC522_COMMAND_RCV_OFF             (1U << 5)
#define MFRC522_COMMAND_POWER_DOWN          (1U << 4)
#define MFRC522_COMMAND_MASK                0x0FU
#define MFRC522_COMMAND_IDLE                0x00U
#define MFRC522_COMMAND_MEM                 0x01U
#define MFRC522_COMMAND_GEN_RID             0x02U
#define MFRC522_COMMAND_CAL_CRC             0x03U
#define MFRC522_COMMAND_TRANSMIT            0x04U
#define MFRC522_COMMAND_NOCHANGE            0x05U
#define MFRC522_COMMAND_RECEIVE             0x06U
#define MFRC522_COMMAND_TRANSCEIVE          0x07U
#define MFRC522_COMMAND_MFAUTHEN            0x09U
#define MFRC522_COMMAND_SOFT_RESET          0x0AU

/* ComIEnReg (0x02) */
#define MFRC522_COMIEN_IRQ_INV              (1U << 7)
#define MFRC522_COMIEN_TX_IEN               (1U << 6)
#define MFRC522_COMIEN_RX_IEN               (1U << 5)
#define MFRC522_COMIEN_IDLE_IEN             (1U << 4)
#define MFRC522_COMIEN_HI_ALERT_IEN         (1U << 3)
#define MFRC522_COMIEN_LO_ALERT_IEN         (1U << 2)
#define MFRC522_COMIEN_ERR_IEN              (1U << 1)
#define MFRC522_COMIEN_TIMER_IEN            (1U << 0)

/* DivIEnReg (0x03) */
#define MFRC522_DIVIEN_IRQ_PUSH_PULL        (1U << 7)
#define MFRC522_DIVIEN_MFIN_ACT_IEN         (1U << 4)
#define MFRC522_DIVIEN_CRC_IEN              (1U << 2)

/* ComIrqReg (0x04) */
#define MFRC522_COMIRQ_SET1                 (1U << 7)
#define MFRC522_COMIRQ_TX_IRQ               (1U << 6)
#define MFRC522_COMIRQ_RX_IRQ               (1U << 5)
#define MFRC522_COMIRQ_IDLE_IRQ             (1U << 4)
#define MFRC522_COMIRQ_HI_ALERT_IRQ         (1U << 3)
#define MFRC522_COMIRQ_LO_ALERT_IRQ         (1U << 2)
#define MFRC522_COMIRQ_ERR_IRQ              (1U << 1)
#define MFRC522_COMIRQ_TIMER_IRQ            (1U << 0)
#define MFRC522_COMIRQ_MASK                 0xFFU

/* DivIrqReg (0x05) */
#define MFRC522_DIVIRQ_SET2                 (1U << 7)
#define MFRC522_DIVIRQ_MFIN_ACT_IRQ         (1U << 4)
#define MFRC522_DIVIRQ_CRC_IRQ              (1U << 2)

/* ErrorReg (0x06) */
#define MFRC522_ERROR_WR_ERR                (1U << 7)
#define MFRC522_ERROR_TEMP_ERR              (1U << 6)
#define MFRC522_ERROR_BUFFER_OVFL           (1U << 4)
#define MFRC522_ERROR_COLL_ERR              (1U << 3)
#define MFRC522_ERROR_CRC_ERR               (1U << 2)
#define MFRC522_ERROR_PARITY_ERR            (1U << 1)
#define MFRC522_ERROR_PROTOCOL_ERR          (1U << 0)

/* Status1Reg (0x07) */
#define MFRC522_STATUS1_CRC_OK              (1U << 6)
#define MFRC522_STATUS1_CRC_READY           (1U << 5)
#define MFRC522_STATUS1_IRQ                 (1U << 4)
#define MFRC522_STATUS1_T_RUNNING           (1U << 3)
#define MFRC522_STATUS1_HI_ALERT            (1U << 1)
#define MFRC522_STATUS1_LO_ALERT            (1U << 0)

/* Status2Reg (0x08) */
#define MFRC522_STATUS2_TEMP_SENS_CLEAR     (1U << 7)
#define MFRC522_STATUS2_I2C_FORCE_HS        (1U << 6)
#define MFRC522_STATUS2_MF_CRYPTO1_ON       (1U << 3)
#define MFRC522_STATUS2_MODEM_STATE_IDLE    0x00U
#define MFRC522_STATUS2_MODEM_STATE_WAIT_BFR 0x01U
#define MFRC522_STATUS2_MODEM_STATE_TXWAIT  0x02U
#define MFRC522_STATUS2_MODEM_STATE_TRANSMITING 0x03U
#define MFRC522_STATUS2_MODEM_STATE_RXWAIT  0x04U
#define MFRC522_STATUS2_MODEM_STATE_WAIT4DATA 0x05U
#define MFRC522_STATUS2_MODEM_STATE_RECEIVE 0x06U
#define MFRC522_STATUS2_MODEM_STATE_MASK    0x07U

/* FIFOLevelReg (0x0A) */
#define MFRC522_FIFOLEVEL_FLUSH_BUFFER      (1U << 7)
#define MFRC522_FIFOLEVEL_MASK              0x7FU

/* WaterLevelReg (0x0B) */
#define MFRC522_WATERLEVEL_MASK             0x3FU

/* ControlReg (0x0C) */
#define MFRC522_CONTROL_T_STOP_NOW          (1U << 7)
#define MFRC522_CONTROL_T_START_NOW         (1U << 6)
#define MFRC522_CONTROL_RX_LAST_BITS_MASK   0x07U

/* BitFramingReg (0x0D) */
#define MFRC522_BITFRAMING_START_SEND       (1U << 7)
#define MFRC522_BITFRAMING_RX_ALIGN_MASK    0x70U
#define MFRC522_BITFRAMING_TX_LAST_BITS_MASK 0x07U

/* CollReg (0x0E) */
#define MFRC522_COLL_VALUES_AFTER_COLL      (1U << 7)
#define MFRC522_COLL_POS_NOT_VALID          (1U << 5)
#define MFRC522_COLL_POS_MASK               0x1FU

/* ModeReg (0x11) */
#define MFRC522_MODE_MSB_FIRST              (1U << 7)
#define MFRC522_MODE_TX_WAIT_RF             (1U << 5)
#define MFRC522_MODE_POL_MFIN               (1U << 3)
#define MFRC522_MODE_CRC_PRESET_MASK        0x03U

/* TxModeReg (0x12) */
#define MFRC522_TXMODE_TX_CRC_EN            (1U << 7)
#define MFRC522_TXMODE_TX_SPEED_MASK        0x70U
#define MFRC522_TXMODE_INV_MOD              (1U << 3)

/* RxModeReg (0x13) */
#define MFRC522_RXMODE_RX_CRC_EN            (1U << 7)
#define MFRC522_RXMODE_RX_SPEED_MASK        0x70U
#define MFRC522_RXMODE_RX_NO_ERR            (1U << 3)
#define MFRC522_RXMODE_RX_MULTIPLE          (1U << 2)

/* TxControlReg (0x14) */
#define MFRC522_TXCONTROL_INV_TX2_RF_ON     (1U << 7)
#define MFRC522_TXCONTROL_INV_TX1_RF_ON     (1U << 6)
#define MFRC522_TXCONTROL_INV_TX2_RF_OFF    (1U << 5)
#define MFRC522_TXCONTROL_INV_TX1_RF_OFF    (1U << 4)
#define MFRC522_TXCONTROL_TX2_CW            (1U << 3)
#define MFRC522_TXCONTROL_TX2_RF_EN         (1U << 1)
#define MFRC522_TXCONTROL_TX1_RF_EN         (1U << 0)

/* TxASKReg (0x15) */
#define MFRC522_TXASK_FORCE_100_ASK         (1U << 6)

/* TxSelReg (0x16) */
#define MFRC522_TXSEL_DRIVER_SEL_MASK       0x30U
#define MFRC522_TXSEL_MF_OUT_SEL_MASK       0x0FU

/* RxSelReg (0x17) */
#define MFRC522_RXSEL_UART_SEL_MASK         0xC0U
#define MFRC522_RXSEL_RX_WAIT_MASK          0x3FU

/* RxThresholdReg (0x18) */
#define MFRC522_RXTHRESHOLD_MIN_LEVEL_MASK  0xF0U
#define MFRC522_RXTHRESHOLD_COLL_LEVEL_MASK 0x07U

/* DemodReg (0x19) */
#define MFRC522_DEMOD_ADD_IQ_MASK           0xC0U
#define MFRC522_DEMOD_FIX_IQ                (1U << 5)
#define MFRC522_DEMOD_T_PRESCAL_EVEN        (1U << 4)
#define MFRC522_DEMOD_TAU_RCV_MASK          0x0CU
#define MFRC522_DEMOD_TAU_SYNC_MASK         0x03U

/* MfTxReg (0x1C) */
#define MFRC522_MFTX_TX_WAIT_MASK           0x03U

/* MfRxReg (0x1D) */
#define MFRC522_MFRX_PARITY_DISABLE         (1U << 4)

/* CRCResultReg MSB (0x21) */
#define MFRC522_CRCRESULT_MSB_MASK          0xFFU

/* CRCResultReg LSB (0x22) */
#define MFRC522_CRCRESULT_LSB_MASK          0xFFU

/* ModWidthReg (0x24) */
#define MFRC522_MODWIDTH_MASK               0xFFU

/* RFCfgReg (0x26) */
#define MFRC522_RFCFG_RX_GAIN_MASK          0x70U

/* GsNReg (0x27) */
#define MFRC522_GSN_CWGSN_MASK              0xF0U
#define MFRC522_GSN_MODGSN_MASK             0x0FU

/* CWGsPReg (0x28) */
#define MFRC522_CWGSP_MASK                  0x3FU

/* ModGsPReg (0x29) */
#define MFRC522_MODGSP_MASK                 0x3FU

/* TModeReg (0x2A) */
#define MFRC522_TMODE_T_AUTO                (1U << 7)
#define MFRC522_TMODE_T_GATED_MASK          0x60U
#define MFRC522_TMODE_T_AUTO_RESTART        (1U << 4)
#define MFRC522_TMODE_T_PRESCALER_HI_MASK   0x0FU

/* TPrescalerReg (0x2B) */
#define MFRC522_TPRESCALER_MASK             0xFFU

/* TReloadReg Hi (0x2C) */
#define MFRC522_TRELOAD_HI_MASK             0xFFU

/* TReloadReg Lo (0x2D) */
#define MFRC522_TRELOAD_LO_MASK             0xFFU

/* TCounterValReg Hi (0x2E) */
#define MFRC522_TCOUNTERVAL_HI_MASK         0xFFU

/* TCounterValReg Lo (0x2F) */
#define MFRC522_TCOUNTERVAL_LO_MASK         0xFFU

/* TestSel1Reg (0x31) */
#define MFRC522_TESTSEL1_TST_BUS_BIT_SEL_MASK 0x07U

/* TestSel2Reg (0x32) */
#define MFRC522_TESTSEL2_TST_BUS_FLIP       (1U << 7)
#define MFRC522_TESTSEL2_PRBS9              (1U << 6)
#define MFRC522_TESTSEL2_PRBS15             (1U << 5)
#define MFRC522_TESTSEL2_TEST_BUS_SEL_MASK  0x1FU

/* TestPinEnReg (0x33) */
#define MFRC522_TESTPINEN_RS232_LINE_EN     (1U << 7)
#define MFRC522_TESTPINEN_TEST_PIN_EN_MASK  0x7EU

/* TestPinValueReg (0x34) */
#define MFRC522_TESTPINVALUE_USE_IO         (1U << 7)
#define MFRC522_TESTPINVALUE_TEST_PIN_VALUE_MASK 0x7EU

/* TestBusReg (0x35) */
#define MFRC522_TESTBUS_MASK                0xFFU

/* AutoTestReg (0x36) */
#define MFRC522_AUTOTEST_AMP_RCV            (1U << 6)
#define MFRC522_AUTOTEST_RFT_MASK           0x30U
#define MFRC522_AUTOTEST_SELF_TEST_MASK     0x0FU

/* VersionReg (0x37) */
#define MFRC522_VERSION_CHIP_TYPE_MASK      0xF0U
#define MFRC522_VERSION_VERSION_MASK        0x0FU

/* AnalogTestReg (0x38) */
#define MFRC522_ANALOGTEST_ANALOG_SEL_AUX1_MASK 0xF0U
#define MFRC522_ANALOGTEST_ANALOG_SEL_AUX2_MASK 0x0FU

/* TestDAC1Reg (0x39) */
#define MFRC522_TESTDAC1_TEST_DAC1_MASK     0x3FU

/* TestDAC2Reg (0x3A) */
#define MFRC522_TESTDAC2_TEST_DAC2_MASK     0x3FU

/* TestADCReg (0x3B) */
#define MFRC522_TESTADC_ADC_I_MASK          0xF0U
#define MFRC522_TESTADC_ADC_Q_MASK          0x0FU

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

/**
 * @brief Execute a command on the MFRC522 device.
 * @param u8Cmd Command value.
 * @return MFRC522 operation status.
 */
Pcd_StatusType Pcd_Ip_TriggerCmd(uint8_t u8Cmd);

/**
 * @brief Write an internal buffer to the MFRC522.
 * @param buff Input buffer.
 * @param u8Size Number of bytes to write.
 * @return MFRC522 operation status.
 */
Pcd_StatusType Pcd_Ip_WriteIntBuffer(const uint8_t *buff, uint8_t u8Size);

/**
 * @brief Write a single value to a register.
 * @param u8Addr Register address.
 * @param u8Val Register value.
 * @return MFRC522 operation status.
 */
Pcd_StatusType Pcd_Ip_WriteRegister(uint8_t u8Addr, uint8_t u8Val);

/**
 * @brief Read a single register value.
 * @param u8Addr Register address.
 * @param buff Output buffer for register value.
 * @return MFRC522 operation status.
 */
Pcd_StatusType Pcd_Ip_ReadRegister(uint8_t u8Addr, uint8_t *buff);

/**
 * @brief Write data to the FIFO buffer.
 * @param buff Input data.
 * @param u8Size Number of bytes to write.
 * @return MFRC522 operation status.
 */
Pcd_StatusType Pcd_Ip_WriteFIFO(const uint8_t *buff, uint8_t u8Size);

/**
 * @brief Read data from the FIFO buffer.
 * @param buff Output buffer.
 * @param u8Size Number of bytes to read.
 * @return MFRC522 operation status.
 */
Pcd_StatusType Pcd_Ip_ReadFIFO(uint8_t *buff, uint8_t u8Size);

/**
 * @brief Flush the FIFO buffer.
 * @return MFRC522 operation status.
 */
Pcd_StatusType Pcd_Ip_FlushFIFO(void);

Pcd_StatusType Pcd_Ip_GetStatus (uint8_t *u8CommandStatus);

#ifdef __cplusplus
}
#endif

#endif /* PCD_IP_H */
