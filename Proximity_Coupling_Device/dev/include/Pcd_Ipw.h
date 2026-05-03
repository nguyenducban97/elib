/**
 * @file Pcd_Ipw.h
 * @brief Proximity Coupling Device IPW (Intelligent Power management) header file.
 * @details This module provides interface definitions for proximity coupling device
 *          intelligent power management functionality.
 *
 * @author [Your Name]
 * @date 2024
 * @version 1.0.0
 *
 * @copyright [Your Company]
 * @license [Your License]
 */

#ifndef PCD_IPW_H
#define PCD_IPW_H

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

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

Pcd_StatusType Pcd_Ipw_Init (const Pcd_Type* pConfig);

/**
 * @brief Initialize the PCD IPW module.
 *
 * @return Pcd_Ipw_StatusType Status of the initialization.
 *
 * @pre None
 * @post Module is initialized and ready for use.
 */
Pcd_StatusType Pcd_Ipw_SetTxMod (uint8_t u8TxModReg);

/**
 * @brief Initialize the PCD IPW module.
 *
 * @return Pcd_Ipw_StatusType Status of the initialization.
 *
 * @pre None
 * @post Module is initialized and ready for use.
 */
Pcd_StatusType Pcd_Ipw_SetRxMod (uint8_t u8RxModReg);

/**
 * @brief Initialize the PCD IPW module.
 *
 * @return Pcd_Ipw_StatusType Status of the initialization.
 *
 * @pre None
 * @post Module is initialized and ready for use.
 */
Pcd_StatusType Pcd_Ipw_EnableInterrupts (uint8_t u8ComIEnReg);

/**
 * @brief Deinitialize the PCD IPW module.
 *
 * @return Pcd_Ipw_StatusType Status of the deinitialization.
 *
 * @pre Module must be initialized.
 * @post Module is deinitialized and resources are released.
 */
Pcd_StatusType Pcd_Ipw_Deinit(void);

#ifdef __cplusplus
}
#endif

#endif /* PCD_IPW_H */