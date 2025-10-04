/**
  ******************************************************************************
  * @file    stm32h7xx.h
  * @author  MCD Application Team
  * @brief   CMSIS STM32H7xx Device Peripheral Access Layer Header File.
  ******************************************************************************
  */

#ifndef STM32H7xx_H
#define STM32H7xx_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

/** @addtogroup Library_configuration_section
  * @{
  */

/**
  * @brief STM32 Family
  */
#if !defined (STM32H7)
#define STM32H7
#endif /* STM32H7 */

/* Uncomment the line below according to the target STM32H7 device used in your
   application
  */

#if !defined (STM32H743xx) && !defined (STM32H753xx) && !defined (STM32H750xx) && !defined (STM32H742xx) && \
    !defined (STM32H745xx) && !defined (STM32H755xx) && !defined (STM32H747xx) && !defined (STM32H757xx) && \
    !defined (STM32H7A3xx) && !defined (STM32H7A3xxQ) && !defined (STM32H7B3xx) && !defined (STM32H7B3xxQ) && !defined (STM32H7B0xx)  && !defined (STM32H7B0xxQ)
  /* #define STM32H742xx */   /*!< STM32H742VI, STM32H742ZI, STM32H742AI, STM32H742II, STM32H742BI, STM32H742XI Devices */
  /* #define STM32H743xx */   /*!< STM32H743VI, STM32H743ZI, STM32H743AI, STM32H743II, STM32H743BI, STM32H743XI Devices */
  /* #define STM32H753xx */   /*!< STM32H753VI, STM32H753ZI, STM32H753AI, STM32H753II, STM32H753BI, STM32H753XI Devices */
  /* #define STM32H750xx */   /*!< STM32H750V, STM32H750Z, STM32H750X Devices */
  /* #define STM32H747xx */   /*!< STM32H747ZI, STM32H747AI, STM32H747II, STM32H747BI, STM32H747XI Devices */
  /* #define STM32H757xx */   /*!< STM32H757ZI, STM32H757AI, STM32H757II, STM32H757BI, STM32H757XI Devices */
  /* #define STM32H745xx */   /*!< STM32H745ZI, STM32H745II, STM32H745BI, STM32H745XI Devices */
  #define STM32H755xx       /*!< STM32H755ZI, STM32H755II, STM32H755BI, STM32H755XI Devices */
  /* #define STM32H7A3xx */   /*!< STM32H7A3xx Devices */
  /* #define STM32H7A3xxQ */  /*!< STM32H7A3xxQ Devices */
  /* #define STM32H7B3xx */   /*!< STM32H7B3xx Devices */
  /* #define STM32H7B3xxQ */  /*!< STM32H7B3xxQ Devices */
  /* #define STM32H7B0xx  */  /*!< STM32H7B0xx Devices */
  /* #define STM32H7B0xxQ */  /*!< STM32H7B0xxQ Devices */
#endif

/* Tip: To avoid modifying this file each time you need to switch between these
        devices, you can define the device in your toolchain compiler preprocessor.
  */

#if !defined  (USE_HAL_DRIVER)
/**
 * @brief Comment the line below if you will not use the peripherals drivers.
   In this case, these drivers will not be included and the application code will
   be based on direct access to peripherals registers
   */
  /*#define USE_HAL_DRIVER */
#endif /* USE_HAL_DRIVER */

/**
  * @brief CMSIS Device version number
  */
#define __STM32H7_CMSIS_VERSION_MAIN   (0x01U) /*!< [31:24] main version */
#define __STM32H7_CMSIS_VERSION_SUB1   (0x0AU) /*!< [23:16] sub1 version */
#define __STM32H7_CMSIS_VERSION_SUB2   (0x00U) /*!< [15:8]  sub2 version */
#define __STM32H7_CMSIS_VERSION_RC     (0x00U) /*!< [7:0]  release candidate */
#define __STM32H7_CMSIS_VERSION        ((__STM32H7_CMSIS_VERSION_MAIN << 24U)\
                                       |(__STM32H7_CMSIS_VERSION_SUB1 << 16U)\
                                       |(__STM32H7_CMSIS_VERSION_SUB2 << 8U )\
                                       |(__STM32H7_CMSIS_VERSION_RC))

/**
  * @}
  */

/** @addtogroup Device_Included
  * @{
  */

#include <stdint.h>

typedef int32_t  int32_t;
typedef uint32_t uint32_t;
typedef int16_t  int16_t;
typedef uint16_t uint16_t;
typedef int8_t   int8_t;
typedef uint8_t  uint8_t;

#define __IO volatile
#define __I  volatile const
#define __O  volatile

/**
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* STM32H7xx_H */
