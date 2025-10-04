/**
  ******************************************************************************
  * @file    stm32h7xx_hal_conf.h
  * @brief   HAL configuration file example
  * @note    This is an EXAMPLE showing how to configure HAL modules.
  *          Copy relevant sections to your actual stm32h7xx_hal_conf.h
  ******************************************************************************
  */

/* This example shows two configurations:
 * 1. With MDMA enabled (if you use MDMA with SRAM)
 * 2. Without MDMA enabled (most common - the fix allows this to work)
 */

/* Configuration 1: WITH MDMA (if you need DMA with SRAM) */
#if 0  /* Set to 1 to use this configuration */
#define HAL_MDMA_MODULE_ENABLED   /* Enable MDMA module */
#define HAL_SRAM_MODULE_ENABLED   /* Enable SRAM module */
/* When both are enabled, you can use HAL_SRAM_Read_DMA() and HAL_SRAM_Write_DMA() */
#endif

/* Configuration 2: WITHOUT MDMA (works with the fix) */
#if 1  /* Set to 0 to disable this configuration */
/* #define HAL_MDMA_MODULE_ENABLED */  /* MDMA disabled or commented out */
#define HAL_SRAM_MODULE_ENABLED          /* SRAM enabled */
/* With the fix, SRAM module works without MDMA */
/* You can use HAL_SRAM_Read_8b/16b/32b() and HAL_SRAM_Write_8b/16b/32b() */
/* DMA functions are not available (HAL_SRAM_Read_DMA/Write_DMA are not compiled) */
#endif

/* Other common HAL modules you might enable */
#define HAL_MODULE_ENABLED
#define HAL_CORTEX_MODULE_ENABLED
#define HAL_DMA_MODULE_ENABLED
#define HAL_EXTI_MODULE_ENABLED
#define HAL_FLASH_MODULE_ENABLED
#define HAL_GPIO_MODULE_ENABLED
#define HAL_PWR_MODULE_ENABLED
#define HAL_RCC_MODULE_ENABLED

/* Include the appropriate header based on which modules are enabled */
#ifdef HAL_SRAM_MODULE_ENABLED
  #include "stm32h7xx_hal_sram.h"  /* This is the fixed header */
#endif

#ifdef HAL_MDMA_MODULE_ENABLED
  #include "stm32h7xx_hal_mdma.h"  /* Only include if MDMA is enabled */
#endif

/* Note: The order of includes matters!
 * If you enable MDMA, include stm32h7xx_hal_mdma.h BEFORE stm32h7xx_hal_sram.h
 * to ensure MDMA_HandleTypeDef is defined when SRAM header needs it.
 */
