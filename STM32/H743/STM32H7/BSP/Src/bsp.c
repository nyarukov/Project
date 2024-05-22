#include "bsp.h"

void Bsp_Init(void)
{
	MPU_Config();
	HAL_Init();
	SystemClock_Config();

	MX_GPIO_Init();

	//BaseTIM6_Init(15-1, 20000-1, 0);
	//100 000 000   
	//	PWM:Freq=CK PSC/(PSC+1)/(ARR+1)  200 000 000   20000 10000  
	//	PWM:Duty=CCR/(ARR+1) 500~2500 20000 
	//	PWM:Reso=1/(ARR+1)  20000
	//TIM1_Init(100-1,2000-1,0,1500);
    //100/5*2 =10


}
void Bsp_Loop(void)
{
}

void Error_Handler(char *file, uint32_t line)
{
	Com_printf(COM1,"Wrong parameters value: file %s on line %d\r\n", file, line);
	while (1)
	{
	}
}

