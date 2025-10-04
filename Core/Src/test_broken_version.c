/**
  ******************************************************************************
  * @file    test_broken_version.c
  * @brief   Test file that demonstrates the compilation error
  ******************************************************************************
  */

#include "stm32h7xx_hal_def.h"
#include "stm32h7xx_ll_fmc.h"
#include "stm32h7xx_hal_sram_broken.h"

/* This file will fail to compile because MDMA_HandleTypeDef is not defined */

int main(void)
{
  SRAM_HandleTypeDef_Broken hsram;
  return 0;
}
