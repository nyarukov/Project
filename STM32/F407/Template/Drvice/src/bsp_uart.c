#include "bsp_uart.h"

User_Functions user_functions = {NULL};

#if (UART_COUNT > 0)
// 串口发送函数优化
#define UART_WAIT_FOR_TX_COMPLETE() while (!(Config[_Id].Para.Port->SR & (1 << 7)))
#define UART_WAIT_FOR_TX_EMPTY() while (!(Config[_Id].Para.Port->SR & (1 << 6)))

typedef struct
{
    USART_TypeDef *Port;
    uint8_t Tx_IO;
    uint8_t Rx_IO;
    uint8_t Rs_IO;
    uint8_t Data;
    uint8_t Stop;
    uint8_t Parity;
    uint32_t Buad;
    void (*Rs_Ctl)(uint8_t Statu);
} Uart_Para;

typedef struct
{
    Uart_Para Para;
    Buffer_t TxBuf;
    Buffer_t RxBuf;
} Uart_Config;

#if UART1_EN == 1
static uint8_t UART1_TX_BUFFER[UART1_TX_BUF_SIZE];
static uint8_t UART1_RX_BUFFER[UART1_RX_BUF_SIZE];
#endif

#if UART2_EN == 1
static uint8_t UART2_TX_BUFFER[UART2_TX_BUF_SIZE];
static uint8_t UART2_RX_BUFFER[UART2_RX_BUF_SIZE];
#endif

#if UART3_EN == 1
static uint8_t UART3_TX_BUFFER[UART3_TX_BUF_SIZE];
static uint8_t UART3_RX_BUFFER[UART3_RX_BUF_SIZE];
#endif

#if UART4_EN == 1
static uint8_t UART4_TX_BUFFER[UART4_TX_BUF_SIZE];
static uint8_t UART4_RX_BUFFER[UART4_RX_BUF_SIZE];
#endif

#if UART5_EN == 1
static uint8_t UART5_TX_BUFFER[UART5_TX_BUF_SIZE];
static uint8_t UART5_RX_BUFFER[UART5_RX_BUF_SIZE];
#endif

#if UART6_EN == 1
static uint8_t UART6_TX_BUFFER[UART6_TX_BUF_SIZE];
static uint8_t UART6_RX_BUFFER[UART6_RX_BUF_SIZE];
#endif

#if UART7_EN == 1
static uint8_t UART7_TX_BUFFER[UART7_TX_BUF_SIZE];
static uint8_t UART7_RX_BUFFER[UART7_RX_BUF_SIZE];
#endif

#if UART8_EN == 1
static uint8_t UART8_TX_BUFFER[UART8_TX_BUF_SIZE];
static uint8_t UART8_RX_BUFFER[UART8_RX_BUF_SIZE];
#endif

static Uart_Config Config[UART_COUNT] = {
#if UART1_EN == 1
    {{USART1, UART1_TX, UART1_RX, UART1_RS, UART1_DATA, UART1_STOP, UART1_PARITY, UART1_BAUD},
     {UART1_TX_BUFFER, UART1_TX_BUF_SIZE, NULL, NULL, NULL},
     {UART1_RX_BUFFER, UART1_RX_BUF_SIZE, NULL, NULL, NULL}},
#endif
#if UART2_EN == 1
    {{USART2, UART2_TX, UART2_RX, UART2_RS, UART2_DATA, UART2_STOP, UART2_PARITY, UART2_BAUD},
     {UART2_TX_BUFFER, UART2_TX_BUF_SIZE, NULL, NULL, NULL},
     {UART2_RX_BUFFER, UART2_RX_BUF_SIZE, NULL, NULL, NULL}},
#endif
#if UART3_EN == 1
    {{USART3, UART3_TX, UART3_RX, UART3_RS, UART3_DATA, UART3_STOP, UART3_PARITY, UART3_BAUD},
     {UART3_TX_BUFFER, UART3_TX_BUF_SIZE, NULL, NULL, NULL},
     {UART3_RX_BUFFER, UART3_RX_BUF_SIZE, NULL, NULL, NULL}},
#endif
#if UART4_EN == 1
    {{UART4, UART4_TX, UART4_RX, UART4_RS, UART4_DATA, UART4_STOP, UART4_PARITY, UART4_BAUD},
     {UART4_TX_BUFFER, UART4_TX_BUF_SIZE, NULL, NULL, NULL},
     {UART4_RX_BUFFER, UART4_RX_BUF_SIZE, NULL, NULL, NULL}},
#endif
#if UART5_EN == 1
    {{UART5, UART5_TX, UART5_RX, UART5_RS, UART5_DATA, UART5_STOP, UART5_PARITY, UART5_BAUD},
     {UART5_TX_BUFFER, UART5_TX_BUF_SIZE, NULL, NULL, NULL},
     {UART5_RX_BUFFER, UART5_RX_BUF_SIZE, NULL, NULL, NULL}},
#endif
#if UART6_EN == 1
    {{USART6, UART6_TX, UART6_RX, UART6_RS, UART6_DATA, UART6_STOP, UART6_PARITY, UART6_BAUD},
     {UART6_TX_BUFFER, UART6_TX_BUF_SIZE, NULL, NULL, NULL},
     {UART6_RX_BUFFER, UART6_RX_BUF_SIZE, NULL, NULL, NULL}},
#endif
#if UART7_EN == 1
    {{UART7, UART7_TX, UART7_RX, UART7_RS, UART7_DATA, UART7_STOP, UART7_PARITY, UART7_BAUD},
     {UART7_TX_BUFFER, UART7_TX_BUF_SIZE, NULL, NULL, NULL},
     {UART7_RX_BUFFER, UART7_RX_BUF_SIZE, NULL, NULL, NULL}},
#endif
#if UART8_EN == 1
    {{UART8, UART8_TX, UART8_RX, UART8_RS, UART8_DATA, UART8_STOP, UART8_PARITY, UART8_BAUD},
     {UART8_TX_BUFFER, UART8_TX_BUF_SIZE, NULL, NULL, NULL},
     {UART8_RX_BUFFER, UART8_RX_BUF_SIZE, NULL, NULL, NULL}},
#endif
};

static void Uart_config(Uart_Config *Para)
{
    USART_InitTypeDef USARTx_Config;
    NVIC_InitTypeDef NVIC_InitStructure;
    USART_TypeDef *Uartx = Para->Para.Port;

    if (Uartx == USART1)
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
        NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    }
    else if (Uartx == USART2)
    {
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
        NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
    }
    else if (Uartx == USART3)
    {
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
        NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
    }
    else if (Uartx == UART4)
    {
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);
        NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;
    }
    else if (Uartx == UART5)
    {
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5, ENABLE);
        NVIC_InitStructure.NVIC_IRQChannel = UART5_IRQn;
    }
    else if (Uartx == USART6)
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6, ENABLE);
        NVIC_InitStructure.NVIC_IRQChannel = USART6_IRQn;
    }
    else if (Uartx == UART7)
    {
        // RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART7, ENABLE);
        // NVIC_InitStructure.NVIC_IRQChannel = UART7_IRQn;
    }
    else if (Uartx == UART8)
    {
        // RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART8, ENABLE);
        // NVIC_InitStructure.NVIC_IRQChannel = UART8_IRQn;
    }
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

    IO_Init(Para->Para.Tx_IO, GPIO_Mode_AF, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_Speed_50MHz);
    IO_Init(Para->Para.Rx_IO, GPIO_Mode_AF, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_Speed_50MHz);

    if (Para->Para.Rs_IO != UART_RS485_IO_NO)
    {
        IO_Init(Para->Para.Rs_IO, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_Speed_50MHz);
    }

    GPIO_TypeDef *GPIO_Tx_IO = (GPIO_TypeDef *)GET_PORT(Para->Para.Tx_IO);
    GPIO_TypeDef *GPIO_Rx_IO = (GPIO_TypeDef *)GET_PORT(Para->Para.Rx_IO);
    uint8_t Tx_Pin = Para->Para.Tx_IO & 0x0F;
    uint8_t Rx_Pin = Para->Para.Rx_IO & 0x0F;

    __IO_WRITE_AFR(GPIO_Tx_IO, Tx_Pin, GPIO_AF_USART1);
    __IO_WRITE_AFR(GPIO_Rx_IO, Rx_Pin, GPIO_AF_USART1);

    USARTx_Config.USART_BaudRate = Para->Para.Buad;
    USARTx_Config.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    /***************************************************************/
    if (Para->Para.Data == 8)
    {
        USARTx_Config.USART_WordLength = USART_WordLength_8b;
    }
    else if (Para->Para.Data == 9)
    {
        USARTx_Config.USART_WordLength = USART_WordLength_9b;
    }
    /***************************************************************/
    if (Para->Para.Stop == 1)
    {
        USARTx_Config.USART_StopBits = USART_StopBits_1;
    }
    else if (Para->Para.Stop == 2)
    {
        USARTx_Config.USART_StopBits = USART_StopBits_2;
    }
    /***************************************************************/
    if (Para->Para.Parity == 0)
    {
        USARTx_Config.USART_Parity = USART_Parity_No;
    }
    else if (Para->Para.Parity == 1)
    {
        USARTx_Config.USART_Parity = USART_Parity_Odd;
    }
    else if (Para->Para.Parity == 2)
    {
        USARTx_Config.USART_Parity = USART_Parity_Even;
    }
    /***************************************************************/
    USARTx_Config.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_Init(Uartx, &USARTx_Config);

    USART_Cmd(Uartx, ENABLE);

    USART_ITConfig(Uartx, USART_IT_RXNE, ENABLE);

    NVIC_Init(&NVIC_InitStructure);
}

void Uart_Init(void)
{
#if UART1_EN == 1
    Uart_config(&Config[COM1]);
#endif
#if UART2_EN == 1
    Uart_config(&Config[COM2]);
#endif
#if UART3_EN == 1
    Uart_config(&Config[COM3]);
#endif
#if UART4_EN == 1
    Uart_config(&Config[COM4]);
#endif
#if UART5_EN == 1
    Uart_config(&Config[COM5]);
#endif
#if UART6_EN == 1
    Uart_config(&Config[COM6]);
#endif
#if UART7_EN == 1
    Uart_config(&Config[COM7]);
#endif
#if UART8_EN == 1
    Uart_config(&Config[COM8]);
#endif
};

void Rs_485(COM_ID _Id, uint8_t Statu)
{
    IO_Wrtie(Config[_Id].Para.Rs_IO, Statu);
}

Status Uart_SendData(COM_ID _Id, uint8_t *_pBuf, uint32_t _Len)
{
    Status flag;
    DISABLE_INT();
    flag = Buffer_Operation(&Config[_Id].TxBuf, _pBuf, _Len, BUFFER_WRITE_BYTE, NULL);
    ENABLE_INT();
    USART_ITConfig(Config[_Id].Para.Port, USART_IT_TXE, ENABLE);
    return flag;
}

void Uart_Sendch(COM_ID _Id, uint8_t ch)
{
    UART_WAIT_FOR_TX_COMPLETE();
    Config[_Id].Para.Port->DR = ch;
    UART_WAIT_FOR_TX_EMPTY();
}

void Uart_SendNextByte(COM_ID _Id)
{
    uint8_t t_data;
    if (Buffer_Operation(&Config[_Id].TxBuf, &t_data, 1, BUFFER_READ_BYTE, NULL) == BF_OK)
    {
        Uart_Sendch(_Id, t_data);
    }
}

void BF_Printf(COM_ID _Id, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int len = vsnprintf(NULL, 0, format, args);
    va_end(args);

    if (len >= 0)
    {
        char *buffer = (char *)malloc(len + 1);
        if (buffer != NULL)
        {
            va_start(args, format);
            vsnprintf(buffer, len + 1, format, args);
            va_end(args);

            Uart_SendData(_Id, (uint8_t *)buffer, len);

            free(buffer);
        }
        else
        { 
        }
    }
    else
    {
    }
}

void Uart_Proc(COM_ID _Id)
{
    uint32_t size, len;
    USART_TypeDef *USARTx = Config[_Id].Para.Port;

    if (USART_GetITStatus(USARTx, USART_IT_RXNE) != RESET)
    {
        uint8_t r_data = USART_ReceiveData(USARTx);
        if (Buffer_Operation(&Config[_Id].RxBuf, &r_data, 1, BUFFER_WRITE_BYTE, NULL) == BF_FULL)
        {
            _ERR_LOG;
        }
        USART_ITConfig(USARTx, USART_IT_IDLE, ENABLE);
    }


    if (USART_GetITStatus(USARTx, USART_IT_IDLE) != RESET)
    {
        USART_ClearFlag(USARTx, USART_IT_IDLE);

        if (Buffer_Operation(&Config[_Id].RxBuf, NULL, NULL, BUFFER_WRITTEN_COUNT, &len) == BF_OK && len > 0)
        {
            USART_ITConfig(USARTx, USART_IT_IDLE, DISABLE);
            // Uart_SendData(_Id, Config[_Id].RxBuf.Buf, len);
            user_functions.Uart_Process_Function(_Id, Config[_Id].RxBuf.Buf, len);
            Buffer_Operation(&Config[_Id].RxBuf, NULL, NULL, BUFFER_CLEAR, 0);
        }
    }

    if (USART_GetITStatus(USARTx, USART_IT_TXE) != RESET)
    {
        USART_ClearITPendingBit(USARTx, USART_IT_TXE);
        if (Buffer_Operation(&Config[_Id].TxBuf, NULL, NULL, BUFFER_WRITTEN_COUNT, &size) == BF_OK)
        {
            if (size == 0)
            {
                USART_ITConfig(USARTx, USART_IT_TXE, DISABLE);
                USART_ITConfig(USARTx, USART_IT_TC, ENABLE);
            }
            else
            {
                Uart_SendNextByte(_Id);
            }
        }
    }

    if (USART_GetITStatus(USARTx, USART_IT_TC) != RESET)
    {
        USART_ClearITPendingBit(USARTx, USART_IT_TC);

        if (Buffer_Operation(&Config[_Id].TxBuf, NULL, NULL, BUFFER_WRITTEN_COUNT, &size) == BF_OK)
        {
            if (size == 0)
            {
                USART_ITConfig(USARTx, USART_IT_TXE, DISABLE);
                USART_ITConfig(USARTx, USART_IT_TC, ENABLE);
            }
            else
            {
                Uart_SendNextByte(_Id);
            }
        }
    }
}

    

#if UART1_EN == 1
void USART1_IRQHandler(void)
{
    Uart_Proc(COM1);
}
#endif

#if UART2_EN == 1
void USART2_IRQHandler(void)
{
    Uart_Proc(COM2);
}
#endif

#if UART3_EN == 1
void USART3_IRQHandler(void)
{
    Uart_Proc(COM3);
}
#endif

#if UART4_EN == 1
void UART4_IRQHandler(void)
{
    Uart_Proc(COM4);
}
#endif

#if UART5_EN == 1
void UART5_IRQHandler(void)
{
    Uart_Proc(COM5);
}
#endif

#if UART6_EN == 1
void USART6_IRQHandler(void)
{
    Uart_Proc(COM6);
}
#endif

#if UART7_EN == 1
void UART7_IRQHandler(void)
{
    Uart_Proc(COM7);
}
#endif

#if UART8_EN == 1
void UART8_IRQHandler(void)
{
    Uart_Proc(COM8);
}
#endif

#endif // !UART_COUNT
