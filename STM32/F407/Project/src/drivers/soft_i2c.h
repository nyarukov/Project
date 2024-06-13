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
#include "uart.h"

#if (I2C_COUNT > 0)

#define _I2C_LOG(...) _LOG(__VA_ARGS__)

typedef enum
{
    I2C_1 = I2C1_IDX,
    I2C_2 = I2C2_IDX,
    I2C_3 = I2C3_IDX,
    I2C_4 = I2C4_IDX
} I2C_ID;

typedef struct I2C_Config
{
    uint8_t SCL_IO;
    uint8_t SDA_IO;
    uint8_t Mode;
    uint8_t Slave_Addr;  // 作为从机的地址
    uint8_t Slave_Count; // 作为主机时从机的数量
    uint32_t Clock_Speed;
} I2C_Config;

typedef struct I2C_Slave_Config
{
    uint8_t Addr;
    Buffer_t Rx_Buf;
} I2C_Slave_Config;

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

#endif
