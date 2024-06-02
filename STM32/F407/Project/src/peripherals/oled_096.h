/*
 * 项目名称: oled_096
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-02 23:44:38
 * 最后修改日期: 2024-06-02 23:44:38
 * 描述: 0.96寸OLED驱动
 */

#ifndef __OLED_096_H
#define __OLED_096_H

// 头文件内容...

// clang-format off
#define I2C_MODE        0 // 0软件，1硬件

#define OLED_096_I2C_BUS_ID     I2C_1
#define OLED_SLAVE_ADDR         (0x3C)

#if OLED_I2C_MODE
#include "hard_i2c.h"
#else
#include "soft_i2c.h"
#endif

#if OLED_I2C_MODE
    #define I2C_Start()
    #define I2C_Stop()
    #define I2C_SendByte(_Byte)
    #define I2C_SendACK(n)
    #define I2C_ReceiveByte()
    #define I2C_ReceiveACK(n)
#else
    #define I2C_WriteByte(_Reg, _Data)                 \
        Soft_I2C_WriteByteWithACK(OLED_096_I2C_BUS_ID, \
                                OLED_SLAVE_ADDR,       \
                                _Reg, _Data)

    #define I2C_ReadByte(_Reg, _Data)                 \
        Soft_I2C_ReadByteWithACK(OLED_096_I2C_BUS_ID, \
                                OLED_SLAVE_ADDR,      \
                                _Reg, _Data)

    #define I2C_Write(_Reg, _pBuf, _Len)    \
        Soft_I2C_Write(OLED_096_I2C_BUS_ID, \
                    OLED_SLAVE_ADDR,        \
                    _Reg, _pBuf, _Len)

    #define I2C_Read(_Reg, _pBuf, _Len)    \
        Soft_I2C_Read(OLED_096_I2C_BUS_ID, \
                    OLED_SLAVE_ADDR,       \
                    _Reg, _pBuf, _Len)
#endif

#define OLED_CMD            (0)	
#define OLED_DATA           (1)

#define Max_Column	        (128)
#define Max_Row		        (64)

// clang-format on

void OLED_Init(void);
void OLED_Clear(uint8_t Color);
void OLED_ShowChar(uint8_t x, uint8_t y, uint8_t Chr, uint8_t Size);
void OLED_ShowNum(uint8_t x, uint8_t y, uint32_t Num, uint8_t Len, uint8_t Size);
void OLED_ShowString(uint8_t x, uint8_t y, uint8_t *Str, uint8_t Size);
void OLED_Set_Pos(uint8_t x, uint8_t y);
void OLED_ShowCHinese(uint8_t x, uint8_t y, uint8_t Chin);
#endif
