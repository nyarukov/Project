#include "main.h"

MPU6050_t mpu6050;
int main(void)
{
	MPU_Config();
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();

	Led_Init(led_r);
	Uart_Init(115200);

	PLL_CLK_Ptintf();
	printf("InitOK\r\n");
	MPU6050_init();
	uint8_t mpu6050ID=MPU6050_ID();
	printf("mpu6050ID:%#x\r\n",mpu6050ID);
	
	while (1)
	{
//		MPU6050_ReadData();
//		printf("ACCEL_XOUT:%d\r\n",mpu6050.ACCEL_XOUT);
//		printf("ACCEL_YOUT:%d\r\n",mpu6050.ACCEL_YOUT);
//		printf("ACCEL_ZOUT:%d\r\n",mpu6050.ACCEL_ZOUT);
//		printf("GYRO_XOUT:%d\r\n",mpu6050.GYRO_XOUT);
//		printf("GYRO_YOUT:%d\r\n",mpu6050.GYRO_YOUT);
//		printf("GYRO_ZOUT:%d\r\n",mpu6050.GYRO_ZOUT);
//		printf("TEMP:%d\r\n",mpu6050.TEMP);
	}
}
