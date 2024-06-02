/*
 * 项目名称: mpu6050
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-02 21:43:58
 * 最后修改日期: 2024-06-02 21:43:58
 * 描述: MPU6050驱动
 */

#include "mpu6050.h"

// C 文件内容...

#if 0
MPU6050_t mpu6050;

static void MPU6050_Send(uint8_t _RegAddress, uint8_t _Data);
static uint8_t MPU6050_Read(uint8_t _RegAddress);

void MPU6050_Init(void)
{
    MPU6050_Send(MPU6050_POWER1, 0x80);
    Delay_Ms(1000);
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
    I2C_Start();
    I2C_SendByte(MPU6050_WRITE);
    I2C_ReceiveACK();
    I2C_SendByte(RegAddress);
    I2C_ReceiveACK();
    I2C_SendByte(Data);
    I2C_ReceiveACK();
    I2C_Stop();
}
uint8_t MPU6050_Read(uint8_t RegAddress)
{
    uint8_t RegData;
    I2C_Start();
    I2C_SendByte(MPU6050_WRITE);
    I2C_ReceiveACK();
    I2C_SendByte(RegAddress);
    I2C_ReceiveACK();
    I2C_Start();
    I2C_SendByte(MPU6050_READ);
    I2C_ReceiveACK();
    RegData = I2C_ReceiveByte();
    I2C_SendACK(1);
    I2C_Stop();

    return RegData;
}

static void MPU6050_Reads(uint8_t _RegAddress, uint8_t *_pBuf, uint8_t _len)
{
    I2C_Start();
    I2C_SendByte(MPU6050_WRITE);
    I2C_ReceiveACK();
    I2C_SendByte(_RegAddress);
    I2C_ReceiveACK();
    I2C_Start();
    I2C_SendByte(MPU6050_READ);
    I2C_ReceiveACK();
    I2C_ReceiveBytes(_pBuf, _len);
    I2C_SendACK(1);
    I2C_Stop();
}

void MPU6050_ReadData(void)
{
    uint8_t RBuffer[14];

    MPU6050_Reads(MPU6050_ACCEL_XOUT_H, RBuffer, 14);

    mpu6050.ACCEL_XOUT = (RBuffer[0] << 8) | RBuffer[1];
    mpu6050.ACCEL_YOUT = (RBuffer[2] << 8) | RBuffer[3];
    mpu6050.ACCEL_ZOUT = (RBuffer[4] << 8) | RBuffer[5];
    mpu6050.TEMP = (RBuffer[6] << 8) | RBuffer[7];
    mpu6050.GYRO_XOUT = (RBuffer[8] << 8) | RBuffer[9];
    mpu6050.GYRO_YOUT = (RBuffer[10] << 8) | RBuffer[11];
    mpu6050.GYRO_ZOUT = (RBuffer[12] << 8) | RBuffer[13];
    _LOG("ACCEL_XOUT:%d\t ACCEL_YOUT:%d\t ACCEL_ZOUT:%d\r\n", mpu6050.ACCEL_XOUT, mpu6050.ACCEL_YOUT, mpu6050.ACCEL_ZOUT);
    _LOG("GYRO_XOUT:%d\t GYRO_YOUT:%d\t GYRO_ZOUT:%d\r\n", mpu6050.GYRO_XOUT, mpu6050.GYRO_YOUT, mpu6050.GYRO_ZOUT);
}
#endif