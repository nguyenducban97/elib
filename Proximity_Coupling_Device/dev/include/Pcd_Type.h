/**
 * @file Pcd_Type.h
 * @brief Type definitions for Proximity Coupling Device (PCD)
 * @author Ban Nguyen
 * @date 
 * @version 1.0
 */

#ifndef PCD_TYPE_H
#define PCD_TYPE_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
==================================================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
/*==================================================================================================
*                                           TYPEDEF
==================================================================================================*/

/** @brief PCD IPW status enumeration */
typedef enum {
    PCD_STATUS_OK = 0,      /**< Operation successful */
    PCD_STATUS_ERROR = 1,   /**< Operation failed */
    PCD_STATUS_TIMEOUT = 2,
} Pcd_StatusType;

/**
 * @defgroup PCD_Types PCD Type Definitions
 * @brief Type definitions for Proximity Coupling Device
 * @{
 */
typedef struct {
    uint8_t u8TxModReg;
    uint8_t u8RxModReg;
    bool bRxMulti;
    uint8_t u8ComIEnReg;
} Pcd_Type;

/** @} */

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define NULL_PTR (0x0)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* PCD_TYPE_H */