#include "stm32l1xx.h"
#define LED		GPIO_Pin_2

int main(void){
	GPIO_InitTypeDef	GPIO_InitStreuct;
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
	
	
	
	GPIO_InitStreuct.GPIO_Pin=LED;
	GPIO_InitStreuct.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_InitStreuct.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStreuct.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_InitStreuct.GPIO_Speed=GPIO_Speed_40MHz;
	GPIO_Init(GPIOA,&GPIO_InitStreuct);
	
	while(1){
		
		GPIO_WriteBit(GPIOA,LED,Bit_RESET);
	}
}
