# Building the STM32H755ZI Display Driver Project

This guide provides step-by-step instructions for building and flashing the firmware.

## Prerequisites

### Required Software
1. **ARM GCC Toolchain** (`arm-none-eabi-gcc`)
   - Download from: https://developer.arm.com/downloads/-/gnu-rm
   - Or install via package manager (Linux/Mac)

2. **STM32CubeH7 HAL Library**
   - Download from: https://www.st.com/en/embedded-software/stm32cubeh7.html
   - Version 1.10.0 or later recommended

3. **Build Tools**
   - `make` utility
   - Standard Unix tools (`bash`, etc.)

4. **Flashing Tools** (one of):
   - STM32CubeProgrammer (recommended)
   - OpenOCD
   - ST-Link utilities

### Optional Software
- **STM32CubeIDE**: Full IDE with integrated build and debug tools
- **STM32CubeMX**: For regenerating or modifying the peripheral configuration

## Step 1: Install ARM GCC Toolchain

### Linux (Ubuntu/Debian)
```bash
sudo apt-get update
sudo apt-get install gcc-arm-none-eabi
```

### macOS (Homebrew)
```bash
brew install --cask gcc-arm-embedded
```

### Windows
Download and install from: https://developer.arm.com/downloads/-/gnu-rm

Verify installation:
```bash
arm-none-eabi-gcc --version
```

## Step 2: Set Up HAL Library

### Quick Check
Run the setup check script to see what's missing:
```bash
./check_hal_setup.sh
```

### Option A: Manual Setup
1. Download STM32CubeH7 from ST's website
2. Extract the archive
3. Copy required files to this project:

```bash
# Set the path to your extracted STM32CubeH7
CUBE_PATH="/path/to/STM32Cube_FW_H7_V1.10.0"

# Copy HAL drivers
cp $CUBE_PATH/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.c Drivers/STM32H7xx_HAL_Driver/Src/
cp $CUBE_PATH/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.c Drivers/STM32H7xx_HAL_Driver/Src/
cp $CUBE_PATH/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.c Drivers/STM32H7xx_HAL_Driver/Src/
cp $CUBE_PATH/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.c Drivers/STM32H7xx_HAL_Driver/Src/
cp $CUBE_PATH/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.c Drivers/STM32H7xx_HAL_Driver/Src/
cp $CUBE_PATH/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.c Drivers/STM32H7xx_HAL_Driver/Src/
cp $CUBE_PATH/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.c Drivers/STM32H7xx_HAL_Driver/Src/
cp $CUBE_PATH/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.c Drivers/STM32H7xx_HAL_Driver/Src/
cp $CUBE_PATH/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.c Drivers/STM32H7xx_HAL_Driver/Src/
cp $CUBE_PATH/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sram.c Drivers/STM32H7xx_HAL_Driver/Src/

# Copy HAL headers
cp $CUBE_PATH/Drivers/STM32H7xx_HAL_Driver/Inc/*.h Drivers/STM32H7xx_HAL_Driver/Inc/

# Copy CMSIS files
cp $CUBE_PATH/Drivers/CMSIS/Device/ST/STM32H7xx/Include/*.h Drivers/CMSIS/Device/ST/STM32H7xx/Include/
cp $CUBE_PATH/Drivers/CMSIS/Include/*.h Drivers/CMSIS/Include/
```

### Option B: Use STM32CubeIDE
1. Open the project in STM32CubeIDE
2. The IDE will automatically download and configure the HAL library
3. Build directly from the IDE (Ctrl+B)

## Step 3: Build the Project

### Using Make (Command Line)
```bash
# Clean previous build
make clean

# Build the project
make

# Build with verbose output
make -j4 V=1
```

### Using STM32CubeIDE
1. Open the project: File → Open Projects from File System
2. Select the project directory
3. Build: Project → Build All (or press Ctrl+B)

### Build Output
Successful build will produce:
- `build/stm32h755zi-display.elf` - ELF executable with debug symbols
- `build/stm32h755zi-display.hex` - Intel HEX format (for flashing)
- `build/stm32h755zi-display.bin` - Raw binary format
- `build/stm32h755zi-display.map` - Memory map file

## Step 4: Flash the Firmware

### Option A: STM32CubeProgrammer (Recommended)
1. Connect the STM32H755ZI Nucleo board via USB
2. Open STM32CubeProgrammer
3. Connect to the board (ST-LINK interface)
4. Load the `.hex` or `.bin` file
5. Click "Download" to flash
6. Reset the board

### Option B: OpenOCD
```bash
# Using the hex file
openocd -f interface/stlink.cfg -f target/stm32h7x.cfg \
  -c "program build/stm32h755zi-display.hex verify reset exit"
```

### Option C: ST-Link Utility (Command Line)
```bash
st-flash write build/stm32h755zi-display.bin 0x08000000
```

### Option D: From STM32CubeIDE
1. Click the "Run" button (green arrow) or press F11
2. The IDE will automatically flash and start debugging

## Step 5: Verify Operation

After flashing and resetting the board:

1. **Power on** the board and display
2. The display should initialize (may take a few seconds)
3. The display will cycle through colors:
   - RED → (1 second)
   - GREEN → (1 second)
   - BLUE → (1 second)
   - Repeat

If the display shows colors cycling, the firmware is working correctly!

## Troubleshooting

### Build Errors

**Error: `stm32h7xx.h: No such file or directory`**
- Solution: HAL library files not installed. See Step 2.

**Error: `arm-none-eabi-gcc: command not found`**
- Solution: Install ARM GCC toolchain. See Step 1.

**Error: Undefined reference to HAL functions**
- Solution: Missing HAL source files. Run `./check_hal_setup.sh` to verify.

### Flashing Issues

**Cannot connect to target**
- Check USB cable connection
- Ensure ST-LINK drivers are installed
- Try a different USB port
- Update ST-LINK firmware using STM32CubeProgrammer

**Verification failed**
- Try erasing the chip first
- Flash the `.bin` file to address 0x08000000

### Display Issues

**Display stays blank**
- Check all connections between display and Nucleo board
- Verify FMC pins are correctly connected (see README.md)
- Check display power supply
- Verify D/C line connection (PE4 → A20)

**Wrong colors or garbage on display**
- Check data bus connections (D0-D7)
- Verify chip select (NE1) connection
- Check read/write enable signals (NOE, NWE)

**Display initializes but freezes**
- Check power supply stability
- Verify FMC timing parameters
- Ensure proper grounding

## Advanced Build Options

### Debug Build
```bash
make DEBUG=1
```

### Release Build (Optimized)
```bash
make DEBUG=0 OPT=-O2
```

### Clean Build
```bash
make clean
make
```

### Parallel Build
```bash
make -j4  # Use 4 parallel jobs
```

## Project Customization

### Changing Display Colors
Edit `Core/Src/main.c` and modify the main loop:
```c
while (1)
{
    ILI9488_Fill_Screen(COLOR_RED);
    HAL_Delay(1000);
    
    ILI9488_Fill_Screen(COLOR_GREEN);
    HAL_Delay(1000);
    
    ILI9488_Fill_Screen(COLOR_BLUE);
    HAL_Delay(1000);
}
```

### Adding Graphics Functions
Extend the ILI9488 driver in `Core/Src/ili9488.c` with additional functions like:
- Draw line
- Draw rectangle
- Draw circle
- Draw text

### Modifying FMC Configuration
1. Open `stm32h755zi-display.ioc` in STM32CubeMX
2. Modify FMC parameters under "Connectivity → FMC"
3. Regenerate code
4. Rebuild the project

## Support

For issues specific to this project:
- Check the README.md for pin configuration
- Review HAL_SETUP.md for library setup
- Run `./check_hal_setup.sh` to verify setup

For STM32 HAL and toolchain issues:
- ST Community: https://community.st.com
- STM32 Documentation: https://www.st.com/en/microcontrollers-microprocessors/stm32h755zi.html
