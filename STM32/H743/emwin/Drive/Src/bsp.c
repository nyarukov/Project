#include "bsp.h"

u8 val = 0;
u16 i;
u8 wbuff[],rbuff[];
void Bsp_Init(void)
{
	MPU_Config();
	SCB_EnableICache(); // 使能ICache
	SCB_EnableDCache(); // 使能DCache
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();
	Uart_Init(115200);
	printf("*****************STM32H743IIT6_emWin***************\r\n");
	PLL_CLK_Ptintf();
	LTDC_Init();
	FT5426_Init();
	BaseTIM6_Init(4,59999,0);

	
	Led_Init();

	MainTask();
}
void Bsp_Loop(void)
{
	Led_Set(led_b,val);
	val=~val;
	HAL_Delay(100);
}
