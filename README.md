# stm32-rva35hi-driver
Firmware for RVA35HI-NUC144A display on STM32H755ZI Nucleo-144

## Build Fix for MDMA_HandleTypeDef Errors

This repository includes a fixed version of `stm32h7xx_hal_sram.h` that resolves compilation errors related to `MDMA_HandleTypeDef` being undefined.

### Problem
The original STM32H7 HAL driver's `stm32h7xx_hal_sram.h` file uses `MDMA_HandleTypeDef` without proper conditional compilation guards. This causes build errors when the MDMA module is not enabled in the HAL configuration:

```
error: unknown type name 'MDMA_HandleTypeDef'
```

### Solution
The fixed header file wraps all MDMA-related code with `#if defined(HAL_MDMA_MODULE_ENABLED)` guards:

1. **SRAM Handle Structure**: The `hmdma` member is only included when MDMA module is enabled
2. **DMA Functions**: `HAL_SRAM_Read_DMA()`, `HAL_SRAM_Write_DMA()`, and callback functions are conditionally compiled
3. **Backward Compatibility**: The fix maintains full compatibility with projects that do enable MDMA

### Usage
Copy `Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_sram.h` to your STM32 project's HAL driver include directory, replacing the original file.

### Configuration
In your `stm32h7xx_hal_conf.h`:
- If you **use MDMA**: Ensure `HAL_MDMA_MODULE_ENABLED` is defined
- If you **don't use MDMA**: Leave it undefined or commented out

The SRAM driver will compile successfully either way.
