/*
 * 项目名称: uart
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-01
 * 最后修改日期: 2024-06-01 18:09:50
 * 描述: UART驱动
 */

#include "uart.h"
//  C 文件内容...

#if (UART_COUNT > 0)

#define UART_WAIT_FOR_TX_COMPLETE(_Id) while (!(COM_OF(_Id).Port->SR & (1 << 7)))

#define UART_WAIT_FOR_TX_EMPTY(_Id) while (!(COM_OF(_Id).Port->SR & (1 << 6)))

#define INIT_CONFIG(PORT, BAUD,                       \
                    TX, RX, RS,                       \
                    DATA, STOP, PARITY,               \
                    TX_BUFFER, TX_BUF_SIZE,           \
                    RX_BUFFER, RX_BUF_SIZE,           \
                    CALLBACK)                         \
    {                                                 \
        .Port = PORT, .Buad = BAUD,                   \
        .Tx_IO = TX, .Rx_IO = RX, .Rs_IO = RS,        \
        .Data = DATA, .Stop = STOP, .Parity = PARITY, \
        .TxBuf = {.Buf = TX_BUFFER,                   \
                  .BufSize = TX_BUF_SIZE,             \
                  .Write = 0,                         \
                  .Read = 0,                          \
                  .Count = 0},                        \
        .RxBuf = {.Buf = RX_BUFFER,                   \
                  .BufSize = RX_BUF_SIZE,             \
                  .Write = 0,                         \
                  .Read = 0,                          \
                  .Count = 0},                        \
        .Callback = CALLBACK,                         \
    }

#define INIT_LOG_UART(UARTX, MSG)      \
    if (UARTX##_EN == 1)               \
    {                                  \
        _LOG("--> " MSG "\r\n", NULL); \
    }

#if UART1_EN == 1
uint8_t UART1_TX_BUFFER[UART1_TX_BUF_SIZE];
uint8_t UART1_RX_BUFFER[UART1_RX_BUF_SIZE];
#endif

#if UART2_EN == 1
uint8_t UART2_TX_BUFFER[UART2_TX_BUF_SIZE];
uint8_t UART2_RX_BUFFER[UART2_RX_BUF_SIZE];
#endif

#if UART3_EN == 1
uint8_t UART3_TX_BUFFER[UART3_TX_BUF_SIZE];
uint8_t UART3_RX_BUFFER[UART3_RX_BUF_SIZE];
#endif

#if UART4_EN == 1
uint8_t UART4_TX_BUFFER[UART4_TX_BUF_SIZE];
uint8_t UART4_RX_BUFFER[UART4_RX_BUF_SIZE];
#endif

#if UART5_EN == 1
uint8_t UART5_TX_BUFFER[UART5_TX_BUF_SIZE];
uint8_t UART5_RX_BUFFER[UART5_RX_BUF_SIZE];
#endif

#if UART6_EN == 1
uint8_t UART6_TX_BUFFER[UART6_TX_BUF_SIZE];
uint8_t UART6_RX_BUFFER[UART6_RX_BUF_SIZE];
#endif

#if UART7_EN == 1
uint8_t UART7_TX_BUFFER[UART7_TX_BUF_SIZE];
uint8_t UART7_RX_BUFFER[UART7_RX_BUF_SIZE];
#endif

#if UART8_EN == 1
uint8_t UART8_TX_BUFFER[UART8_TX_BUF_SIZE];
uint8_t UART8_RX_BUFFER[UART8_RX_BUF_SIZE];
#endif
// clang-format off

// clang-format on
struct COM_Config Com_Config[UART_COUNT] = {

#if UART1_EN == 1
    INIT_CONFIG(USART1, UART1_BAUD,
                UART1_TX, UART1_RX, UART1_RS,
                UART1_DATA, UART1_STOP, UART1_PARITY,
                UART1_TX_BUFFER, UART1_TX_BUF_SIZE,
                UART1_RX_BUFFER, UART1_RX_BUF_SIZE,
                COM1_Proc),
#endif

#if UART2_EN == 1
    INIT_CONFIG(USART2, UART2_BAUD,
                UART2_TX, UART2_RX, UART2_RS,
                UART2_DATA, UART2_STOP, UART2_PARITY,
                UART2_TX_BUFFER, UART2_TX_BUF_SIZE,
                UART2_RX_BUFFER, UART2_RX_BUF_SIZE,
                COM2_Proc),
#endif

#if UART3_EN == 1
    INIT_CONFIG(USART3, UART3_BAUD,
                UART3_TX, UART3_RX, UART3_RS,
                UART3_DATA, UART3_STOP, UART3_PARITY,
                UART3_TX_BUFFER, UART3_TX_BUF_SIZE,
                UART3_RX_BUFFER, UART3_RX_BUF_SIZE),
#endif

#if UART4_EN == 1
    INIT_CONFIG(UART4, UART4_BAUD,
                UART4_TX, UART4_RX, UART4_RS,
                UART4_DATA, UART4_STOP, UART4_PARITY,
                UART4_TX_BUFFER, UART4_TX_BUF_SIZE,
                UART4_RX_BUFFER, UART4_RX_BUF_SIZE),
#endif

#if UART5_EN == 1
    INIT_CONFIG(UART5, UART5_BAUD,
                UART5_TX, UART5_RX, UART5_RS,
                UART5_DATA, UART5_STOP, UART5_PARITY,
                UART5_TX_BUFFER, UART5_TX_BUF_SIZE,
                UART5_RX_BUFFER, UART5_RX_BUF_SIZE),
#endif

#if UART6_EN == 1
    INIT_CONFIG(USART6, UART6_BAUD,
                UART6_TX, UART6_RX, UART6_RS,
                UART6_DATA, UART6_STOP, UART6_PARITY,
                UART6_TX_BUFFER, UART6_TX_BUF_SIZE,
                UART6_RX_BUFFER, UART6_RX_BUF_SIZE),
#endif

#if UART7_EN == 1
    INIT_CONFIG(UART7, UART7_BAUD,
                UART7_TX, UART7_RX, UART7_RS,
                UART7_DATA, UART7_STOP, UART7_PARITY,
                UART7_TX_BUFFER, UART7_TX_BUF_SIZE,
                UART7_RX_BUFFER, UART7_RX_BUF_SIZE),
#endif

#if UART8_EN == 1
    INIT_CONFIG(UART8, UART8_BAUD,
                UART8_TX, UART8_RX, UART8_RS,
                UART8_DATA, UART8_STOP, UART8_PARITY,
                UART8_TX_BUFFER, UART8_TX_BUF_SIZE,
                UART8_RX_BUFFER, UART8_RX_BUF_SIZE),
#endif

};

static void UART_Init(COM_Config *_Para)
{
    USART_InitTypeDef USARTx_Config;
    NVIC_InitTypeDef NVIC_InitStructure;
    USART_TypeDef *Uartx = _Para->Port;

    IO_Init(_Para->Tx_IO, GPIO_Mode_AF, GPIO_OType_PP,
            GPIO_PuPd_UP, GPIO_Speed_50MHz);
    IO_Init(_Para->Rx_IO, GPIO_Mode_AF, GPIO_OType_PP,
            GPIO_PuPd_UP, GPIO_Speed_50MHz);

    if (_Para->Rs_IO != UART_RS485_IO_NO)
    {
        IO_Init(_Para->Rs_IO, GPIO_Mode_OUT,
                GPIO_OType_PP, GPIO_PuPd_UP, GPIO_Speed_50MHz);
    }

    GPIO_TypeDef *GPIO_Tx_IO = (GPIO_TypeDef *)GET_PORT(_Para->Tx_IO);
    GPIO_TypeDef *GPIO_Rx_IO = (GPIO_TypeDef *)GET_PORT(_Para->Rx_IO);
    uint8_t Tx_Pin = _Para->Tx_IO & 0x0F;
    uint8_t Rx_Pin = _Para->Rx_IO & 0x0F;

#if UART1_EN == 1
    if (Uartx == USART1)
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
        NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;

        if (UART1_REUSE != UART_REUSE_NO)
        {
            __IO_WRITE_AFR(GPIO_Tx_IO, Tx_Pin, UART1_REUSE);
            __IO_WRITE_AFR(GPIO_Rx_IO, Rx_Pin, UART1_REUSE);
        }
    }
#endif

#if UART2_EN == 1
    else if (Uartx == USART2)
    {
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
        NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;

        if (UART2_REUSE != UART_REUSE_NO)
        {
            __IO_WRITE_AFR(GPIO_Tx_IO, Tx_Pin, UART2_REUSE);
            __IO_WRITE_AFR(GPIO_Rx_IO, Rx_Pin, UART2_REUSE);
        }
    }
#endif

#if UART3_EN == 1
    else if (Uartx == USART3)
    {
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
        NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;

        if (UART3_REUSE != UART_REUSE_NO)
        {
            __IO_WRITE_AFR(GPIO_Tx_IO, Tx_Pin, UART3_REUSE);
            __IO_WRITE_AFR(GPIO_Rx_IO, Rx_Pin, UART3_REUSE);
        }
    }
#endif

#if UART4_EN == 1
    else if (Uartx == UART4)
    {
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);
        NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;

        if (UART4_REUSE != UART_REUSE_NO)
        {
            __IO_WRITE_AFR(GPIO_Tx_IO, Tx_Pin, UART4_REUSE);
            __IO_WRITE_AFR(GPIO_Rx_IO, Rx_Pin, UART4_REUSE);
        }
    }
#endif

#if UART5_EN == 1
    else if (Uartx == UART5)
    {
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5, ENABLE);
        NVIC_InitStructure.NVIC_IRQChannel = UART5_IRQn;

        if (UART5_REUSE != UART_REUSE_NO)
        {
            __IO_WRITE_AFR(GPIO_Tx_IO, Tx_Pin, UART5_REUSE);
            __IO_WRITE_AFR(GPIO_Rx_IO, Rx_Pin, UART5_REUSE);
        }
    }

#endif

#if UART6_EN == 1
    else if (Uartx == USART6)
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6, ENABLE);
        NVIC_InitStructure.NVIC_IRQChannel = USART6_IRQn;

        if (UART6_REUSE != UART_REUSE_NO)
        {
            __IO_WRITE_AFR(GPIO_Tx_IO, Tx_Pin, UART6_REUSE);
            __IO_WRITE_AFR(GPIO_Rx_IO, Rx_Pin, UART6_REUSE);
        }
    }

#endif

#if UART7_EN == 1
    else if (Uartx == UART7)
    {
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART7, ENABLE);

        if (UART7_REUSE != UART_REUSE_NO)
        {
            __IO_WRITE_AFR(GPIO_Tx_IO, Tx_Pin, UART7_REUSE);
            __IO_WRITE_AFR(GPIO_Rx_IO, Rx_Pin, UART7_REUSE);
        }
    }

#endif

#if UART8_EN == 1
    else if (Uartx == UART8)
    {
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART8, ENABLE);
        NVIC_InitStructure.NVIC_IRQChannel = UART8_IRQn;

        if (UART8_REUSE != UART_REUSE_NO)
        {
            __IO_WRITE_AFR(GPIO_Tx_IO, Tx_Pin, UART8_REUSE);
            __IO_WRITE_AFR(GPIO_Rx_IO, Rx_Pin, UART8_REUSE);
        }
    }
#endif

    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

    USARTx_Config.USART_BaudRate = _Para->Buad;
    USARTx_Config.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    /***************************************************************/
    if (_Para->Data == 0)
    {
        USARTx_Config.USART_WordLength = USART_WordLength_8b;
    }
    else if (_Para->Data == 1)
    {
        USARTx_Config.USART_WordLength = USART_WordLength_9b;
    }
    /***************************************************************/
    if (_Para->Stop == 0)
    {
        USARTx_Config.USART_StopBits = USART_StopBits_1;
    }
    else if (_Para->Stop == 1)
    {
        USARTx_Config.USART_StopBits = USART_StopBits_2;
    }
    /***************************************************************/
    if (_Para->Parity == 0)
    {
        USARTx_Config.USART_Parity = USART_Parity_No;
    }
    else if (_Para->Parity == 1)
    {
        USARTx_Config.USART_Parity = USART_Parity_Odd;
    }
    else if (_Para->Parity == 2)
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

void Init_Com(void)
{

    for (uint8_t i = 0; i < UART_COUNT; i++)
    {
        UART_Init(&COM_OF(i));
    }
    _LOG("\r\n", NULL);
    INIT_LOG_UART(UART1, "COM1_Init")
    INIT_LOG_UART(UART2, "COM2_Init")
    INIT_LOG_UART(UART3, "COM3_Init")
    INIT_LOG_UART(UART4, "COM4_Init")
    INIT_LOG_UART(UART5, "COM5_Init")
    INIT_LOG_UART(UART6, "COM6_Init")
    INIT_LOG_UART(UART7, "COM7_Init")
    INIT_LOG_UART(UART8, "COM8_Init")
}

void Rs_485(COM_ID _Id, uint8_t Status)
{
    IO_Write(COM_OF(_Id).Rs_IO, Status);
}

Status Uart_SendData(COM_ID _Id, uint8_t *_pBuf, uint32_t _Len)
{
    Status flag;
    DISABLE_INT();
    flag = Buffer_Write_Byte(&COM_OF(_Id).TxBuf, _pBuf, _Len);
    ENABLE_INT();
    USART_ITConfig(COM_OF(_Id).Port, USART_IT_TXE, ENABLE);
    return flag;
}

void Uart_Sendch(COM_ID _Id, uint8_t ch)
{
    UART_WAIT_FOR_TX_COMPLETE(_Id);
    COM_OF(_Id).Port->DR = ch;
    UART_WAIT_FOR_TX_EMPTY(_Id);
}

void Uart_SendNextByte(COM_ID _Id)
{
    uint8_t t_data;
    if (Buffer_Read_Byte(&COM_OF(_Id).TxBuf, &t_data, 1) == BF_SUCCESS)
    {
        COM_OF(_Id).Port->DR = t_data;
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
    uint32_t size;
    USART_TypeDef *USARTx = COM_OF(_Id).Port;

    if (USART_GetITStatus(USARTx, USART_IT_RXNE) != RESET)
    {
        uint8_t r_data = USART_ReceiveData(USARTx);

        if (Buffer_Write_Byte(&COM_OF(_Id).RxBuf, &r_data, 1) == BF_FULL)

        {
            _ERR_LOG;
        }
        USART_ITConfig(USARTx, USART_IT_IDLE, ENABLE);
    }

    if (USART_GetITStatus(USARTx, USART_IT_IDLE) != RESET)
    {
        USART_ClearFlag(USARTx, USART_IT_IDLE);
        USART_ITConfig(USARTx, USART_IT_IDLE, DISABLE);
        COM_OF(_Id).Callback(COM_OF(_Id).RxBuf.Buf, COM_OF(_Id).RxBuf.Count);
    }

    if (USART_GetITStatus(USARTx, USART_IT_TXE) != RESET)
    {
        if (COM_OF(_Id).Rs_IO != UART_RS485_IO_NO)
        {
            Rs_485(_Id, 1);
        }
        USART_ClearITPendingBit(USARTx, USART_IT_TXE);

        if (Buffer_Get_Written_Count(&COM_OF(_Id).TxBuf, &size) == BF_SUCCESS)
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
        if (Buffer_Get_Written_Count(&COM_OF(_Id).TxBuf, &size) == BF_SUCCESS)
        {
            if (size == 0)
            {
                USART_ITConfig(USARTx, USART_IT_TXE, DISABLE);
                USART_ITConfig(USARTx, USART_IT_TC, ENABLE);
                if (COM_OF(_Id).Rs_IO != UART_RS485_IO_NO)
                {
                    Rs_485(_Id, 0);
                }
            }
            else
            {
                Uart_SendNextByte(_Id);
            }
        }
    }
}

#define UART_IRQ_HANDLER(ID, USART_IRQ_FUNC) \
    void USART_IRQ_FUNC(void)                \
    {                                        \
        Uart_Proc(ID);                       \
    }

#if UART1_EN == 1
UART_IRQ_HANDLER(COM1, USART1_IRQHandler)
#endif

#if UART2_EN == 1
UART_IRQ_HANDLER(COM2, USART2_IRQHandler)
#endif

#if UART3_EN == 1
UART_IRQ_HANDLER(COM3, USART3_IRQHandler)
#endif

#if UART4_EN == 1
UART_IRQ_HANDLER(COM4, UART4_IRQHandler)
#endif

#if UART5_EN == 1
UART_IRQ_HANDLER(COM5, UART5_IRQHandler)
#endif

#if UART6_EN == 1
UART_IRQ_HANDLER(COM6, USART6_IRQHandler)
#endif

#if UART7_EN == 1
UART_IRQ_HANDLER(COM7, UART7_IRQHandler)
#endif

#if UART8_EN == 1
UART_IRQ_HANDLER(COM8, UART8_IRQHandler)
#endif

#endif // !UART_COUNT
