#include "stm32l1xx.h"
#include "led.h"
#include "key.h"
void uart_config(void);
void serila_char(uint8_t c);
/*	sclk	pa5
		sda		pa7
		res		pb1
		dc		pb0
		cs		pa4
		scl		pb10
		sda		pb11
*/
int main(void){
	uart_config();
	led_init(led_g);
	key_init(key_up);
	serila_char('A');
	while(1){
		
		if(key_read(key_up)){
			led_set(led_g,false);
		}else{
			led_set(led_g,true);
		}
	}
}
void uart_config(void){
    GPIO_InitTypeDef GPIO_InitStructe;
    USART_InitTypeDef UART_InitStructe;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);

    GPIO_InitStructe.GPIO_Pin=GPIO_Pin_9;
    GPIO_InitStructe.GPIO_Mode=GPIO_Mode_AF;
    GPIO_InitStructe.GPIO_OType=GPIO_OType_PP;
    GPIO_InitStructe.GPIO_PuPd=GPIO_PuPd_UP;
    GPIO_InitStructe.GPIO_Speed=GPIO_Speed_40MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructe);
    GPIO_InitStructe.GPIO_Pin=GPIO_Pin_10;
    GPIO_InitStructe.GPIO_Mode=GPIO_Mode_AIN;
    GPIO_InitStructe.GPIO_OType=GPIO_OType_OD;
    GPIO_InitStructe.GPIO_PuPd=GPIO_PuPd_NOPULL;
    GPIO_InitStructe.GPIO_Speed=GPIO_Speed_40MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructe);

    UART_InitStructe.USART_BaudRate=115200;
    UART_InitStructe.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
    UART_InitStructe.USART_Mode=USART_Mode_Rx | USART_Mode_Tx;
    UART_InitStructe.USART_Parity=USART_Parity_No;
    UART_InitStructe.USART_StopBits=USART_StopBits_1;
    UART_InitStructe.USART_WordLength=USART_WordLength_8b;
    USART_Init(USART1,&UART_InitStructe);
		USART_Cmd(USART1,ENABLE);
}
void serila_char(uint8_t c){
    (USART1->SR);
    USART1->DR=c;
}