/**
  ******************************************************************************
  * @file    stm32h7xx_hal_def.h
  * @author  MCD Application Team
  * @brief   This file contains HAL common defines, enumeration, macros and 
  *          structures definitions.
  ******************************************************************************
  */

#ifndef STM32H7xx_HAL_DEF_H
#define STM32H7xx_HAL_DEF_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx.h"
#include "Legacy/stm32_hal_legacy.h"
#include <stddef.h>

/* Exported types ------------------------------------------------------------*/

/**
  * @brief  HAL Status structures definition
  */
typedef enum
{
  HAL_OK       = 0x00U,
  HAL_ERROR    = 0x01U,
  HAL_BUSY     = 0x02U,
  HAL_TIMEOUT  = 0x03U
} HAL_StatusTypeDef;

/**
  * @brief  HAL Lock structures definition
  */
typedef enum
{
  HAL_UNLOCKED = 0x00U,
  HAL_LOCKED   = 0x01U
} HAL_LockTypeDef;

#ifdef __cplusplus
}
#endif

#endif /* STM32H7xx_HAL_DEF_H */
