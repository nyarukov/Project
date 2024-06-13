#include "bsp.h"

void Bsp_Init(void)
{
	// SCB->VTOR = FLASH_BASE | 0x20000;
	MPU_Config();
	SCB_EnableICache();
	SCB_EnableDCache();
	HAL_Init();
	SystemClock_Config();

	MX_GPIO_Init();
	Serial_Init();
	printf("*****************STM32H743IIT6_V1.2***************\r\n");
	PLL_CLK_Ptintf();
	Command_List();
	Led_Init();
	
	//System_Task();

#if LVGL
	BaseTIM6_Init(59999, 4, 0);

	lv_init();
	lv_port_disp_init();
	lv_port_indev_init();

	ui_init();
#endif
}

void Bsp_Loop(void)
{
#if LVGL
	lv_task_handler();
#endif
}

void Error_Handler(char *file, uint32_t line)
{
	printf("Wrong parameters value: file %s on line %d\r\n", file, line);
	while (1)
	{
	}
}