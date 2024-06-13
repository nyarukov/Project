#include "bsp_uart.h"

UART_HandleTypeDef huart1;
RX_TCB Uart1 = {0};

void Serial_Init(void)
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
    HAL_UART_Receive_IT(&huart1, &(Uart1.RxbufArr), 1);
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
        HAL_NVIC_SetPriority(USART1_IRQn, 0, 1);
        NVIC_EnableIRQ(USART1_IRQn);
    }

}

static void Serial_SendChar(uint8_t ch)
{
    while (!__HAL_UART_GET_FLAG(&huart1, UART_FLAG_TC))
        ;
    huart1.Instance->TDR = ch;
    while (!__HAL_UART_GET_FLAG(&huart1, UART_FLAG_TXE))
        ;
}
static uint8_t Serial_ReceiveChar(void)
{
    while (!__HAL_UART_GET_FLAG(&huart1, UART_FLAG_RXNE))
        ;
    return huart1.Instance->RDR;
}
int fputc(int ch, FILE *f)
{
    Serial_SendChar(ch);
    return ch;
}
int fgetc(FILE *f)
{
    return Serial_ReceiveChar();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (Uart1.RxCnt > 512)
    {
        Uart1.RxCnt = 0;
        memset(Uart1.Rxbuf, 0, sizeof(Uart1.Rxbuf));
        //printf("数据缓冲区溢出\r\n");
    }
    else
    {
        Uart1.Rxbuf[Uart1.RxCnt++] = Uart1.RxbufArr;
        if ((Uart1.Rxbuf[Uart1.RxCnt - 1] == 0x0A) && (Uart1.Rxbuf[Uart1.RxCnt - 2] == 0x0D))
        {
            Uart1.RXFlag = 1;
        }
        if (Uart1.RXFlag != 0)
        {
            //printf("%s", Uart1.Rxbuf);
            memset(Uart1.Rxbuf, 0, sizeof(Uart1.Rxbuf));
            Uart1.RXFlag = 0;
            Uart1.RxCnt = 0;
        }
    }
    HAL_UART_Receive_IT(&huart1, &(Uart1.RxbufArr), 1);
}

