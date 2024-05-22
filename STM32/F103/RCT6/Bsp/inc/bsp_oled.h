#ifndef __BSP_OLED_H
#define __BSP_OLED_H

#include "stm32f10x.h"
#include "stdlib.h"

#include "bsp_systick.h"
#include "bsp_soft_spi.h"

#define OLED_DC(n) ((n) ? __GPIO_SET_BIT(GPIOA, 12) : __GPIO_RESET_BIT(GPIOA, 12))
#define OLED_RS(n) ((n) ? __GPIO_SET_BIT(GPIOA, 5) : __GPIO_RESET_BIT(GPIOA, 5))

#define OLED_CMD 0  // 写命令
#define OLED_DATA 1 // 写数据
// OLED控制用函数
extern uint8_t OLED_GRAM[128][8];
void OLED_WR_Byte(u8 dat, u8 cmd); // 写数据或命令
void OLED_Display_On(void);        // 开屏
void OLED_Display_Off(void);       // 息屏
void OLED_Refresh_Gram(void);      // 刷新

void OLED_Init(void);                                                 // 初始化
void OLED_Clear(void);                                                // 清屏
void OLED_DrawPoint(int x, int y, u8 t);                              // 画点
void OLED_ShowNumber(u8 x, u8 y, u32 num, u8 len, u8 size);           // 正整数
void OLED_Showdecimalchar(u8 x, u8 y, float num, u8 z_len, u8 f_len); // 浮点数
void OLED_ShowChar(u8 x, u8 y, u8 chr, u8 size, u8 mode);             // 单字符
void OLED_ShowString(u8 x, u8 y, char *p, u8 size, u8 mode);          // 字符串
void OLED_Show_CH(u8 x, u8 y, u8 chr, u8 size, u8 mode);              // 单字
void OLED_Show_chString(u8 x, u8 y, u8 ch[], u8 size);                // 多字，中英数字都行
void OLED_Show_MY_String(u8 x, u8 y, const u8 *p, u8 size, u8 mode);
void chString1(void);                                  // 自定义句子
void line(u8 x, u8 y, u8 length, u8 mode);             // 单点画线
void drawline(float x1, float y1, float x2, float y2); // 两点画线(参数方程)
void OLED_DrawLine(int x0, int y0, int x1, int y1);    // bresenham画线
void OLED_ClearLine(int x0, int y0, int x1, int y1);
void OLED_DrawSolidBox(int x0, int y0, int x1, int y1);
void OLED_ClearSolidBox(int x0, int y0, int x1, int y1);
void circle(int x, int y, u8 r);                                             // 画圆(参数方程)
void OLED_DrawCircle(int x0, int y0, u8 r);                                  // 中点画圆法
void OLED_DrawCircle2(u8 x0, u8 y0, u8 r);                                   // bresenham画圆法
void OLED_DrawFullCircle(u8 x0, u8 y0, u8 r);                                // 实心圆
void ellipse(int x, int y, u8 major_semi_axis, u8 minor_semi_axis, float t); // 椭圆(参数方程)
void OLED_DrawRect(u8 x, u8 y, u8 length, u8 high);                          // 中心点画矩形
void OLED_DrawRoundRect(u8 x, u8 y, u8 length, u8 high, u8 r);               // 圆角矩形
void progress_right(u8 x, u8 y, u8 length, u8 width, u8 value);              // 向右进度条
void progress_up(u8 x, u8 y, u8 length, u8 width, u8 value);                 // 向上进度条
void OLED_ShowBMP(const uint8_t BMP[]);
void OLED_setroll(void); // 设置滚动，必须静态画面
void OLED_roll(u8 i);    // 滚动开关
void oled_test(void);
#endif
