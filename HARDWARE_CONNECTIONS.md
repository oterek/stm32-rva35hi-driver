# Hardware Connection Diagram

## STM32H755ZI Nucleo-144 to RVA35HI-NUC144A Display

```
┌─────────────────────────────────────────────────────────────────────┐
│                    STM32H755ZI Nucleo-144                           │
│                                                                     │
│  ┌──────────────────────────────────────────────────────────┐     │
│  │                    STM32H755ZITx                         │     │
│  │                  (Cortex-M7 @ 400MHz)                    │     │
│  │                                                          │     │
│  │  ┌────────────────────────────────────────────┐         │     │
│  │  │  FMC (Flexible Memory Controller)          │         │     │
│  │  │  Bank 1: NOR/PSRAM                         │         │     │
│  │  │  Base Address: 0x60000000                  │         │     │
│  │  └────────────────────────────────────────────┘         │     │
│  │                                                          │     │
│  │  PC7  ───────────── FMC_NE1   (Chip Select)             │     │
│  │  PD4  ───────────── FMC_NOE   (Read Enable)             │     │
│  │  PD5  ───────────── FMC_NWE   (Write Enable)            │     │
│  │  PE4  ───────────── FMC_A20   (D/C Selection)           │     │
│  │                                                          │     │
│  │  PD14 ───────────── FMC_D0    (Data Bit 0)              │     │
│  │  PD15 ───────────── FMC_D1    (Data Bit 1)              │     │
│  │  PD0  ───────────── FMC_D2    (Data Bit 2)              │     │
│  │  PD1  ───────────── FMC_D3    (Data Bit 3)              │     │
│  │  PE7  ───────────── FMC_D4    (Data Bit 4)              │     │
│  │  PE8  ───────────── FMC_D5    (Data Bit 5)              │     │
│  │  PE9  ───────────── FMC_D6    (Data Bit 6)              │     │
│  │  PE10 ───────────── FMC_D7    (Data Bit 7)              │     │
│  │                                                          │     │
│  └──────────────────────────────────────────────────────────┘     │
│                                                                     │
└─────────────────────────────────────────────────────────────────────┘
                                   │
                                   │ 8-bit Parallel Interface
                                   │ (8080-I Type)
                                   ▼
┌─────────────────────────────────────────────────────────────────────┐
│                    RVA35HI-NUC144A Display                          │
│                                                                     │
│  ┌──────────────────────────────────────────────────────────┐     │
│  │                    ILI9488 Controller                    │     │
│  │                  (320x480 RGB Display)                   │     │
│  │                                                          │     │
│  │  CS  ◄────────────────── Chip Select                    │     │
│  │  RD  ◄────────────────── Read Strobe                    │     │
│  │  WR  ◄────────────────── Write Strobe                   │     │
│  │  D/C ◄────────────────── Data/Command Select            │     │
│  │                                                          │     │
│  │  D0  ◄────────────────── Data Bus [0]                   │     │
│  │  D1  ◄────────────────── Data Bus [1]                   │     │
│  │  D2  ◄────────────────── Data Bus [2]                   │     │
│  │  D3  ◄────────────────── Data Bus [3]                   │     │
│  │  D4  ◄────────────────── Data Bus [4]                   │     │
│  │  D5  ◄────────────────── Data Bus [5]                   │     │
│  │  D6  ◄────────────────── Data Bus [6]                   │     │
│  │  D7  ◄────────────────── Data Bus [7]                   │     │
│  │                                                          │     │
│  └──────────────────────────────────────────────────────────┘     │
│                                                                     │
│  ┌──────────────────────────────────────────────────────────┐     │
│  │                 LCD Panel (320x480)                      │     │
│  │                                                          │     │
│  │  ┌──────────────────────────────────────────────┐       │     │
│  │  │                                              │       │     │
│  │  │         RGB565 Color Display                 │       │     │
│  │  │         (16-bit per pixel)                   │       │     │
│  │  │                                              │       │     │
│  │  └──────────────────────────────────────────────┘       │     │
│  └──────────────────────────────────────────────────────────┘     │
│                                                                     │
└─────────────────────────────────────────────────────────────────────┘
```

## Memory Mapping

```
FMC Bank 1 Address Space: 0x60000000 - 0x6FFFFFFF

┌─────────────────────────────────────────────────┐
│  0x60000000  │  Command Address (A20=0)        │ ◄─── LCD_CMD_ADDRESS
├─────────────────────────────────────────────────┤
│              │                                  │
│     ...      │       (unused address space)     │
│              │                                  │
├─────────────────────────────────────────────────┤
│  0x60100000  │  Data Address (A20=1)           │ ◄─── LCD_DATA_ADDRESS
│              │  (Bit 20 set = 2^20 = 0x100000) │
└─────────────────────────────────────────────────┘

A20 Line Function:
- When A20 = 0: Write to command register
- When A20 = 1: Write to data register

This is implemented in hardware through FMC address decoding.
```

## Signal Flow

### Writing a Command
```
CPU → FMC → [Address: 0x60000000] → D/C=0 (Command) → ILI9488
         → [Data Bus D0-D7] → Command Byte → ILI9488
         → [WR Strobe] → Latches Command
```

### Writing Data
```
CPU → FMC → [Address: 0x60100000] → D/C=1 (Data) → ILI9488
         → [Data Bus D0-D7] → Data Byte → ILI9488
         → [WR Strobe] → Latches Data
```

### Pixel Write Sequence (RGB565)
```
For each pixel (16-bit color):
  1. Set address window (CASET, PASET commands)
  2. Issue RAMWR command
  3. Write high byte of color (bits 15-8)
  4. Write low byte of color (bits 7-0)
  5. Repeat for each pixel
```

## Color Format: RGB565

```
16-bit Color Value (RGB565)
┌──────┬──────────┬──────┐
│  R5  │    G6    │  B5  │
└──────┴──────────┴──────┘
 15-11    10-5      4-0

Red:   5 bits (0-31) → bits 15-11
Green: 6 bits (0-63) → bits 10-5
Blue:  5 bits (0-31) → bits 4-0

Example Colors:
- RED:   0xF800 = 0b1111100000000000
- GREEN: 0x07E0 = 0b0000011111100000
- BLUE:  0x001F = 0b0000000000011111
- WHITE: 0xFFFF = 0b1111111111111111
```

## Timing Characteristics

The FMC is configured with the following timing parameters:

- **Address Setup Time**: 15 FMC_CLK cycles
- **Data Setup Time**: 255 FMC_CLK cycles
- **Bus Turnaround**: 15 FMC_CLK cycles

These values provide safe margins for the ILI9488 controller timing requirements.

## Power Connections (Not Shown Above)

Additional connections required (typically on display module):
- VCC → 3.3V or 5V (check display specifications)
- GND → Ground
- LED/BL → Backlight power (may need current limiting)
- RESET → MCU reset or GPIO (if available)

**Note**: Power connections depend on your specific display module configuration.
