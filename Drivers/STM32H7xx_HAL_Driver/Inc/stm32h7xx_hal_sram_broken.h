/**
  ******************************************************************************
  * @file    stm32h7xx_hal_sram_broken.h
  * @brief   BROKEN version - demonstrates the compilation error
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32H7xx_HAL_SRAM_BROKEN_H
#define STM32H7xx_HAL_SRAM_BROKEN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal_def.h"
#include "stm32h7xx_ll_fmc.h"
/* NOTE: Missing include for stm32h7xx_hal_mdma.h - this causes the error! */

/* Exported typedef ----------------------------------------------------------*/

typedef enum
{
  HAL_SRAM_STATE_RESET     = 0x00U,
  HAL_SRAM_STATE_READY     = 0x01U,
  HAL_SRAM_STATE_BUSY      = 0x02U,
  HAL_SRAM_STATE_ERROR     = 0x03U,
  HAL_SRAM_STATE_PROTECTED = 0x04U
} HAL_SRAM_StateTypeDef;

typedef struct
{
  FMC_NORSRAM_TypeDef           *Instance;
  FMC_NORSRAM_ExtendedTypeDef   *Extended;
  FMC_NORSRAM_InitTypeDef       Init;
  HAL_LockTypeDef               Lock;
  __IO HAL_SRAM_StateTypeDef    State;
  
  /* This line will cause a compilation error because MDMA_HandleTypeDef is not defined */
  MDMA_HandleTypeDef             *hmdma;      /*!< Pointer DMA handler */
  
} SRAM_HandleTypeDef_Broken;

/* These function declarations will also cause errors */
void HAL_SRAM_DMA_XferCpltCallback_Broken(MDMA_HandleTypeDef *hmdma);
void HAL_SRAM_DMA_XferErrorCallback_Broken(MDMA_HandleTypeDef *hmdma);

#ifdef __cplusplus
}
#endif

#endif /* STM32H7xx_HAL_SRAM_BROKEN_H */
