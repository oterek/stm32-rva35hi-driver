/**
  ******************************************************************************
  * @file    stm32h7xx_hal.c
  * @author  MCD Application Team
  * @brief   HAL module driver.
  ******************************************************************************
  */

#include "stm32h7xx_hal.h"

__IO uint32_t uwTick;
uint32_t uwTickPrio   = (1UL << __NVIC_PRIO_BITS);
HAL_TickFreqTypeDef uwTickFreq = HAL_TICK_FREQ_DEFAULT;

/**
  * @brief  This function is called to increment  a global variable "uwTick"
  *         used as application time base.
  * @note   In the default implementation, this variable is incremented each 1ms
  *         in SysTick ISR.
  * @retval None
  */
__weak void HAL_IncTick(void)
{
  uwTick += uwTickFreq;
}

/**
  * @brief  Provides a tick value in millisecond.
  * @retval tick value
  */
__weak uint32_t HAL_GetTick(void)
{
  return uwTick;
}

/**
  * @brief  This function provides minimum delay (in milliseconds) based
  *         on variable incremented.
  * @param  Delay  specifies the delay time length, in milliseconds.
  * @retval None
  */
__weak void HAL_Delay(uint32_t Delay)
{
  uint32_t tickstart = HAL_GetTick();
  uint32_t wait = Delay;

  /* Add a freq to guarantee minimum wait */
  if (wait < HAL_MAX_DELAY)
  {
    wait += (uint32_t)(uwTickFreq);
  }

  while ((HAL_GetTick() - tickstart) < wait)
  {
  }
}

/**
  * @brief  This function configures the source of the time base.
  *         The time source is configured  to have 1ms time base with a dedicated
  *         Tick interrupt priority.
  * @param  TickPriority  Tick interrupt priority.
  * @retval HAL status
  */
__weak HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority)
{
  /* Configure the SysTick to have interrupt in 1ms time basis*/
  if (HAL_SYSTICK_Config(SystemCoreClock / (1000U / uwTickFreq)) > 0U)
  {
    return HAL_ERROR;
  }

  /* Configure the SysTick IRQ priority */
  if (TickPriority < (1UL << __NVIC_PRIO_BITS))
  {
    HAL_NVIC_SetPriority(SysTick_IRQn, TickPriority, 0U);
    uwTickPrio = TickPriority;
  }
  else
  {
    return HAL_ERROR;
  }

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
HAL_StatusTypeDef HAL_Init(void)
{
  /* Configure Flash prefetch and Instruction cache through ART accelerator */
#if (INSTRUCTION_CACHE_ENABLE != 0U)
  __HAL_FLASH_INSTRUCTION_CACHE_ENABLE();
#endif /* INSTRUCTION_CACHE_ENABLE */

#if (DATA_CACHE_ENABLE != 0U)
  __HAL_FLASH_DATA_CACHE_ENABLE();
#endif /* DATA_CACHE_ENABLE */

#if (PREFETCH_ENABLE != 0U)
  __HAL_FLASH_PREFETCH_BUFFER_ENABLE();
#endif /* PREFETCH_ENABLE */

  /* Set Interrupt Group Priority */
  HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  /* Use systick as time base source and configure 1ms tick (default clock after Reset is HSI) */
  HAL_InitTick(TICK_INT_PRIORITY);

  /* Init the low level hardware */
  HAL_MspInit();

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Initializes the MSP.
  * @retval None
  */
__weak void HAL_MspInit(void)
{
}
