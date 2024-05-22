#include "main.h"

uint8_t arr[5]={1,2,3,4,5};
int main(void)
{
	MPU_Config();
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();

	Uart_Init();

    printf("STM32H743IIT6_V1.2\r\n");

	Command_List();
	//Led_Init();
	Start_Boot();
	
	while (1)
	{
		Match_Cmd((char *)Uart1.Rxbuf);
	}
}
