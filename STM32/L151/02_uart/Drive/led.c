#include "led.h"

void led_init(enum led_id id){
	GPIO_InitTypeDef GPIO_InitStreuct;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
	GPIO_InitStreuct.GPIO_Pin=id;
	GPIO_InitStreuct.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_InitStreuct.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStreuct.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_InitStreuct.GPIO_Speed=GPIO_Speed_40MHz;
	GPIO_Init(GPIOA,&GPIO_InitStreuct);
}
void led_set(enum led_id id,bool value){
    (value)? ((GPIOA->BSRRH)=id) : ((GPIOA->BSRRL)=id);
}