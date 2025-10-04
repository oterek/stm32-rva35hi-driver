# Contributing to STM32H755ZI Display Driver

Thank you for your interest in contributing to this project! This document provides guidelines for development and contributions.

## Development Setup

### Prerequisites
1. ARM GCC toolchain
2. STM32CubeH7 HAL library
3. Make utility
4. Git

See [BUILD.md](BUILD.md) for detailed setup instructions.

### Getting Started
1. Fork the repository
2. Clone your fork:
   ```bash
   git clone https://github.com/YOUR_USERNAME/stm32-rva35hi-driver.git
   cd stm32-rva35hi-driver
   ```
3. Set up HAL dependencies (see [HAL_SETUP.md](HAL_SETUP.md))
4. Build the project to verify setup:
   ```bash
   make clean
   make
   ```

## Project Structure

```
.
├── Core/
│   ├── Inc/              # Application headers
│   │   ├── ili9488.h     # ILI9488 driver API
│   │   ├── main.h        # Main application header
│   │   └── stm32h7xx_*.h # HAL configuration
│   └── Src/              # Application sources
│       ├── ili9488.c     # ILI9488 driver implementation
│       ├── main.c        # Main application logic
│       └── stm32h7xx_*.c # System initialization
├── Drivers/              # STM32 HAL and CMSIS (not in repo)
├── startup/              # Startup assembly code
├── Makefile              # Build configuration
├── STM32H755ZITX_FLASH.ld # Linker script
└── stm32h755zi-display.ioc # STM32CubeMX configuration
```

## Coding Standards

### C Code Style
- **Indentation**: 4 spaces (no tabs)
- **Line length**: Max 100 characters
- **Braces**: K&R style (opening brace on same line)
- **Naming**:
  - Functions: `ILI9488_Function_Name` (PascalCase with prefix)
  - Variables: `local_variable` (snake_case)
  - Constants: `COLOR_RED` (UPPER_CASE)
  - Macros: `LCD_CMD_ADDRESS` (UPPER_CASE)

### Documentation
- Add Doxygen-style comments for all public functions
- Include brief description and parameter documentation
- Example:
  ```c
  /**
    * @brief  Draws a single pixel
    * @param  x: X coordinate
    * @param  y: Y coordinate
    * @param  color: 16-bit RGB565 color
    * @retval None
    */
  void ILI9488_Draw_Pixel(uint16_t x, uint16_t y, uint16_t color)
  {
      // Implementation
  }
  ```

### Comments
- Use `/* */` for multi-line comments
- Use `//` for single-line comments
- Explain "why" not "what" when code is complex

## Adding New Features

### Display Driver (ili9488.c/h)
When adding new graphics functions:
1. Declare function in `Core/Inc/ili9488.h`
2. Implement in `Core/Src/ili9488.c`
3. Follow existing naming pattern: `ILI9488_FunctionName`
4. Add Doxygen comments
5. Test thoroughly on hardware

Example:
```c
// In ili9488.h
void ILI9488_Draw_Line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);

// In ili9488.c
/**
  * @brief  Draws a line between two points
  * @param  x1: Start X coordinate
  * @param  y1: Start Y coordinate
  * @param  x2: End X coordinate
  * @param  y2: End Y coordinate
  * @param  color: 16-bit RGB565 color
  * @retval None
  */
void ILI9488_Draw_Line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{
    // Implementation using Bresenham's algorithm
}
```

### Hardware Configuration
If modifying pin assignments or FMC configuration:
1. Update `stm32h755zi-display.ioc` using STM32CubeMX
2. Regenerate code if needed
3. Update pin documentation in README.md
4. Update `MX_GPIO_Init()` and `MX_FMC_Init()` in main.c

## Testing

### Hardware Testing
Test all changes on actual hardware:
1. Build and flash firmware
2. Verify basic functionality (color cycling)
3. Test new features thoroughly
4. Check for any visual artifacts or glitches
5. Test edge cases (e.g., drawing at screen boundaries)

### Build Testing
Ensure clean builds:
```bash
make clean
make
```

Check for warnings:
```bash
make 2>&1 | grep -i warning
```

## Submitting Changes

### Before Submitting
- [ ] Code follows project style guidelines
- [ ] All functions have proper documentation
- [ ] Changes tested on hardware
- [ ] Build completes without errors or warnings
- [ ] README.md updated if needed
- [ ] No debug code or commented-out sections

### Pull Request Process
1. Create a feature branch:
   ```bash
   git checkout -b feature/your-feature-name
   ```
2. Make your changes
3. Commit with clear messages:
   ```bash
   git commit -m "Add draw_line function to ILI9488 driver"
   ```
4. Push to your fork:
   ```bash
   git push origin feature/your-feature-name
   ```
5. Open a Pull Request with:
   - Clear description of changes
   - Hardware test results
   - Screenshots/photos if UI changes

### Commit Messages
- Use present tense: "Add feature" not "Added feature"
- Be descriptive but concise
- Reference issues when applicable: "Fix #123: Correct pixel addressing"

## Areas for Contribution

### High Priority
- Additional graphics primitives (lines, rectangles, circles)
- Text rendering support
- Image/bitmap display functions
- Performance optimizations (DMA for bulk transfers)

### Medium Priority
- Color space conversions (RGB888 to RGB565)
- Double buffering support
- Touch screen support (if display has touch)
- Advanced graphics (gradients, anti-aliasing)

### Documentation
- Additional examples in README
- Troubleshooting guide expansion
- Pin connection diagrams
- Performance benchmarks

## Resources

### STM32H7 Documentation
- [STM32H755 Reference Manual](https://www.st.com/resource/en/reference_manual/rm0399-stm32h745755-and-stm32h747757-advanced-armbased-32bit-mcus-stmicroelectronics.pdf)
- [STM32H755 Datasheet](https://www.st.com/resource/en/datasheet/stm32h755zi.pdf)
- [HAL User Manual](https://www.st.com/resource/en/user_manual/um2217-description-of-stm32h7-hal-and-lowlayer-drivers-stmicroelectronics.pdf)

### Display Documentation
- ILI9488 Datasheet (search online)
- FMC Peripheral Documentation (Chapter in Reference Manual)

### Development Tools
- [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)
- [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html)
- [STM32CubeProgrammer](https://www.st.com/en/development-tools/stm32cubeprog.html)

## Questions?

If you have questions about contributing:
1. Check existing issues and pull requests
2. Review documentation in README.md and BUILD.md
3. Open a new issue with the "question" label

Thank you for contributing!
