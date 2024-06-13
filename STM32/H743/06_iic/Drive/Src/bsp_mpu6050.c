/*
 * @Author: Yusaka
 * @Date: 2023-11-25 16:51:25
 * @LastEditors: Yusaka
 * @LastEditTime: 2023-11-25 17:03:07
 * @FilePath: /09_iic/src/mpu6050.c
 * @Description:
 */
#include "bsp_mpu6050.h"




void MPU6050_init(void)
{
    SoftIIC_Init();
    MPU6050_Send(MPU6050_POWER1, 0x01);
    MPU6050_Send(MPU6050_POWER2, 0x00);
    MPU6050_Send(MPU6050_SMPRT_DIV, 0x09);
    MPU6050_Send(MPU6050_CONFIG, 0x06);
    MPU6050_Send(MPU6050_GYRO_CONFIG, 0x18);
    MPU6050_Send(MPU6050_ACCEL_CONFIG, 0x18);
}

uint8_t MPU6050_ID(void)
{
    return MPU6050_Read(MPU6050_WHO_AM_I);
}

void MPU6050_Send(uint8_t RegAddress, uint8_t Data)
{
    SoftIIC_Start();
    SoftIIC_SendByte(MPU6050_ADDRESS);
    SoftIIC_ReceiveACK();
    SoftIIC_SendByte(RegAddress);
    SoftIIC_ReceiveACK();
    SoftIIC_SendByte(Data);
    SoftIIC_ReceiveACK();
    SoftIIC_Stop();
}
uint8_t MPU6050_Read(uint8_t RegAddress)
{
    uint8_t RegData;
    SoftIIC_Start();
    SoftIIC_SendByte(MPU6050_ADDRESS);
    SoftIIC_ReceiveACK();
    SoftIIC_SendByte(RegAddress);
    SoftIIC_ReceiveACK();
	
    SoftIIC_Start();
    SoftIIC_SendByte(MPU6050_ADDRESS | 0x01);
    SoftIIC_ReceiveACK();
    RegData = SoftIIC_ReceiveByte();
    SoftIIC_SendACK(1);
    SoftIIC_Stop();
	
    return RegData;
}

void MPU6050_ReadData(void){
    mpu6050.ACCEL_XOUT=(MPU6050_Read(MPU6050_ACCEL_XOUT_H)<<8)|(MPU6050_Read(MPU6050_ACCEL_XOUT_L));
    mpu6050.ACCEL_YOUT=(MPU6050_Read(MPU6050_ACCEL_YOUT_H)<<8)|(MPU6050_Read(MPU6050_ACCEL_YOUT_L));
    mpu6050.ACCEL_ZOUT=(MPU6050_Read(MPU6050_ACCEL_ZOUT_H)<<8)|(MPU6050_Read(MPU6050_ACCEL_ZOUT_L));
    mpu6050.GYRO_XOUT=(MPU6050_Read(MPU6050_GYRO_XOUT_H)<<8)|(MPU6050_Read(MPU6050_GYRO_XOUT_L));
    mpu6050.GYRO_YOUT=(MPU6050_Read(MPU6050_GYRO_YOUT_H)<<8)|(MPU6050_Read(MPU6050_GYRO_YOUT_L));
    mpu6050.GYRO_ZOUT=(MPU6050_Read(MPU6050_GYRO_ZOUT_H)<<8)|(MPU6050_Read(MPU6050_GYRO_ZOUT_L));
    mpu6050.TEMP=(MPU6050_Read(MPU6050_TEMP_OUT_H)<<8)|(MPU6050_Read(MPU6050_TEMP_OUT_L));
}
