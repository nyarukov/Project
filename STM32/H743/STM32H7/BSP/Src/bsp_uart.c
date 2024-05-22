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

UART_HandleTypeDef huart[COM_MAX] = {0};
RingBuffer_t buffer[COM_MAX] = {0};

uint8_t RingBuffer_Write(RingBuffer_t *_buffer, uint8_t *_pData,uint16_t _len)
{   
    if ((_buffer->lenght >= BUFFER_SIZE)||(_pData==NULL))
    {
        return 1;
    }
    while (_len--)
    {
        _buffer->buffer[_buffer->write] = *_pData++;;
        _buffer->write = (_buffer->write +1) % BUFFER_SIZE;
        _buffer->lenght++;
    }
    return 0;
}

uint8_t RingBuffer_Read(RingBuffer_t *_buffer, uint8_t *_pData,uint16_t _len)
{
    if ((_buffer->lenght==NULL)||(_buffer->buffer==NULL))
    {
        return 1;
    }
    while (_len--)
    {
        *_pData++ = _buffer->buffer[_buffer->read];
        _buffer->read = (_buffer->read +1) % BUFFER_SIZE;
        _buffer->lenght--;
    }
    return 0;
}

uint8_t IsRingBufferEmpty(RingBuffer_t *_buffer){
    return (_buffer->read==_buffer->write)?1:0;
}

void Com_Init(COM_ID _Com, uint32_t _BaudRaet)
{
    switch (_Com)
    {
    case COM1:
        huart[COM1].Instance = USART1;
        break;
    case COM2:
        huart[COM2].Instance = USART2;
        break;
    case COM3:
        huart[COM3].Instance = USART3;
        break;
    case COM4:
        huart[COM4].Instance = UART4;
        break;
    case COM5:
        huart[COM5].Instance = UART5;
        break;
    case COM6:
        huart[COM6].Instance = USART6;
        break;
    case COM7:
        huart[COM7].Instance = UART7;
        break;
    case COM8:
        huart[COM8].Instance = UART8;
        break;
    }
    huart[_Com].Init.BaudRate = _BaudRaet;
    huart[_Com].Init.WordLength = UART_WORDLENGTH_8B;
    huart[_Com].Init.StopBits = UART_STOPBITS_1;
    huart[_Com].Init.Parity = UART_PARITY_NONE;
    huart[_Com].Init.Mode = UART_MODE_TX_RX;
    huart[_Com].Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart[_Com].Init.OverSampling = UART_OVERSAMPLING_16;
    huart[_Com].Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
    huart[_Com].Init.ClockPrescaler = UART_PRESCALER_DIV1;
    huart[_Com].AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
    HAL_UART_Init(&huart[_Com]);

    __HAL_UART_ENABLE_IT(&huart[_Com],UART_IT_RXNE);
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
    RCC_PeriphCLKInitTypeDef Uart_RCC_PeriphCLKInit;
    GPIO_InitTypeDef Uart_GPIO_Init;

    if (huart->Instance == USART1)
    {
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
        HAL_NVIC_SetPriority(USART1_IRQn,0,5);
        HAL_NVIC_EnableIRQ(USART1_IRQn);
    }
    else if (huart->Instance == USART2)
    {
        Uart_RCC_PeriphCLKInit.PeriphClockSelection = RCC_PERIPHCLK_USART2;
        Uart_RCC_PeriphCLKInit.Usart234578ClockSelection = RCC_USART234578CLKSOURCE_PCLK1;
        HAL_RCCEx_PeriphCLKConfig(&Uart_RCC_PeriphCLKInit);

        __HAL_RCC_GPIOA_CLK_ENABLE();
        __HAL_RCC_USART2_CLK_ENABLE();

        Uart_GPIO_Init.Pin = GPIO_PIN_2 | GPIO_PIN_3;
        Uart_GPIO_Init.Mode = GPIO_MODE_AF_PP;
        Uart_GPIO_Init.Pull = GPIO_NOPULL;
        Uart_GPIO_Init.Speed = GPIO_SPEED_FREQ_LOW;
        Uart_GPIO_Init.Alternate = GPIO_AF7_USART2;
        HAL_GPIO_Init(GPIOA, &Uart_GPIO_Init);
        HAL_NVIC_SetPriority(USART2_IRQn,0,5);
        HAL_NVIC_EnableIRQ(USART2_IRQn);
    }
}

void Com_SendChar(COM_ID _Com, uint8_t ch)
{
    while (!__HAL_UART_GET_FLAG(&huart[_Com], UART_FLAG_TC));
    huart[_Com].Instance->TDR = ch;
    while (!__HAL_UART_GET_FLAG(&huart[_Com], UART_FLAG_TXE));
}
uint8_t Com_ReceiveChar(COM_ID _Com)
{
    while (!__HAL_UART_GET_FLAG(&huart[_Com], UART_FLAG_RXNE));
    return huart[_Com].Instance->RDR;
}

void Com_SendArr(COM_ID _Com, uint8_t *_Arr, uint16_t _Len)
{
    uint8_t i;
    for (i = 0; i < _Len; i++)
    {
        Com_SendChar(_Com, _Arr[i]);
    }
}

void Com_printf(COM_ID _Com, char *fmt, ...)
{
    uint8_t tempbuff[128];
    uint16_t i;
    __va_list ap;        // 使用标准的va_list类型
    __va_start(ap, fmt); // 使用标准的va_start宏
    vsprintf((char *)tempbuff, fmt, ap);
    __va_end(ap); // 使用标准的va_end宏

    for (i = 0; i < str_len((char *)tempbuff); i++)
    {
        Com_SendChar(_Com, tempbuff[i]); // 发送格式化后的字符
    }
}

void USART1_IRQHandler(void){
    if(__HAL_UART_GET_FLAG(&huart[COM1],UART_FLAG_RXNE)){
        __HAL_UART_CLEAR_FLAG(&huart[COM1],UART_FLAG_RXNE);
        uint8_t receivechar=Com_ReceiveChar(COM1);
        RingBuffer_Write(&buffer[COM1],&receivechar,1);
    }
}
void USART2_IRQHandler(void){
    if(__HAL_UART_GET_FLAG(&huart[COM2],UART_FLAG_RXNE)){
        __HAL_UART_CLEAR_FLAG(&huart[COM2],UART_FLAG_RXNE);
        uint8_t receivechar=Com_ReceiveChar(COM2);
        RingBuffer_Write(&buffer[COM2],&receivechar,1);
    }
}

