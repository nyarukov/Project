// /*
//  * mpu6050.c
//  *
//  *  Created on: 2023��11��23��
//  *      Author: Yusaka
//  */
// #include "mpu6050.h"

// void MPU6050_Init(void)
// {
//     IIC_GPIO();
// //    MPU6050_Send(MPU6050_POWER1, 0x80);
// //    Delay_Ms(1000);
//     MPU6050_Send(MPU6050_POWER1, 0x01);
//     MPU6050_Send(MPU6050_POWER2, 0x00);
// //    MPU6050_Send(MPU6050_INT_ENABLE, 0x00);
// //    MPU6050_Send(MPU6050_FIFO_EN, 0x00);

//     MPU6050_Send(MPU6050_SMPRT_DIV, 0x9);
//     MPU6050_Send(MPU6050_CONFIG, 0x06);
//     MPU6050_Send(MPU6050_GYRO_CONFIG, 0x18);
//     MPU6050_Send(MPU6050_ACCEL_CONFIG, 0x18);
// }
// uint8_t MPU6050_GetID(void)
// {
//     return MPU6050_Read(MPU6050_WHO_AM_I);
// }

// struct MPU6050_ReadData MPU6050_GetData(void)
// {
//     struct MPU6050_ReadData value;
//     value.ACCEL_XOUT = (MPU6050_Read(MPU6050_ACCEL_XOUT_H) << 8) | MPU6050_Read(MPU6050_ACCEL_XOUT_L);
//     value.ACCEL_YOUT = (MPU6050_Read(MPU6050_ACCEL_YOUT_H) << 8) | MPU6050_Read(MPU6050_ACCEL_YOUT_L);
//     value.ACCEL_ZOUT = (MPU6050_Read(MPU6050_ACCEL_ZOUT_H) << 8) | MPU6050_Read(MPU6050_ACCEL_ZOUT_L);
//     value.TEMP = (MPU6050_Read(MPU6050_TEMP_OUT_H) << 8) | MPU6050_Read(MPU6050_TEMP_OUT_L);
//     value.GYRO_XOUT = (MPU6050_Read(MPU6050_GYRO_XOUT_H) << 8) | MPU6050_Read(MPU6050_GYRO_XOUT_L);
//     value.GYRO_YOUT = (MPU6050_Read(MPU6050_GYRO_YOUT_H) << 8) | MPU6050_Read(MPU6050_GYRO_YOUT_L);
//     value.GYRO_ZOUT = (MPU6050_Read(MPU6050_GYRO_ZOUT_H) << 8) | MPU6050_Read(MPU6050_GYRO_ZOUT_L);
//     return value;
// }
// void MPU6050_Getvaule(int16_t *Accx, int16_t *Accy, int16_t *Accz, int16_t *gyrox, int16_t *gyroy, int16_t *gyroz)
// {
//     int8_t dataH, dataL;
//     dataH = MPU6050_Read(MPU6050_ACCEL_XOUT_H);
//     dataL = MPU6050_Read(MPU6050_ACCEL_XOUT_L);
//     *Accx = (dataH << 8) | dataL;
//     dataH = MPU6050_Read(MPU6050_ACCEL_YOUT_H);
//     dataL = MPU6050_Read(MPU6050_ACCEL_YOUT_L);
//     *Accy = (dataH << 8) | dataL;
//     dataH = MPU6050_Read(MPU6050_ACCEL_ZOUT_H);
//     dataL = MPU6050_Read(MPU6050_ACCEL_ZOUT_L);
//     *Accz = (dataH << 8) | dataL;
//     dataH = MPU6050_Read(MPU6050_GYRO_XOUT_H);
//     dataL = MPU6050_Read(MPU6050_GYRO_XOUT_L);
//     *gyrox = (dataH << 8) | dataL;
//     dataH = MPU6050_Read(MPU6050_GYRO_YOUT_H);
//     dataL = MPU6050_Read(MPU6050_GYRO_YOUT_L);
//     *gyroy = (dataH << 8) | dataL;
//     dataH = MPU6050_Read(MPU6050_GYRO_ZOUT_H);
//     dataL = MPU6050_Read(MPU6050_GYRO_ZOUT_L);
//     *gyroz = (dataH << 8) | dataL;
// }
// void MPU6050_Send(uint8_t RegAddress, uint8_t Data)
// {
//     IIC_Start();
//     IIC_SendByte(MPU6050_ADDRESS);
//     IIC_ReadACK();
//     IIC_SendByte(RegAddress);
//     IIC_ReadACK();
//     IIC_SendByte(Data);
//     IIC_ReadACK();
//     IIC_Stop();
// }
// uint8_t MPU6050_Read(uint8_t RegAddress)
// {
//     uint8_t RegData;
//     IIC_Start();
//     IIC_SendByte(MPU6050_ADDRESS);
//     IIC_ReadACK();
//     IIC_SendByte(RegAddress);
//     IIC_ReadACK();
//     IIC_Start();
//     IIC_SendByte(MPU6050_ADDRESS | 0x01);
//     IIC_ReadACK();
//     RegData = IIC_ReadByte();
//     IIC_SendACK(1);
//     return RegData;
// }
