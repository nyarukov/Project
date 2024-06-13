/*
 * 项目名称: mpu6050
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-02 21:43:58
 * 最后修改日期: 2024-06-02 21:43:58
 * 描述: MPU6050驱动
 */

#ifndef __MPU6050_H
#define __MPU6050_H

// 头文件内容...

// clang-format off

// #define I2C_MODE    0   //0软件，1硬件

// #define MPU6050_I2C_BUS_ID      I2C_1

// #if I2C_MODE
//     #include "hard_i2c.h"
// #else
//    #include "soft_i2c.h"
// #endif

// #if I2C_MODE
//    #define  I2C_Start()                            
//    #define  I2C_Stop()                             
//    #define  I2C_SendByte(_Byte)                    
//    #define  I2C_SendACK(n)                         
//    #define  I2C_ReceiveByte()                      
//    #define  I2C_ReceiveACK(n)                      
// #else
//    #define  I2C_Start()                            Soft_I2C_Start(MPU6050_I2C_BUS_ID)
//    #define  I2C_Stop()                             Soft_I2C_Stop(MPU6050_I2C_BUS_ID)
//    #define  I2C_SendByte(_Byte)                    Soft_I2C_SendByte(MPU6050_I2C_BUS_ID,_Byte)    
//    #define  I2C_SendACK(n)                         Soft_I2C_SendACK(MPU6050_I2C_BUS_ID,n)
//    #define  I2C_ReceiveByte()                      Soft_I2C_ReceiveByte(MPU6050_I2C_BUS_ID)
//    #define  I2C_ReceiveBytes(_pBuf,_len)           Soft_I2C_ReceiveBytes(MPU6050_I2C_BUS_ID,_pBuf,_len)
//    #define  I2C_ReceiveACK()                       Soft_I2C_ReceiveACK(MPU6050_I2C_BUS_ID)
// #endif

// #define MPU6050_WRITE           0xD0
// #define MPU6050_READ            0xD1

// #define MPU6050_POWER1          0X6B
// #define MPU6050_POWER2          0x6C
// #define MPU6050_INT_ENABLE      0x38    
// #define MPU6050_SMPRT_DIV       0x19    
// #define MPU6050_CONFIG          0x1A
// #define MPU6050_GYRO_CONFIG     0x1B
// #define MPU6050_ACCEL_CONFIG    0x1C
// #define MPU6050_WHO_AM_I        0x75
// #define MPU6050_FIFO_EN         0x23

// #define MPU6050_ACCEL_XOUT_H    0x3B
// #define MPU6050_ACCEL_XOUT_L    0x3C
// #define MPU6050_ACCEL_YOUT_H    0x3D
// #define MPU6050_ACCEL_YOUT_L    0x3E
// #define MPU6050_ACCEL_ZOUT_H    0x3F
// #define MPU6050_ACCEL_ZOUT_L    0x40
// #define MPU6050_TEMP_OUT_H      0x41
// #define MPU6050_TEMP_OUT_L      0x42
// #define MPU6050_GYRO_XOUT_H     0x43
// #define MPU6050_GYRO_XOUT_L     0x44
// #define MPU6050_GYRO_YOUT_H     0x45
// #define MPU6050_GYRO_YOUT_L     0x46
// #define MPU6050_GYRO_ZOUT_H     0x47
// #define MPU6050_GYRO_ZOUT_L     0x48

// // clang-format on

// typedef struct
// {
//     int16_t ACCEL_XOUT;
//     int16_t ACCEL_YOUT;
//     int16_t ACCEL_ZOUT;
//     int16_t TEMP;
//     int16_t GYRO_XOUT;
//     int16_t GYRO_YOUT;
//     int16_t GYRO_ZOUT;
// } MPU6050_t;

// extern MPU6050_t mpu6050;

// void MPU6050_Init(void);
// uint8_t MPU6050_ID(void);
// void MPU6050_ReadData(void);

#endif
