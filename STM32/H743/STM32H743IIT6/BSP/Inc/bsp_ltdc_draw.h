#ifndef __BSP_LTDC_DRAW_H
#define __BSP_LTDC_DRAW_H

#include "bsp_ltdc_driver.h"


// 定义RGB565颜色编码宏
#define RGB565(r, g, b) (((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3))

// 颜色常量定义
#define LCD_BLUE           RGB565(0, 0, 255)       // 纯蓝色
#define LCD_GREEN          RGB565(0, 255, 0)       // 纯绿色
#define LCD_RED            RGB565(255, 0, 0)       // 纯红色
#define LCD_CYAN           RGB565(0, 255, 255)     // 青色（绿+蓝）
#define LCD_MAGENTA        RGB565(255, 0, 255)     // 洋红色（红+蓝）
#define LCD_YELLOW         RGB565(255, 255, 0)     // 黄色（红+绿）
#define LCD_LIGHTBLUE      RGB565(128, 128, 255)   // 亮蓝色
#define LCD_LIGHTGREEN     RGB565(128, 255, 128)   // 亮绿色
#define LCD_LIGHTRED       RGB565(255, 128, 128)   // 亮红色
#define LCD_LIGHTCYAN      RGB565(128, 255, 255)   // 亮青色
#define LCD_LIGHTMAGENTA   RGB565(255, 128, 255)   // 亮洋红色
#define LCD_LIGHTYELLOW    RGB565(255, 255, 128)   // 亮黄色
#define LCD_DARKBLUE       RGB565(0, 0, 128)       // 深蓝色
#define LCD_DARKGREEN      RGB565(0, 128, 0)       // 深绿色
#define LCD_DARKRED        RGB565(128, 0, 0)       // 深红色
#define LCD_DARKCYAN       RGB565(0, 128, 128)     // 深青色
#define LCD_DARKMAGENTA    RGB565(128, 0, 128)     // 深洋红色
#define LCD_DARKYELLOW     RGB565(128, 128, 0)     // 深黄色
#define LCD_WHITE          RGB565(255, 255, 255)   // 纯白色
#define LCD_LIGHTGRAY      RGB565(211, 211, 211)   // 亮灰色
#define LCD_GRAY           RGB565(128, 128, 128)   // 灰色
#define LCD_DARKGRAY       RGB565(64, 64, 64)      // 深灰色
#define LCD_BLACK          RGB565(0, 0, 0)         // 纯黑色
#define LCD_BROWN          RGB565(165, 42, 42)     // 棕色
#define LCD_ORANGE         RGB565(255, 165, 0)      // 橙色
#define LCD_TRANSPARENT    RGB565(0, 0, 0)         // 透明色

/**
 * @brief 
 * 
 * @param xStart 
 * @param yStart 
 * @param xEnd 
 * @param yEnd 
 * @param Color 
 */
void LCD_DrawPoint(uint16_t x,uint16_t y,uint16_t color);
uint16_t LCD_ReadPoint(uint16_t x,uint16_t y);
void LCD_Cler(uint16_t color);
void LCD_Fill(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint16_t color);
//void LCD_DrawHLine(uint16_t _usX, uint16_t _usY, uint16_t _usLen , uint16_t _usColor);
//void LCD_DrawVLine(uint16_t _usX , uint16_t _usY , uint16_t _usLen , uint16_t _usColor);
//void LCD_DrawPoints(uint16_t *x, uint16_t *y, uint16_t _usSize, uint16_t _usColor);
//void LCD_DrawRect(uint16_t _usX, uint16_t _usY, uint16_t _usHeight, uint16_t _usWidth, uint16_t _usColor);
//void LCD_DrawLine(uint16_t _usX1 , uint16_t _usY1 , uint16_t _usX2 , uint16_t _usY2 , uint16_t _usColor);
void LCD_DrawBMP(uint16_t _usX, uint16_t _usY, uint16_t _usHeight, uint16_t _usWidth, uint16_t *_ptr);
//void LCD_DrawCircle(uint16_t _usX, uint16_t _usY, uint16_t _usRadius, uint16_t _usColor);
void LCD_DMA2D_Fill(uint16_t xStart,uint16_t yStart,uint16_t xEnd,uint16_t yEnd,uint16_t Color);
void LCD_DMA2D_Image(uint16_t xStart,uint16_t yStart,uint16_t xEnd,uint16_t yEnd,void *Image);
#endif // !__BSP_LTDC_DRAW_H




