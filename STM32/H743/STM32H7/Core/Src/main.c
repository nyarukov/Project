#include "main.h"
#include "user_lib.h"
#include "mpu.h"
#include "rcc.h"
#include "systick.h"
#include "uart.h"
#include "gpio.h"

int main(void)
{
	MPU_Config();
	HAL_Init();
	SystemClock_Config();

	MX_GPIO_Init();
	Com_Init(COM1,115200);
	PLL_CLK_Ptintf();
	Com_printf(COM1,"COM1_Init\r\n");
	IO_Init("PA1",1,1);
	while (1)
	{
		Delay_Ms(1000);
		Com_printf(COM1,"COM1\r\n");
	}
}


