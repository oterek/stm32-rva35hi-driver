/**
  ******************************************************************************
  * @file           : ili9488.c
  * @brief          : ILI9488 LCD driver implementation
  ******************************************************************************
  */

#include "ili9488.h"

/* Pointers to FMC addresses for LCD communication */
#define LCD_CMD  (*((volatile uint8_t *)(LCD_CMD_ADDRESS)))
#define LCD_DATA (*((volatile uint8_t *)(LCD_DATA_ADDRESS)))

/**
  * @brief  Writes a command to the LCD
  * @param  command: Command byte to send
  * @retval None
  */
void ILI9488_Write_Command(uint8_t command)
{
    LCD_CMD = command;
}

/**
  * @brief  Writes a single byte of data to the LCD
  * @param  data: Data byte to send
  * @retval None
  */
void ILI9488_Write_Data(uint8_t data)
{
    LCD_DATA = data;
}

/**
  * @brief  Writes multiple bytes of data to the LCD
  * @param  data: Pointer to data buffer
  * @param  size: Number of bytes to send
  * @retval None
  */
void ILI9488_Write_Data_Multiple(uint8_t* data, int size)
{
    for(int i = 0; i < size; i++)
    {
        LCD_DATA = data[i];
    }
}

/**
  * @brief  Initializes the ILI9488 LCD controller
  * @retval None
  */
void ILI9488_Init(void)
{
    /* Small delay after power-up */
    HAL_Delay(120);
    
    /* Software Reset */
    ILI9488_Write_Command(ILI9488_CMD_SWRESET);
    HAL_Delay(120);
    
    /* Exit Sleep Mode */
    ILI9488_Write_Command(ILI9488_CMD_SLPOUT);
    HAL_Delay(120);
    
    /* Positive Gamma Control */
    ILI9488_Write_Command(ILI9488_CMD_PGAMCTRL);
    ILI9488_Write_Data(0x00);
    ILI9488_Write_Data(0x03);
    ILI9488_Write_Data(0x09);
    ILI9488_Write_Data(0x08);
    ILI9488_Write_Data(0x16);
    ILI9488_Write_Data(0x0A);
    ILI9488_Write_Data(0x3F);
    ILI9488_Write_Data(0x78);
    ILI9488_Write_Data(0x4C);
    ILI9488_Write_Data(0x09);
    ILI9488_Write_Data(0x0A);
    ILI9488_Write_Data(0x08);
    ILI9488_Write_Data(0x16);
    ILI9488_Write_Data(0x1A);
    ILI9488_Write_Data(0x0F);
    
    /* Negative Gamma Control */
    ILI9488_Write_Command(ILI9488_CMD_NGAMCTRL);
    ILI9488_Write_Data(0x00);
    ILI9488_Write_Data(0x16);
    ILI9488_Write_Data(0x19);
    ILI9488_Write_Data(0x03);
    ILI9488_Write_Data(0x0F);
    ILI9488_Write_Data(0x05);
    ILI9488_Write_Data(0x32);
    ILI9488_Write_Data(0x45);
    ILI9488_Write_Data(0x46);
    ILI9488_Write_Data(0x04);
    ILI9488_Write_Data(0x0E);
    ILI9488_Write_Data(0x0D);
    ILI9488_Write_Data(0x35);
    ILI9488_Write_Data(0x37);
    ILI9488_Write_Data(0x0F);
    
    /* Power Control 1 */
    ILI9488_Write_Command(ILI9488_CMD_PWCTR1);
    ILI9488_Write_Data(0x17);
    ILI9488_Write_Data(0x15);
    
    /* Power Control 2 */
    ILI9488_Write_Command(ILI9488_CMD_PWCTR2);
    ILI9488_Write_Data(0x41);
    
    /* VCOM Control */
    ILI9488_Write_Command(ILI9488_CMD_VMCTR1);
    ILI9488_Write_Data(0x00);
    ILI9488_Write_Data(0x12);
    ILI9488_Write_Data(0x80);
    
    /* Memory Access Control */
    ILI9488_Write_Command(ILI9488_CMD_MADCTL);
    ILI9488_Write_Data(0x48); /* MY=0, MX=1, MV=0, ML=0, BGR=1, MH=0 */
    
    /* Interface Pixel Format - 16 bits/pixel (RGB565) */
    ILI9488_Write_Command(ILI9488_CMD_PIXFMT);
    ILI9488_Write_Data(0x55); /* 16-bit color */
    
    /* Frame Rate Control */
    ILI9488_Write_Command(ILI9488_CMD_FRMCTR1);
    ILI9488_Write_Data(0xA0);
    
    /* Display Inversion Control */
    ILI9488_Write_Command(ILI9488_CMD_INVCTR);
    ILI9488_Write_Data(0x02);
    
    /* Display Function Control */
    ILI9488_Write_Command(ILI9488_CMD_DFUNCTR);
    ILI9488_Write_Data(0x02);
    ILI9488_Write_Data(0x02);
    
    /* Set Image Function */
    ILI9488_Write_Command(0xE9);
    ILI9488_Write_Data(0x00);
    
    /* Adjust Control 3 */
    ILI9488_Write_Command(ILI9488_CMD_ADJCTR3);
    ILI9488_Write_Data(0xA9);
    ILI9488_Write_Data(0x51);
    ILI9488_Write_Data(0x2C);
    ILI9488_Write_Data(0x82);
    
    /* Display ON */
    ILI9488_Write_Command(ILI9488_CMD_DISPON);
    HAL_Delay(120);
}

/**
  * @brief  Sets the address window for drawing operations
  * @param  x1: Start X coordinate
  * @param  y1: Start Y coordinate
  * @param  x2: End X coordinate
  * @param  y2: End Y coordinate
  * @retval None
  */
void ILI9488_Set_Address_Window(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
    /* Column Address Set */
    ILI9488_Write_Command(ILI9488_CMD_CASET);
    ILI9488_Write_Data((x1 >> 8) & 0xFF);
    ILI9488_Write_Data(x1 & 0xFF);
    ILI9488_Write_Data((x2 >> 8) & 0xFF);
    ILI9488_Write_Data(x2 & 0xFF);
    
    /* Page Address Set */
    ILI9488_Write_Command(ILI9488_CMD_PASET);
    ILI9488_Write_Data((y1 >> 8) & 0xFF);
    ILI9488_Write_Data(y1 & 0xFF);
    ILI9488_Write_Data((y2 >> 8) & 0xFF);
    ILI9488_Write_Data(y2 & 0xFF);
    
    /* Memory Write */
    ILI9488_Write_Command(ILI9488_CMD_RAMWR);
}

/**
  * @brief  Draws a single pixel
  * @param  x: X coordinate
  * @param  y: Y coordinate
  * @param  color: 16-bit RGB565 color
  * @retval None
  */
void ILI9488_Draw_Pixel(uint16_t x, uint16_t y, uint16_t color)
{
    if((x >= ILI9488_WIDTH) || (y >= ILI9488_HEIGHT))
        return;
    
    ILI9488_Set_Address_Window(x, y, x, y);
    
    /* Write 16-bit color in two 8-bit transfers */
    ILI9488_Write_Data((color >> 8) & 0xFF);
    ILI9488_Write_Data(color & 0xFF);
}

/**
  * @brief  Fills the entire screen with a color
  * @param  color: 16-bit RGB565 color
  * @retval None
  */
void ILI9488_Fill_Screen(uint16_t color)
{
    uint32_t i;
    uint32_t pixel_count = (uint32_t)ILI9488_WIDTH * (uint32_t)ILI9488_HEIGHT;
    
    ILI9488_Set_Address_Window(0, 0, ILI9488_WIDTH - 1, ILI9488_HEIGHT - 1);
    
    uint8_t color_high = (color >> 8) & 0xFF;
    uint8_t color_low = color & 0xFF;
    
    for(i = 0; i < pixel_count; i++)
    {
        ILI9488_Write_Data(color_high);
        ILI9488_Write_Data(color_low);
    }
}
