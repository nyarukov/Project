#include "key.h"

void key_init(enum key_id id){
	GPIO_InitTypeDef GPIO_InitStreuct;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB,ENABLE);
	GPIO_InitStreuct.GPIO_Pin=id;
	GPIO_InitStreuct.GPIO_Mode=GPIO_Mode_IN;
	GPIO_InitStreuct.GPIO_OType=GPIO_OType_OD;
	GPIO_InitStreuct.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_InitStreuct.GPIO_Speed=GPIO_Speed_40MHz;
	GPIO_Init(GPIOB,&GPIO_InitStreuct);
}
