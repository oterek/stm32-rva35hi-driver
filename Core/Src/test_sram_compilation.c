/**
  ******************************************************************************
  * @file    test_sram_compilation.c
  * @brief   Test file to verify that SRAM HAL header compiles correctly
  ******************************************************************************
  */

#include "stm32h7xx_hal_conf.h"

/* This test file verifies that the SRAM HAL header can be compiled
   without errors related to MDMA_HandleTypeDef being undefined.
   
   The fix includes the MDMA HAL header in stm32h7xx_hal_sram.h
   before using MDMA_HandleTypeDef, which resolves the compilation error.
*/

int main(void)
{
  /* Test that we can declare SRAM handle without compilation errors */
  SRAM_HandleTypeDef hsram;
  
  /* Test that we can access the MDMA handle pointer member */
  hsram.hmdma = (MDMA_HandleTypeDef*)0;
  
  return 0;
}
