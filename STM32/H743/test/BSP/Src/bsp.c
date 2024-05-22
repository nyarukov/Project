#include "bsp.h"

void Bsp_Init(void)
{
	MPU_Config();
	// SCB_EnableICache();
	// SCB_EnableDCache();
	HAL_Init();
	SystemClock_Config();

	MX_GPIO_Init();
	// 200000000/20000 =10kHZ
	// 500ms,200ms
	BaseTIM6_Init(15, 20000, 0);
	TIM3_Init(4,0);
	Uart_Init();
	u1_printf("*****************STM32H743IIT6_V1.2***************\r\n");
	PLL_CLK_Ptintf();

	//Led_Init();
	//KEY_Init();
}

void Bsp_Loop(void)
{

	if (Uart1.Flag == 1)
	{
		Modbus_check(Uart1.buffer, Uart1.Cnt);

	}
}

void Error_Handler(char *file, uint32_t line)
{
	u1_printf("Wrong parameters value: file %s on line %d\r\n", file, line);
	while (1)
	{
	}
}

