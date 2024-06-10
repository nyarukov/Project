/*
 * 项目名称: oled_096
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-02 23:44:38
 * 最后修改日期: 2024-06-02 23:44:38
 * 描述: 0.96寸OLED驱动
 */

#include "oled_096.h"
#include "oledfont.h"
// C 文件内容...

// void OLED_WR_Byte(uint8_t Reg, uint8_t Cmd)
// {
//     if (Cmd)
//     {
//         I2C_WriteByte(0x40, Reg);
//     }
//     else
//     {
//         I2C_WriteByte(0x00, Reg);
//     }
// }

// void OLED_Set_Pos(uint8_t x, uint8_t y)
// {
//     OLED_WR_Byte(0xb0 + y, OLED_CMD);
//     OLED_WR_Byte(((x & 0xf0) >> 4) | 0x10, OLED_CMD);
//     OLED_WR_Byte((x & 0x0f), OLED_CMD);
// }

// void OLED_Display_On(void)
// {
//     OLED_WR_Byte(0X8D, OLED_CMD); // SET DCDC命令
//     OLED_WR_Byte(0X14, OLED_CMD); // DCDC ON
//     OLED_WR_Byte(0XAF, OLED_CMD); // DISPLAY ON
// }

// void OLED_Display_Off(void)
// {
//     OLED_WR_Byte(0X8D, OLED_CMD); // SET DCDC命令
//     OLED_WR_Byte(0X10, OLED_CMD); // DCDC OFF
//     OLED_WR_Byte(0XAE, OLED_CMD); // DISPLAY OFF
// }

// void OLED_Clear(uint8_t Color)
// {
//     uint8_t i, n;
//     for (i = 0; i < 8; i++)
//     {
//         OLED_WR_Byte(0xb0 + i, OLED_CMD); // 設置頁位址（0~7）
//         OLED_WR_Byte(0x00, OLED_CMD);     // 設置顯示位置—列低位址
//         OLED_WR_Byte(0x10, OLED_CMD);     // 設置顯示位置—列高位址
//         for (n = 0; n < 128; n++)
//             OLED_WR_Byte(Color, OLED_DATA);
//     } // 更新顯示
// }
// void OLED_On(void)
// {
//     uint8_t i, n;
//     for (i = 0; i < 8; i++)
//     {
//         OLED_WR_Byte(0xb0 + i, OLED_CMD); // 設置頁位址（0~7）
//         OLED_WR_Byte(0x00, OLED_CMD);     // 設置顯示位置—列低位址
//         OLED_WR_Byte(0x10, OLED_CMD);     // 設置顯示位置—列高位址
//         for (n = 0; n < 128; n++)
//             OLED_WR_Byte(1, OLED_DATA);
//     }
// }

// uint32_t oled_pow(uint8_t m, uint8_t n)
// {
//     uint32_t result = 1;
//     while (n--)
//         result *= m;
//     return result;
// }

// void OLED_ShowChar(uint8_t x, uint8_t y, uint8_t Chr, uint8_t Size)
// {
//     unsigned char c = 0, i = 0;
//     c = Chr - ' ';
//     if (x > Max_Column - 1)
//     {
//         x = 0;
//         y = y + 2;
//     }
//     if (Size == 16)
//     {
//         OLED_Set_Pos(x, y);
//         for (i = 0; i < 8; i++)
//             OLED_WR_Byte(F8X16[c * 16 + i], OLED_DATA);
//         OLED_Set_Pos(x, y + 1);
//         for (i = 0; i < 8; i++)
//             OLED_WR_Byte(F8X16[c * 16 + i + 8], OLED_DATA);
//     }
//     else
//     {
//         OLED_Set_Pos(x, y);
//         for (i = 0; i < 6; i++)
//             OLED_WR_Byte(F6x8[c][i], OLED_DATA);
//     }
// }

// void OLED_ShowNum(uint8_t x, uint8_t y, uint32_t Num, uint8_t Len, uint8_t Size)
// {
//     uint8_t t, temp;
//     uint8_t enshow = 0;
//     for (t = 0; t < Len; t++)
//     {
//         temp = (Num / oled_pow(10, Len - t - 1)) % 10;
//         if (enshow == 0 && t < (Len - 1))
//         {
//             if (temp == 0)
//             {
//                 OLED_ShowChar(x + (Size / 2) * t, y, ' ', Size);
//                 continue;
//             }
//             else
//                 enshow = 1;
//         }
//         OLED_ShowChar(x + (Size / 2) * t, y, temp + '0', Size);
//     }
// }

// // 顯示一個字符號串
// void OLED_ShowString(uint8_t x, uint8_t y, uint8_t *Str, uint8_t Size)
// {
//     uint8_t j = 0;
//     while (Str[j] != '\0')
//     {
//         OLED_ShowChar(x, y, Str[j], Size);
//         x += 8;
//         if (x > 120)
//         {
//             x = 0;
//             y += 2;
//         }
//         j++;
//     }
// }

// // 顯示漢字
// void OLED_ShowCHinese(uint8_t x, uint8_t y, uint8_t Chin)
// {
//     uint8_t t, adder = 0;
//     OLED_Set_Pos(x, y);
//     for (t = 0; t < 16; t++)
//     {
//         OLED_WR_Byte(Hzk[2 * Chin][t], OLED_DATA);
//         adder += 1;
//     }
//     OLED_Set_Pos(x, y + 1);
//     for (t = 0; t < 16; t++)
//     {
//         OLED_WR_Byte(Hzk[2 * Chin + 1][t], OLED_DATA);
//         adder += 1;
//     }
// }

// void OLED_Init(void)
// {
//     OLED_WR_Byte(0xAE, OLED_CMD); //--display off
//     OLED_WR_Byte(0x00, OLED_CMD); //---set low column address
//     OLED_WR_Byte(0x10, OLED_CMD); //---set high column address
//     OLED_WR_Byte(0x40, OLED_CMD); //--set start line address
//     OLED_WR_Byte(0xB0, OLED_CMD); //--set page address
//     OLED_WR_Byte(0x81, OLED_CMD); // contract control
//     OLED_WR_Byte(0xFF, OLED_CMD); //--128
//     OLED_WR_Byte(0xA1, OLED_CMD); // set segment remap
//     OLED_WR_Byte(0xA6, OLED_CMD); //--normal / reverse
//     OLED_WR_Byte(0xA8, OLED_CMD); //--set multiplex ratio(1 to 64)
//     OLED_WR_Byte(0x3F, OLED_CMD); //--1/32 duty
//     OLED_WR_Byte(0xC8, OLED_CMD); // Com scan direction
//     OLED_WR_Byte(0xD3, OLED_CMD); //-set display offset
//     OLED_WR_Byte(0x00, OLED_CMD); //

//     OLED_WR_Byte(0xD5, OLED_CMD); // set osc division
//     OLED_WR_Byte(0x80, OLED_CMD); //

//     OLED_WR_Byte(0xD8, OLED_CMD); // set area color mode off
//     OLED_WR_Byte(0x05, OLED_CMD); //

//     OLED_WR_Byte(0xD9, OLED_CMD); // Set Pre-Charge Period
//     OLED_WR_Byte(0xF1, OLED_CMD); //

//     OLED_WR_Byte(0xDA, OLED_CMD); // set com pin configuartion
//     OLED_WR_Byte(0x12, OLED_CMD); //

//     OLED_WR_Byte(0xDB, OLED_CMD); // set Vcomh
//     OLED_WR_Byte(0x30, OLED_CMD); //

//     OLED_WR_Byte(0x8D, OLED_CMD); // set charge pump enable
//     OLED_WR_Byte(0x14, OLED_CMD); //

//     OLED_WR_Byte(0xAF, OLED_CMD); //--turn on oled panel
// }
