# STM32 HAL Library Setup

## Important Notice
This project requires the STM32CubeH7 HAL library to build successfully.

## Required HAL Source Files
The following HAL driver files need to be placed in `Drivers/STM32H7xx_HAL_Driver/Src/`:
- stm32h7xx_hal_cortex.c
- stm32h7xx_hal_rcc.c
- stm32h7xx_hal_rcc_ex.c
- stm32h7xx_hal_flash.c
- stm32h7xx_hal_flash_ex.c
- stm32h7xx_hal_gpio.c
- stm32h7xx_hal_pwr.c
- stm32h7xx_hal_pwr_ex.c
- stm32h7xx_hal_dma.c
- stm32h7xx_hal_sram.c

## Required HAL Header Files
The following header files need to be placed in `Drivers/STM32H7xx_HAL_Driver/Inc/`:
- stm32h7xx_hal_cortex.h
- stm32h7xx_hal_rcc.h
- stm32h7xx_hal_rcc_ex.h
- stm32h7xx_hal_flash.h
- stm32h7xx_hal_flash_ex.h
- stm32h7xx_hal_gpio.h
- stm32h7xx_hal_pwr.h
- stm32h7xx_hal_pwr_ex.h
- stm32h7xx_hal_dma.h
- stm32h7xx_hal_sram.h
- stm32h7xx_hal_def.h
- stm32h7xx_hal.h
- stm32h7xx_ll_fmc.h

## Required CMSIS Files
The following CMSIS files need to be placed in `Drivers/CMSIS/Device/ST/STM32H7xx/Include/`:
- stm32h7xx.h
- stm32h755xx.h
- system_stm32h7xx.h

The following CMSIS core files need to be placed in `Drivers/CMSIS/Include/`:
- core_cm7.h
- cmsis_version.h
- cmsis_compiler.h
- cmsis_gcc.h
- mpu_armv7.h

## How to Obtain These Files

### Option 1: Download STM32CubeH7
1. Download STM32CubeH7 from ST's website: https://www.st.com/en/embedded-software/stm32cubeh7.html
2. Extract the archive
3. Copy the required files from:
   - `Drivers/STM32H7xx_HAL_Driver/Src/` → This project's `Drivers/STM32H7xx_HAL_Driver/Src/`
   - `Drivers/STM32H7xx_HAL_Driver/Inc/` → This project's `Drivers/STM32H7xx_HAL_Driver/Inc/`
   - `Drivers/CMSIS/Device/ST/STM32H7xx/Include/` → This project's `Drivers/CMSIS/Device/ST/STM32H7xx/Include/`
   - `Drivers/CMSIS/Include/` → This project's `Drivers/CMSIS/Include/`

### Option 2: Use STM32CubeMX
1. Install STM32CubeMX
2. Create a new project for STM32H755ZI
3. Enable the FMC peripheral
4. Generate code
5. Copy the generated HAL files to this project

### Option 3: Use STM32CubeIDE
1. Open this project in STM32CubeIDE
2. The IDE will automatically download the required HAL library
3. The project should build successfully

## Build After Setup
Once all files are in place, run:
```bash
make clean
make
```

The project should now build without errors.
