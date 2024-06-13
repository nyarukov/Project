#include "bsp_uart.h"

/*
Baud rate	Bit rate	 Bit time	 Character time	  3.5 character times
  2400	    2400 bits/s	  417 us	      4.6 ms	      16 ms
  4800	    4800 bits/s	  208 us	      2.3 ms	      8.0 ms
  9600	    9600 bits/s	  104 us	      1.2 ms	      4.0 ms
 19200	   19200 bits/s    52 us	      573 us	      2.0 ms
 38400	   38400 bits/s	   26 us	      286 us	      1.75 ms(1.0 ms)
 115200	   115200 bit/s	  8.7 us	       95 us	      1.75 ms(0.33 ms)
*/

void USART1_Init(void)
{
    // 1. 启用 GPIOB 时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // 2. 启用串口1 时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

    // 3. 引脚重映射
    // 使用AFIO重映射功能，将串口1的引脚重映射到GPIOB
    //RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    //GPIO_PinRemapConfig(GPIO_Remap_USART1, ENABLE);

    // 4. 配置 GPIO 引脚
    GPIO_InitTypeDef GPIO_InitStruct;

    // 配置 GPIOA 9 作为 USART1_TX
    GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_9;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_AF_PP; // 复用推挽输出
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    // 配置 GPIOA 10 作为 USART1_RX
    GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_10;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING; // 浮空输入
    GPIO_Init(GPIOA, &GPIO_InitStruct);
    NVIC_InitTypeDef nvicInitStruct;
    // 5. 配置并启用串口1
    USART_InitTypeDef USART_InitStruct;

    USART_InitStruct.USART_BaudRate            = 115200;                         // 设置波特率
    USART_InitStruct.USART_WordLength          = USART_WordLength_8b;            // 设置数据位长度
    USART_InitStruct.USART_StopBits            = USART_StopBits_1;               // 设置停止位
    USART_InitStruct.USART_Parity              = USART_Parity_No;                // 设置校验位
    USART_InitStruct.USART_Mode                = USART_Mode_Rx | USART_Mode_Tx;  // 设置接收和发送模式
    USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // 禁用硬件流控制

    USART_Init(USART1, &USART_InitStruct); // 初始化串口1

    USART_Cmd(USART1, ENABLE);                     // 启用串口1
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); // 使能接收中断

    nvicInitStruct.NVIC_IRQChannel                   = USART1_IRQn;
    nvicInitStruct.NVIC_IRQChannelCmd                = ENABLE;
    nvicInitStruct.NVIC_IRQChannelPreemptionPriority = 0;
    nvicInitStruct.NVIC_IRQChannelSubPriority        = 2;
    NVIC_Init(&nvicInitStruct);
}

void USART2_Init(void)
{
    // 1. 启用 GPIOA 时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // 2. 启用串口2 时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
    NVIC_InitTypeDef nvicInitStruct;
    // 3. 配置 GPIO 引脚
    GPIO_InitTypeDef GPIO_InitStruct;

    // 配置 GPIOA 2 作为 USART2_TX
    GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_2;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_AF_PP; // 复用推挽输出
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    // 配置 GPIOA 3 作为 USART2_RX
    GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_3;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING; // 浮空输入
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    // 4. 配置并启用串口2
    USART_InitTypeDef USART_InitStruct;

    USART_InitStruct.USART_BaudRate            = 115200;                         // 设置波特率
    USART_InitStruct.USART_WordLength          = USART_WordLength_8b;            // 设置数据位长度
    USART_InitStruct.USART_StopBits            = USART_StopBits_1;               // 设置停止位
    USART_InitStruct.USART_Parity              = USART_Parity_No;                // 设置校验位
    USART_InitStruct.USART_Mode                = USART_Mode_Rx | USART_Mode_Tx;  // 设置接收和发送模式
    USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // 禁用硬件流控制

    USART_Init(USART2, &USART_InitStruct); // 初始化串口2

    USART_Cmd(USART2, ENABLE); // 启用串口2

    USART_ITConfig(USART2, USART_IT_RXNE, ENABLE); // 使能接收中断

    nvicInitStruct.NVIC_IRQChannel                   = USART2_IRQn;
    nvicInitStruct.NVIC_IRQChannelCmd                = ENABLE;
    nvicInitStruct.NVIC_IRQChannelPreemptionPriority = 0;
    nvicInitStruct.NVIC_IRQChannelSubPriority        = 0;
    NVIC_Init(&nvicInitStruct);
}

void USART3_Init(void)
{
    // 1. 启用 GPIOB 时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    // 2. 启用串口3 时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

    // 3. 配置 GPIO 引脚
    GPIO_InitTypeDef GPIO_InitStruct;

    // 配置 GPIOB 10 作为 USART3_TX
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP; // 复用推挽输出
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct);

    // 配置 GPIOB 11 作为 USART3_RX
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING; // 浮空输入
    GPIO_Init(GPIOB, &GPIO_InitStruct);

    // 4. 配置并启用串口3
    USART_InitTypeDef USART_InitStruct;

    USART_InitStruct.USART_BaudRate = 115200;                                    // 设置波特率
    USART_InitStruct.USART_WordLength = USART_WordLength_8b;                     // 设置数据位长度
    USART_InitStruct.USART_StopBits = USART_StopBits_1;                          // 设置停止位
    USART_InitStruct.USART_Parity = USART_Parity_No;                             // 设置校验位
    USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;                 // 设置接收和发送模式
    USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // 禁用硬件流控制

    USART_Init(USART3, &USART_InitStruct); // 初始化串口3

    USART_Cmd(USART3, ENABLE); // 启用串口3

    // 5. 配置中断和优先级
    NVIC_InitTypeDef nvicInitStruct;

    nvicInitStruct.NVIC_IRQChannel = USART3_IRQn;
    nvicInitStruct.NVIC_IRQChannelCmd = ENABLE;
    nvicInitStruct.NVIC_IRQChannelPreemptionPriority = 0;
    nvicInitStruct.NVIC_IRQChannelSubPriority = 0;
    NVIC_Init(&nvicInitStruct);

    USART_ITConfig(USART3, USART_IT_RXNE, ENABLE); // 使能接收中断
}


void USART1_IRQHandler(void)
{
    if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) // 接收中断
    {
        USART_ClearFlag(USART1, USART_FLAG_RXNE);
    }
}

void Usart_SendString(USART_TypeDef *USARTx, unsigned char *str, unsigned short len)
{

    unsigned short count = 0;

    for (; count < len; count++) {
        USART_SendData(USARTx, *str++);                              // 发送数据
        while (USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET); // 等待发送完成
    }
}

void UsartPrintf(USART_TypeDef *USARTx, char *fmt, ...)
{

    unsigned char UsartPrintfBuf[296];
    va_list ap;
    unsigned char *pStr = UsartPrintfBuf;

    va_start(ap, fmt);
    vsnprintf((char *)UsartPrintfBuf, sizeof(UsartPrintfBuf), fmt, ap); // 格式化
    va_end(ap);

    while (*pStr != 0) {
        USART_SendData(USARTx, *pStr++);
        while (USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET);
    }
}

void Uart_SendChar(USART_TypeDef *USARTx, uint8_t ch)
{
    // 等待传输数据寄存器空闲
    while (!(USARTx->SR & USART_FLAG_TXE));
    // 发送字符
    USARTx->DR = ch;
    // 等待传输完成
    while (!(USARTx->SR & USART_FLAG_TC));
}
