#!/bin/bash

# STM32H7xx HAL Library Setup Script
# This script helps verify and guide the setup of required HAL library files

echo "============================================="
echo "STM32H755ZI Display Driver - HAL Setup Check"
echo "============================================="
echo ""

HAL_SRC_DIR="Drivers/STM32H7xx_HAL_Driver/Src"
HAL_INC_DIR="Drivers/STM32H7xx_HAL_Driver/Inc"
CMSIS_DEV_DIR="Drivers/CMSIS/Device/ST/STM32H7xx/Include"
CMSIS_CORE_DIR="Drivers/CMSIS/Include"

# Required HAL source files
HAL_SRC_FILES=(
    "stm32h7xx_hal_cortex.c"
    "stm32h7xx_hal_rcc.c"
    "stm32h7xx_hal_rcc_ex.c"
    "stm32h7xx_hal_flash.c"
    "stm32h7xx_hal_flash_ex.c"
    "stm32h7xx_hal_gpio.c"
    "stm32h7xx_hal_pwr.c"
    "stm32h7xx_hal_pwr_ex.c"
    "stm32h7xx_hal_dma.c"
    "stm32h7xx_hal_sram.c"
)

# Required HAL header files
HAL_INC_FILES=(
    "stm32h7xx_hal.h"
    "stm32h7xx_hal_def.h"
    "stm32h7xx_hal_cortex.h"
    "stm32h7xx_hal_rcc.h"
    "stm32h7xx_hal_rcc_ex.h"
    "stm32h7xx_hal_flash.h"
    "stm32h7xx_hal_flash_ex.h"
    "stm32h7xx_hal_gpio.h"
    "stm32h7xx_hal_pwr.h"
    "stm32h7xx_hal_pwr_ex.h"
    "stm32h7xx_hal_dma.h"
    "stm32h7xx_hal_dma_ex.h"
    "stm32h7xx_hal_sram.h"
    "stm32h7xx_ll_fmc.h"
)

# Required CMSIS device headers
CMSIS_DEV_FILES=(
    "stm32h7xx.h"
    "stm32h755xx.h"
    "system_stm32h7xx.h"
)

# Required CMSIS core headers
CMSIS_CORE_FILES=(
    "core_cm7.h"
    "cmsis_version.h"
    "cmsis_compiler.h"
    "cmsis_gcc.h"
    "mpu_armv7.h"
)

missing_files=0

echo "Checking HAL source files..."
for file in "${HAL_SRC_FILES[@]}"; do
    if [ ! -f "$HAL_SRC_DIR/$file" ]; then
        echo "  ❌ Missing: $HAL_SRC_DIR/$file"
        missing_files=$((missing_files + 1))
    else
        echo "  ✓ Found: $file"
    fi
done
echo ""

echo "Checking HAL header files..."
for file in "${HAL_INC_FILES[@]}"; do
    if [ ! -f "$HAL_INC_DIR/$file" ]; then
        echo "  ❌ Missing: $HAL_INC_DIR/$file"
        missing_files=$((missing_files + 1))
    else
        echo "  ✓ Found: $file"
    fi
done
echo ""

echo "Checking CMSIS device headers..."
for file in "${CMSIS_DEV_FILES[@]}"; do
    if [ ! -f "$CMSIS_DEV_DIR/$file" ]; then
        echo "  ❌ Missing: $CMSIS_DEV_DIR/$file"
        missing_files=$((missing_files + 1))
    else
        echo "  ✓ Found: $file"
    fi
done
echo ""

echo "Checking CMSIS core headers..."
for file in "${CMSIS_CORE_FILES[@]}"; do
    if [ ! -f "$CMSIS_CORE_DIR/$file" ]; then
        echo "  ❌ Missing: $CMSIS_CORE_DIR/$file"
        missing_files=$((missing_files + 1))
    else
        echo "  ✓ Found: $file"
    fi
done
echo ""

echo "============================================="
if [ $missing_files -eq 0 ]; then
    echo "✓ All required HAL and CMSIS files are present!"
    echo "You can now build the project with: make"
else
    echo "❌ Missing $missing_files required file(s)"
    echo ""
    echo "To obtain these files:"
    echo "1. Download STM32CubeH7 from:"
    echo "   https://www.st.com/en/embedded-software/stm32cubeh7.html"
    echo "2. Extract and copy the required files from:"
    echo "   - Drivers/STM32H7xx_HAL_Driver/Src/ → $HAL_SRC_DIR/"
    echo "   - Drivers/STM32H7xx_HAL_Driver/Inc/ → $HAL_INC_DIR/"
    echo "   - Drivers/CMSIS/Device/ST/STM32H7xx/Include/ → $CMSIS_DEV_DIR/"
    echo "   - Drivers/CMSIS/Include/ → $CMSIS_CORE_DIR/"
    echo ""
    echo "See HAL_SETUP.md for detailed instructions."
fi
echo "============================================="
