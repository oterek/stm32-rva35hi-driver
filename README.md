# stm32-rva35hi-driver
Firmware for RVA35HI-NUC144A display on STM32H755ZI Nucleo-144

## STM32H7xx HAL SRAM Driver Compilation Fix

This repository contains a fix for a compilation error in the STM32H7xx HAL SRAM driver where `MDMA_HandleTypeDef` was used without including the required header file.

### Quick Fix

Add this line to `Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_sram.h`:

```c
#include "stm32h7xx_hal_mdma.h"
```

### Documentation

- [SUMMARY.md](SUMMARY.md) - Quick overview and how to apply the fix
- [FIX_DOCUMENTATION.md](FIX_DOCUMENTATION.md) - Detailed technical documentation

### Problem

The compilation error occurred because `stm32h7xx_hal_sram.h` uses `MDMA_HandleTypeDef` without including the header that defines it:

```
error: unknown type name 'MDMA_HandleTypeDef'
   75 |   MDMA_HandleTypeDef             *hmdma;
```

### Solution

The fix adds `#include "stm32h7xx_hal_mdma.h"` to the SRAM HAL header file, ensuring the MDMA types are defined before use.

### Verification

Test files are included to demonstrate:
- `Core/Src/test_sram_compilation.c` - Compiles successfully with the fix
- `Core/Src/test_broken_version.c` - Fails without the fix (demonstrates the original error)
