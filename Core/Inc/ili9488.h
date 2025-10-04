/**
  ******************************************************************************
  * @file           : ili9488.h
  * @brief          : Header for ili9488.c file.
  *                   This file contains the common defines and functions for
  *                   the ILI9488 LCD driver.
  ******************************************************************************
  */

#ifndef __ILI9488_H
#define __ILI9488_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32h7xx_hal.h"

/* LCD FMC Addresses */
#define LCD_CMD_ADDRESS   0x60000000  /* Command address (A20=0) */
#define LCD_DATA_ADDRESS  0x60100000  /* Data address (A20=1, bit 20 set) */

/* LCD dimensions */
#define ILI9488_WIDTH  320
#define ILI9488_HEIGHT 480

/* ILI9488 Commands */
#define ILI9488_CMD_NOP                     0x00
#define ILI9488_CMD_SWRESET                 0x01
#define ILI9488_CMD_SLPIN                   0x10
#define ILI9488_CMD_SLPOUT                  0x11
#define ILI9488_CMD_INVOFF                  0x20
#define ILI9488_CMD_INVON                   0x21
#define ILI9488_CMD_DISPOFF                 0x28
#define ILI9488_CMD_DISPON                  0x29
#define ILI9488_CMD_CASET                   0x2A
#define ILI9488_CMD_PASET                   0x2B
#define ILI9488_CMD_RAMWR                   0x2C
#define ILI9488_CMD_RAMRD                   0x2E
#define ILI9488_CMD_MADCTL                  0x36
#define ILI9488_CMD_PIXFMT                  0x3A
#define ILI9488_CMD_FRMCTR1                 0xB1
#define ILI9488_CMD_INVCTR                  0xB4
#define ILI9488_CMD_DFUNCTR                 0xB6
#define ILI9488_CMD_PWCTR1                  0xC0
#define ILI9488_CMD_PWCTR2                  0xC1
#define ILI9488_CMD_VMCTR1                  0xC5
#define ILI9488_CMD_PGAMCTRL                0xE0
#define ILI9488_CMD_NGAMCTRL                0xE1
#define ILI9488_CMD_ADJCTR3                 0xF7

/* RGB565 Color definitions */
#define COLOR_BLACK   0x0000
#define COLOR_WHITE   0xFFFF
#define COLOR_RED     0xF800
#define COLOR_GREEN   0x07E0
#define COLOR_BLUE    0x001F
#define COLOR_YELLOW  0xFFE0
#define COLOR_CYAN    0x07FF
#define COLOR_MAGENTA 0xF81F

/* Function Prototypes */
void ILI9488_Write_Command(uint8_t command);
void ILI9488_Write_Data(uint8_t data);
void ILI9488_Write_Data_Multiple(uint8_t* data, int size);
void ILI9488_Init(void);
void ILI9488_Set_Address_Window(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void ILI9488_Draw_Pixel(uint16_t x, uint16_t y, uint16_t color);
void ILI9488_Fill_Screen(uint16_t color);

#ifdef __cplusplus
}
#endif

#endif /* __ILI9488_H */
