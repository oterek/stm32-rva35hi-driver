# STM32H7xx HAL SRAM Driver Compilation Fix

## Problem

When compiling STM32H7xx HAL projects that use the SRAM driver, the following compilation error occurs:

```
../../Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_sram.h:75:3: error: unknown type name 'MDMA_HandleTypeDef'
   75 |   MDMA_HandleTypeDef             *hmdma;      /*!< Pointer DMA handler                          */
      |   ^~~~~~~~~~~~~~~~~~
```

This error occurs because the SRAM HAL header file (`stm32h7xx_hal_sram.h`) uses the `MDMA_HandleTypeDef` type without including the MDMA HAL header file that defines it.

## Root Cause

The `stm32h7xx_hal_sram.h` header file declares a member of type `MDMA_HandleTypeDef*` in the `SRAM_HandleTypeDef` structure (line 75) and uses it in function declarations (lines 174-175), but it doesn't include the header file where `MDMA_HandleTypeDef` is defined (`stm32h7xx_hal_mdma.h`).

## Solution

The fix is to add the following include statement to `stm32h7xx_hal_sram.h`:

```c
#include "stm32h7xx_hal_mdma.h"
```

This include should be added after the other HAL includes, around line 28 in the header file.

## Files Modified

- `Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_sram.h`
  - Added `#include "stm32h7xx_hal_mdma.h"` to ensure `MDMA_HandleTypeDef` is defined before use

## Verification

The fix has been verified by:
1. Creating the necessary header file structure
2. Including the MDMA header in the SRAM header file
3. Compiling a test file that uses the SRAM HAL driver

The compilation now succeeds without errors related to undefined `MDMA_HandleTypeDef`.

## Impact

This is a minimal change that only affects the header file dependencies. It does not change any functionality or API, only ensures that types are properly defined before they are used.

## Related Issues

This fix addresses compilation errors similar to those reported in STM32CubeH7 when using:
- STM32H755xx devices
- SRAM HAL driver with MDMA support
- Projects that enable both SRAM and MDMA modules
