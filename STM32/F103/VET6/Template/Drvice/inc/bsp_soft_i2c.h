#ifndef __BSP_SOFT_I2C_H
#define __BSP_SOFT_I2C_H

#include "stm32f4xx.h"
#include <stdio.h>
#include <stdbool.h>

// 硬件控制接口
typedef struct
{
    void (*init)(void);
    void (*set_scl)(bool state);
    void (*set_sda)(bool state);
    bool (*read_sda)(void);
    void (*set_sda_mode)(bool output);
    void (*delay_us)(void);
} I2C_HardwareControl;

// I2C 通信标志
typedef enum
{
    I2C_SUCCESS, // 操作成功
    I2C_ERROR,   // 通信错误
    I2C_TIMEOUT, // 通信超时
    I2C_NACK,    // 收到从设备的 NACK
    I2C_BUSY     // 总线忙碌
} I2C_Status;

// SoftI2C 结构体
typedef struct
{
    uint8_t address;        // I2C 设备地址
    I2C_HardwareControl hw; // 硬件控制
} SoftI2C;

I2C_Status SoftI2C_Init(SoftI2C *si2c,
                        uint8_t device_address,
                        I2C_HardwareControl hw_control);

void Soft_I2C_Start(SoftI2C *_si2c);
void Soft_I2C_Stop(SoftI2C *_si2c);
void Soft_I2C_SendACK(SoftI2C *_si2c, bool ack);
uint8_t Soft_I2C_ReceiveACK(SoftI2C *_si2c);
void Soft_I2C_SendByte(SoftI2C *_si2c, uint8_t txdata);
uint8_t Soft_I2C_ReceiveByte(SoftI2C *_si2c);
I2C_Status Soft_I2C_ReceiveBytes(SoftI2C *_si2c, uint8_t *pData, uint8_t len);
uint8_t Soft_I2C_AddrCheck(SoftI2C *_si2c, uint8_t _Addr);
I2C_Status Soft_I2C_Write(SoftI2C *si2c, uint8_t _Addr, uint8_t _Reg_Addr, uint8_t *_pBuf, uint16_t _Size);
I2C_Status Soft_I2C_Read(SoftI2C *_si2c, uint8_t device_address, uint8_t *buffer, uint16_t length);
#endif
