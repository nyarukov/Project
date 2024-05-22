#include "bsp.h"

void Bsp_Init(void)
{
	// SCB->VTOR = FLASH_BASE | 0x20000;
	MPU_Config();
	SCB_EnableICache(); // ICache
	SCB_EnableDCache(); // DCache
	HAL_Init();
	SystemClock_Config();

	MX_GPIO_Init();
	
	Serial1_Init(115200);
	printf("*****************STM32H743IIT6_V1.2***************\r\n");
	PLL_CLK_Ptintf();
	Led_Init();
	System_Task();
}

void Bsp_Loop(void)
{
	
}

void Error_Handler(char *file, uint32_t line)
{
	printf("Wrong parameters value: file %s on line %d\r\n", file, line);
	while (1)
	{
	}
}
