/*
 * 项目名称: soft_i2c
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-01
 * 最后修改日期: 2024-06-01 18:09:50
 * 描述: 软件I2C驱动
 */

#ifndef __SOFT_I2C_H
#define __SOFT_I2C_H

// 头文件内容...

#include "middle.h"
#include "gpio.h"
#include "systick.h"
#include "uart.h"

typedef enum
{
    I2C_1 = 0,
    I2C_2,
    I2C_3,
    I2C_4
} I2C_ID;

// clang-format off

#define I2C_CLOCK           500000
#define soft_delay(n)       Delay_Us(I2C_CLOCK / (n))



#define I2C_CMD_WRITE       (0xFE)
#define I2C_CMD_READ        (0x01)

#define I2C1_EN    1
#define I2C2_EN    0
#define I2C3_EN    0
#define I2C4_EN    0



#define I2C_MODE_MASTER         0
#define I2C_MODE_SLAVE          1

#if I2C1_EN == 1
    #define I2C1_SCL            PB8
    #define I2C1_SDA            PB9

    #define I2C1_MODE           I2C_MODE_MASTER
    #define I2C1_CLOCK_SPEED    100000

    #define I2C1_SLAVE_ADDR     0x10

    #if I2C1_MODE == I2C_MODE_MASTER

        #define I2C1_SLAVE_COUNT    2
        
    #else
        #define I2C1_TX_BUF_SIZE  64
        uint8_t I2C1_TX_BUFFER[I2C1_TX_BUF_SIZE];
    #endif

    #define I2C1_IDX    (0)
#else
    #define I2C1_IDX    (-1)
#endif


#if I2C2_EN == 1
    #define I2C2_SCL            PB6
    #define I2C2_SDA            PB7
    
    #define I2C2_MODE           I2C_MODE_MASTER
    #define I2C2_CLOCK_SPEED    100000

    #define I2C2_SLAVE_ADDR     0x10

    #if I2C2_MODE == I2C_MODE_MASTER

        #define I2C2_SLAVE_COUNT    4
        
    #else

        #define I2C2_TX_BUF_SIZE  64
        uint8_t I2C2_TX_BUFFER[I2C2_TX_BUF_SIZE];
    #endif

    #define I2C2_IDX    (I2C1_IDX + 1)
#else
    #define I2C2_IDX    I2C1_IDX
#endif


#if I2C3_EN == 1
    #define I2C3_SCL            PD6
    #define I2C3_SDA            PD7

    #define I2C3_MODE           I2C_MODE_MASTER
    #define I2C3_CLOCK_SPEED    100000

    #define I2C3_SLAVE_ADDR     0x10

    #if I2C3_MODE == I2C_MODE_MASTER

        #define I2C3_SLAVE_COUNT    2

        #define I2C3_SLAVE_ADDR1  0x68
        #define I2C3_SLAVE1_RX_BUF_SIZE  64
    #else
        #define I2C3_TX_BUF_SIZE  64
        uint8_t I2C3_TX_BUFFER[I2C3_TX_BUF_SIZE];
    #endif

    #define I2C3_IDX    (I2C2_IDX + 1)
#else
    #define I2C3_IDX    I2C2_IDX
#endif


#if I2C4_EN == 1
    #define I2C4_SCL            PD6
    #define I2C4_SDA            PD7
    
    #define I2C4_MODE           I2C_MODE_MASTER
    #define I2C4_CLOCK_SPEED    100000

    #define I2C4_SLAVE_ADDR     0x10

    #if I2C4_MODE == I2C_MODE_MASTER

        #define I2C4_SLAVE_COUNT    2

        #define I2C4_SLAVE_ADDR1  0x68
        #define I2C4_SLAVE1_RX_BUF_SIZE  64

    #else

        #define I2C4_TX_BUF_SIZE  64
        uint8_t I2C4_TX_BUFFER[I2C4_TX_BUF_SIZE];
    #endif

    #define I2C4_IDX    (I2C3_IDX + 1)
#else
    #define I2C4_IDX    I2C3_IDX
#endif

#define I2C_COUNT       (I2C4_IDX + 1)
// clang-format on

void Soft_I2C_Init(void);
Status Soft_I2C_AddrCheck(I2C_ID _ID, uint8_t _Addr);
void Soft_I2C_SacnBus(I2C_ID _ID);

Status Soft_I2C_WriteByteWithACK(I2C_ID _ID, uint8_t _Addr,
                                 uint8_t _RegAddr,
                                 uint8_t _Data);

Status Soft_I2C_ReadByteWithACK(I2C_ID _ID, uint8_t _Addr,
                                uint8_t _RegAddr,
                                uint8_t *_pData);

Status Soft_I2C_Write(I2C_ID _ID, uint8_t _Addr,
                      uint8_t _RegAddr,
                      uint8_t *_pBuf, uint16_t _Len);

Status Soft_I2C_Read(I2C_ID _ID, uint8_t _Addr,
                     uint8_t _RegAddr,
                     uint8_t *_pBuf, uint16_t _Len);

#endif
