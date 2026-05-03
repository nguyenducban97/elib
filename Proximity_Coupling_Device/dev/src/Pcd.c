/**
 * @file Pcd.c
 * @brief Implementation of Proximity Coupling Device functionality.
 * @author [Your Name]
 * @date [Date]
 * @version 1.0
 *
 * This file contains the implementation of the Proximity Coupling Device (PCD)
 * library functions. It is compatible with the C99 standard and uses Doxygen
 * for documentation.
 */

#include "Pcd.h"
#include "Pcd_Ipw.h"

/**
 * @brief Initializes the Proximity Coupling Device.
 *
 * This function performs the necessary initialization steps for the PCD.
 *
 * @return 0 on success, non-zero on failure.
 */
void PCD_Init(const Pcd_Type* pConfig)
{
    /* PCD_SWS_01: before trigger any command to PCD. Host must ensure all dependencie drivers are in ready state, unless stop execution immediately. */
    if((NULL_PTR != pConfig) && (u8Pcd_Driver_Status == PCD_DRIVER_UNINIT) && (HAL_SPI_STATE_RESET != HAL_SPI_GetState(&SPI_CHANNEL)))
    {
        /* PCD_SWS_03: if any process is triggered when PCD driver status is in wrong state, it will be canceled. */
        HAL_NVIC_DisableIRQ(SPI_IRQ_HANDLER);
        HAL_NVIC_DisableIRQ(EXTI_IRQ_HANDLER);
        /*TODO: add condition to check if Ipw function is false or not. */
        if (PCD_STATUS_OK == Pcd_Ipw_Init(pConfig))
        {
            u8Pcd_Driver_Status = PCD_DRIVER_INIT;
        }
        HAL_NVIC_EnableIRQ(SPI_IRQ_HANDLER);
        HAL_NVIC_EnableIRQ(EXTI_IRQ_HANDLER);
    }
}

/**
 * @brief Deinitializes the Proximity Coupling Device.
 *
 * This function performs cleanup operations for the PCD.
 *
 * @return 0 on success, non-zero on failure.
 */
void Pcd_Deinit(void) {

    return 0;
}