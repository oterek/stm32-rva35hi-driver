# stm32-rva35hi-driver
Firmware for RVA35HI-NUC144A display on STM32H755ZI Nucleo-144

## Overview
This project provides a complete driver implementation for the RVA35HI-NUC144A display (ILI9488 controller) on the STM32H755ZI Nucleo-144 development board.

## Hardware Configuration
- **MCU:** STM32H755ZITx (Dual-core Cortex-M7 + M4)
- **Display:** RVA35HI-NUC144A (320x480 pixels)
- **Controller:** ILI9488
- **Interface:** 8-bit parallel (8080-I type) via FMC

## Pin Configuration (FMC)
| Function | Pin | FMC Signal |
|----------|-----|------------|
| Chip Select | PC7 | FMC_NE1 |
| Read Enable | PD4 | FMC_NOE |
| Write Enable | PD5 | FMC_NWE |
| D/C Line | PE4 | FMC_A20 |
| Data D0 | PD14 | FMC_D0 |
| Data D1 | PD15 | FMC_D1 |
| Data D2 | PD0 | FMC_D2 |
| Data D3 | PD1 | FMC_D3 |
| Data D4 | PE7 | FMC_D4 |
| Data D5 | PE8 | FMC_D5 |
| Data D6 | PE9 | FMC_D6 |
| Data D7 | PE10 | FMC_D7 |

## Memory Mapping
- **Command Address:** `0x60000000` (A20=0)
- **Data Address:** `0x60100000` (A20=1)

## Features
- Complete ILI9488 initialization sequence
- RGB565 color format (16-bit)
- Basic graphics functions:
  - Fill screen
  - Draw pixel
  - Set address window
- Demo application cycling through RED, GREEN, and BLUE colors

## Building the Project

### Prerequisites
You need to have the STM32 HAL libraries installed. This project requires:
- ARM GCC toolchain (`arm-none-eabi-gcc`)
- STM32CubeH7 HAL library (v1.10.0 or later)

### Build Instructions
1. Ensure you have the STM32CubeH7 package installed
2. Copy the required HAL and CMSIS files to the Drivers directory
3. Run `make` to build the project

```bash
make clean
make
```

This will generate:
- `build/stm32h755zi-display.elf` - ELF executable
- `build/stm32h755zi-display.hex` - HEX file for flashing
- `build/stm32h755zi-display.bin` - Binary file

### Flashing
Use STM32CubeProgrammer or OpenOCD to flash the generated `.hex` or `.bin` file to the board.

## Project Structure
```
.
├── Core/
│   ├── Inc/              # Application headers
│   │   ├── ili9488.h     # ILI9488 driver header
│   │   ├── main.h        # Main application header
│   │   └── stm32h7xx_*.h # HAL configuration
│   └── Src/              # Application sources
│       ├── ili9488.c     # ILI9488 driver implementation
│       ├── main.c        # Main application
│       └── stm32h7xx_*.c # System and interrupt handlers
├── Drivers/              # STM32 HAL and CMSIS libraries
├── startup/              # Startup code
├── Makefile              # Build configuration
└── STM32H755ZITX_FLASH.ld # Linker script
```

## Usage
After flashing, the display will continuously cycle through three colors:
1. Red (1 second)
2. Green (1 second)
3. Blue (1 second)

## API Reference

### Initialization
```c
void ILI9488_Init(void);
```

### Graphics Functions
```c
void ILI9488_Fill_Screen(uint16_t color);
void ILI9488_Draw_Pixel(uint16_t x, uint16_t y, uint16_t color);
void ILI9488_Set_Address_Window(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
```

### Low-Level Functions
```c
void ILI9488_Write_Command(uint8_t command);
void ILI9488_Write_Data(uint8_t data);
void ILI9488_Write_Data_Multiple(uint8_t* data, int size);
```

## Color Definitions (RGB565)
- `COLOR_BLACK` - 0x0000
- `COLOR_WHITE` - 0xFFFF
- `COLOR_RED` - 0xF800
- `COLOR_GREEN` - 0x07E0
- `COLOR_BLUE` - 0x001F
- `COLOR_YELLOW` - 0xFFE0
- `COLOR_CYAN` - 0x07FF
- `COLOR_MAGENTA` - 0xF81F

## Notes
- The project uses FMC Bank 1 (NOR/PSRAM) to interface with the LCD
- The FMC_A20 line is used as the Data/Command selection line
- The display operates in 16-bit RGB565 color mode
- Display dimensions: 320x480 pixels

## License
This project is provided as-is for educational and development purposes.