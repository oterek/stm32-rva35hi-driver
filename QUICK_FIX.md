# Quick Fix Guide

## Problem
Getting compilation errors like:
```
error: unknown type name 'MDMA_HandleTypeDef'
```

## Solution
Replace your project's `stm32h7xx_hal_sram.h` file with the fixed version from this repository.

## Steps

### 1. Locate the File
In your STM32 project, find:
```
Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_sram.h
```

### 2. Backup Original (Optional)
```bash
cp Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_sram.h \
   Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_sram.h.backup
```

### 3. Replace with Fixed Version
Copy the fixed `stm32h7xx_hal_sram.h` from this repository to your project:
```bash
cp /path/to/this/repo/Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_sram.h \
   /path/to/your/project/Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_sram.h
```

### 4. Rebuild
Clean and rebuild your project:
- **STM32CubeIDE**: Project → Clean → Build
- **Command line**: `make clean && make all`

## What Changed?
The fix wraps MDMA-related code with conditional compilation:
```c
#if defined(HAL_MDMA_MODULE_ENABLED)
  MDMA_HandleTypeDef *hmdma;  // Only compiled when MDMA is enabled
#endif
```

This allows the SRAM driver to compile whether or not you use MDMA in your project.

## Need Help?
See [TECHNICAL_FIX.md](TECHNICAL_FIX.md) for detailed technical documentation.
