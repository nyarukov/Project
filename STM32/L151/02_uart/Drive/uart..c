#include "uart.h"

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
}
void serila_char(uint8_t c){
    (USART1->SR);
    USART1->DR=c;
}
