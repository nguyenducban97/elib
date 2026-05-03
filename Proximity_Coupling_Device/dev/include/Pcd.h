/**
 * @file Pcd.h
 * @brief Brief description of the Proximity Coupling Device module.
 * 
 * Detailed description of the module's purpose and functionality.
 * 
 * @author Author Name
 * @date YYYY-MM-DD
 * @version 1.0.0
 * 
 * @copyright Copyright (c) YYYY Company Name. All rights reserved.
 */

#ifndef PCD_H
#define PCD_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
==================================================================================================*/
#include "Pcd_Cfg.h"

/**
 * @defgroup PCD Proximity Coupling Device
 * @{
 */
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define PCD_DRIVER_UNINIT (0x0U)
#define PCD_DRIVER_READY  (0x1U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                         GLOBAL VARIABLES
==================================================================================================*/
#ifndef PCD_DRIVER_STATUS_VAR
#define PCD_DRIVER_STATUS_VAR
static uint8_t u8Pcd_Driver_Status = PCD_DRIVER_UNINIT;
#endif /*PCD_DRIVER_STATUS_VAR*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


/**
 * @brief Function description.
 * 
 * Detailed description of what the function does.
 * 
 * @param[in] param1 Description of input parameter 1.
 * @param[out] param2 Description of output parameter.
 * 
 * @return Return value description.
 * 
 * @retval void
 */
void PCD_Init(const Pcd_Type* pConfig);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* PCD_H */