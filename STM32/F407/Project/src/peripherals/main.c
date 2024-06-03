#include "gpio.h"
#include "systick.h"
#include "uart.h"
#include "soft_i2c.h"
#include "oled_096.h"
#include "mpu6050.h"
#include "DI.h"
#include "Struct_Para.h"

#define Version "STM32F407 V1.0"

void I2C_Test(void)
{
}
uint8_t _val = 0;
int main(void)
{

#if (UART_COUNT > 0)
	COM_Init();
#endif
#if DI_NUM > 0
	DI_Init();
#endif
#if (I2C_COUNT > 0)
	Soft_I2C_Init();
#endif
	Soft_I2C_SacnBus(I2C_1);

	IO_Init(PF9,
			GPIO_Mode_OUT, GPIO_OType_PP,
			GPIO_PuPd_NOPULL, GPIO_Speed_2MHz);
	IO_Init(PF10,
			GPIO_Mode_OUT, GPIO_OType_PP,
			GPIO_PuPd_NOPULL, GPIO_Speed_2MHz);

	_LOG("%s\r\n", Version);

	OLED_Init();

	OLED_Clear(0x00);

	OLED_ShowString(10, 2, "HHD Hello!", 16);
	OLED_ShowCHinese(0, 0, 0);

	while (1)
	{
		// I2C_Test();
		DI_Read(&UserPara.DI_Value);
		IO_Write(PF9, _val);
		IO_Write(PF10, _val = ~_val);
		Delay_Ms(500);
	}
}
