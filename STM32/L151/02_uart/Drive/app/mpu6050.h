/*
 * mpu6050.h
 *
 *  Created on: 2023��11��23��
 *      Author: Yusaka
 */

#ifndef DRIVE_MPU6050_H_
#define DRIVE_MPU6050_H_

#include "iic.h"

#define MPU6050_ADDRESS         0xD0
#define MPU6050_POWER1          0X6B
#define MPU6050_POWER2          0x6C
#define MPU6050_INT_ENABLE      0x38    //�ж�
#define MPU6050_SMPRT_DIV       0x19    //����Ƶ�ʷ�Ƶ
#define MPU6050_CONFIG          0x1A
#define MPU6050_GYRO_CONFIG     0x1B
#define MPU6050_ACCEL_CONFIG    0x1C
#define MPU6050_WHO_AM_I        0x75
#define MPU6050_FIFO_EN         0x23

#define MPU6050_ACCEL_XOUT_H    0x3B
#define MPU6050_ACCEL_XOUT_L    0x3C
#define MPU6050_ACCEL_YOUT_H    0x3D
#define MPU6050_ACCEL_YOUT_L    0x3E
#define MPU6050_ACCEL_ZOUT_H    0x3F
#define MPU6050_ACCEL_ZOUT_L    0x40
#define MPU6050_TEMP_OUT_H      0x41
#define MPU6050_TEMP_OUT_L      0x42
#define MPU6050_GYRO_XOUT_H     0x43
#define MPU6050_GYRO_XOUT_L     0x44
#define MPU6050_GYRO_YOUT_H     0x45
#define MPU6050_GYRO_YOUT_L     0x46
#define MPU6050_GYRO_ZOUT_H     0x47
#define MPU6050_GYRO_ZOUT_L     0x48

struct MPU6050_ReadData{
    int16_t ACCEL_XOUT;
    int16_t ACCEL_YOUT;
    int16_t ACCEL_ZOUT;
    int16_t TEMP;
    int16_t GYRO_XOUT;
    int16_t GYRO_YOUT;
    int16_t GYRO_ZOUT;
};
void MPU6050_Init(void);
uint8_t MPU6050_GetID(void);
struct MPU6050_ReadData MPU6050_GetData(void);
void MPU6050_Getvaule(int16_t *Accx, int16_t *Accy, int16_t *Accz, int16_t *gyrox, int16_t *gyroy, int16_t *gyroz);
void MPU6050_Send(uint8_t RegAddress,uint8_t Data);
uint8_t MPU6050_Read(uint8_t RegAddress);
#endif /* DRIVE_MPU6050_H_ */
