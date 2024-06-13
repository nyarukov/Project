#include "bsp_uart.h"

/*
Baud rate	Bit rate	 Bit time	 Character time	  3.5 character times
  2400	    2400 bits/s	  417 us	      4.6 ms	      16 ms
  4800	    4800 bits/s	  208 us	      2.3 ms	      8.0 ms
  9600	    9600 bits/s	  104 us	      1.2 ms	      4.0 ms
 19200	   19200 bits/s    52 us	      573 us	      2.0 ms
 38400	   38400 bits/s	   26 us	      286 us	      1.75 ms(1.0 ms)
 115200	   115200 bit/s	  8.7 us	       95 us	      1.75 ms(0.33 ms) 后面固定都为1750us
*/


UART_HandleTypeDef huart1;
UART_TCB Uart1 = {0};

void Uart_Init(void)
{
    huart1.Instance = USART1;
    huart1.Init.BaudRate = 115200;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.Mode = UART_MODE_TX_RX;
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;
    huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
    huart1.Init.ClockPrescaler = UART_PRESCALER_DIV1;
    huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
    HAL_UART_Init(&huart1);
    HAL_UART_Receive_IT(&huart1, &(Uart1.bufArr), 1);
    
    
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
    RCC_PeriphCLKInitTypeDef Uart_RCC_PeriphCLKInit;
    GPIO_InitTypeDef Uart_GPIO_Init;

    if(huart->Instance==USART1){
        Uart_RCC_PeriphCLKInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
        Uart_RCC_PeriphCLKInit.Usart16ClockSelection = RCC_USART16CLKSOURCE_D2PCLK2;
        HAL_RCCEx_PeriphCLKConfig(&Uart_RCC_PeriphCLKInit);

        __HAL_RCC_GPIOA_CLK_ENABLE();
        __HAL_RCC_USART1_CLK_ENABLE();

        Uart_GPIO_Init.Pin = GPIO_PIN_9 | GPIO_PIN_10;
        Uart_GPIO_Init.Mode = GPIO_MODE_AF_PP;
        Uart_GPIO_Init.Pull = GPIO_NOPULL;
        Uart_GPIO_Init.Speed = GPIO_SPEED_FREQ_LOW;
        Uart_GPIO_Init.Alternate = GPIO_AF7_USART1;
        HAL_GPIO_Init(GPIOA, &Uart_GPIO_Init);
        HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
        NVIC_EnableIRQ(USART1_IRQn);
    }

}

void USART1_IRQHandler(void){
    HAL_UART_IRQHandler(&huart1);
}

void Uart_SendChar(uint8_t ch)
{
    while (!__HAL_UART_GET_FLAG(&huart1, UART_FLAG_TC))
        ;
    huart1.Instance->TDR = ch;
    while (!__HAL_UART_GET_FLAG(&huart1, UART_FLAG_TXE))
        ;
}
uint8_t Uart_ReceiveChar(void)
{
    while (!__HAL_UART_GET_FLAG(&huart1, UART_FLAG_RXNE))
        ;
    return huart1.Instance->RDR;
}

void Uart_SendArr(uint8_t *_Arr,uint16_t _Len){
    uint8_t i;
    for ( i = 0; i < _Len; i++)
    {
        Uart_SendChar(_Arr[i]);
    }
    
}

void u1_printf(char *fmt, ...) {
    uint8_t tempbuff[256];
    uint16_t i;
    __va_list ap; // 使用标准的va_list类型
    __va_start(ap, fmt); // 使用标准的va_start宏
    vsprintf((char*)tempbuff, fmt, ap);
    __va_end(ap); // 使用标准的va_end宏

    for (i = 0; i < str_len((char*)tempbuff); i++) {
        Uart_SendChar(tempbuff[i]); // 发送格式化后的字符
    }
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (Uart1.Cnt > 512)
    {
        Uart1.Cnt = 0;
    }
    else
    {
        Uart1.buffer[Uart1.Cnt++] = Uart1.bufArr;
        __HAL_TIM_CLEAR_FLAG(&tim6_struct,TIM_FLAG_UPDATE);
        HAL_TIM_Base_Start_IT(&tim6_struct);
    }
    HAL_UART_Receive_IT(&huart1, &(Uart1.bufArr), 1);
}

