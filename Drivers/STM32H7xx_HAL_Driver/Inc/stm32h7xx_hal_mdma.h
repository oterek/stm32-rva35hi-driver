/**
  ******************************************************************************
  * @file    stm32h7xx_hal_mdma.h
  * @author  MCD Application Team
  * @brief   Header file of MDMA HAL module.
  ******************************************************************************
  */

#ifndef STM32H7xx_HAL_MDMA_H
#define STM32H7xx_HAL_MDMA_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal_def.h"

/** @addtogroup STM32H7xx_HAL_Driver
  * @{
  */

/** @addtogroup MDMA
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/** @defgroup MDMA_Exported_Types MDMA Exported Types
  * @{
  */

/**
  * @brief  HAL MDMA State structures definition
  */
typedef enum
{
  HAL_MDMA_STATE_RESET             = 0x00U,  /*!< MDMA not yet initialized or disabled */
  HAL_MDMA_STATE_READY             = 0x01U,  /*!< MDMA initialized and ready for use   */
  HAL_MDMA_STATE_BUSY              = 0x02U,  /*!< MDMA process is ongoing              */
  HAL_MDMA_STATE_TIMEOUT           = 0x03U,  /*!< MDMA timeout state                   */
  HAL_MDMA_STATE_ERROR             = 0x04U,  /*!< MDMA error state                     */
  HAL_MDMA_STATE_ABORT             = 0x05U,  /*!< MDMA Abort state                     */

} HAL_MDMA_StateTypeDef;

/**
  * @brief  MDMA handle Structure definition
  */
typedef struct __MDMA_HandleTypeDef
{
  void                        *Instance;                        /*!< Register base address                  */

  void                        *Init;                            /*!< MDMA communication parameters          */

  HAL_LockTypeDef             Lock;                             /*!< MDMA locking object                    */

  __IO HAL_MDMA_StateTypeDef  State;                            /*!< MDMA transfer state                    */

  void                        *Parent;                          /*!< Parent object state                    */

  void (* XferCpltCallback)(struct __MDMA_HandleTypeDef *hmdma);       /*!< MDMA transfer complete callback        */

  void (* XferErrorCallback)(struct __MDMA_HandleTypeDef *hmdma);      /*!< MDMA transfer error callback           */

  void (* XferAbortCallback)(struct __MDMA_HandleTypeDef *hmdma);      /*!< MDMA transfer Abort callback           */

  __IO uint32_t               ErrorCode;                        /*!< MDMA Error code                        */

} MDMA_HandleTypeDef;

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @defgroup MDMA_Exported_Functions MDMA Exported Functions
  * @{
  */

HAL_StatusTypeDef HAL_MDMA_Init(MDMA_HandleTypeDef *hmdma);
HAL_StatusTypeDef HAL_MDMA_DeInit(MDMA_HandleTypeDef *hmdma);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32H7xx_HAL_MDMA_H */
