#include "bsp_hard_spi.h"

#define Hard_SPI_PORT                GPIOA
#define Hard_SPI_CS_Pin              GPIO_PIN_4
#define Hard_SPI_SCLK_Pin            GPIO_PIN_5
#define Hard_SPI_MISO_Pin            GPIO_PIN_6
#define Hard_SPI_MOSI_Pin            GPIO_PIN_7

SPI_HandleTypeDef hSPI ;

void Hard_SPI_Init(void)
{

    hSPI.Instance = SPI1;
    hSPI.Init.Mode = SPI_MODE_MASTER;
    hSPI.Init.Direction = SPI_DIRECTION_2LINES;
    hSPI.Init.DataSize = SPI_DATASIZE_8BIT;
    hSPI.Init.CLKPolarity = SPI_POLARITY_LOW;
    hSPI.Init.CLKPhase = SPI_PHASE_1EDGE;
    hSPI.Init.NSS = SPI_NSS_SOFT;
    hSPI.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;    //200MHZ  200/2=100MHZ  
    hSPI.Init.FirstBit = SPI_FIRSTBIT_MSB;
    hSPI.Init.TIMode = SPI_TIMODE_DISABLE;
    hSPI.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
    hSPI.Init.CRCPolynomial = 7;
    hSPI.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
    hSPI.Init.NSSPolarity = SPI_NSS_POLARITY_LOW;
    hSPI.Init.FifoThreshold = SPI_FIFO_THRESHOLD_01DATA;
    hSPI.Init.MasterKeepIOState = SPI_MASTER_KEEP_IO_STATE_ENABLE;

    if (HAL_SPI_Init(&hSPI) != HAL_OK)
    {
        Error_Handler(__FILE__, __LINE__);
    }
    //__HAL_SPI_ENABLE(&hSPI);
}

void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi)
{

    RCC_PeriphCLKInitTypeDef SPI_PerClk;
    GPIO_InitTypeDef hSPI_Struct;

    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_SPI1_CLK_ENABLE();

    SPI_PerClk.PeriphClockSelection = RCC_PERIPHCLK_SPI1;
    SPI_PerClk.PLL2.PLL2M = 5;
    SPI_PerClk.PLL2.PLL2N = 160;
    SPI_PerClk.PLL2.PLL2P = 2;
    SPI_PerClk.PLL2.PLL2Q = 1;
    SPI_PerClk.PLL2.PLL2N = 16;
    SPI_PerClk.PLL2.PLL2RGE = RCC_PLL2VCIRANGE_2;
    SPI_PerClk.PLL2.PLL2VCOSEL = RCC_PLL2VCOWIDE;
    SPI_PerClk.PLL2.PLL2FRACN = 0;
    SPI_PerClk.Spi123ClockSelection = RCC_SPI123CLKSOURCE_PLL2;

    if (HAL_RCCEx_PeriphCLKConfig(&SPI_PerClk) != HAL_OK)
    {
        Error_Handler(__FILE__, __LINE__);
    }

    hSPI_Struct.Pin = Hard_SPI_CS_Pin;
    hSPI_Struct.Mode = GPIO_MODE_OUTPUT_PP;
    hSPI_Struct.Pull = GPIO_PULLUP;
    hSPI_Struct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(Hard_SPI_PORT, &hSPI_Struct);
    __GPIO_SET_BIT(Hard_SPI_PORT,4);

    hSPI_Struct.Pin = Hard_SPI_SCLK_Pin | Hard_SPI_MISO_Pin | Hard_SPI_MOSI_Pin;
    hSPI_Struct.Mode = GPIO_MODE_AF_PP;
    hSPI_Struct.Alternate = GPIO_AF5_SPI1;
    HAL_GPIO_Init(Hard_SPI_PORT, &hSPI_Struct);
}

void Hard_SPI_Transmit(uint8_t _pBuffer)
{
    if(HAL_SPI_Transmit(&hSPI, &_pBuffer, 1, 1000)!=HAL_OK){
        Error_Handler(__FILE__, __LINE__);
    }
}
uint8_t Hard_SPI_Reveice(void)
{
    uint8_t RxBuffer;
    if(HAL_SPI_Receive(&hSPI, &RxBuffer, 1, 1000)!=HAL_OK){
        Error_Handler(__FILE__, __LINE__);
    }
    return RxBuffer;
}
uint8_t Hard_SPI_TransmitReceive(uint8_t _pWBuffer)
{
    uint8_t RxBuffer;
    if(HAL_SPI_TransmitReceive(&hSPI, &_pWBuffer, &RxBuffer, 1, 1000)!=HAL_OK){
        Error_Handler(__FILE__, __LINE__);
    }
    return RxBuffer;
    
}

void Hard_SPI_Test(void){
    uint8_t wbuf=0xAA;
    uint8_t rbuf;
    __GPIO_RESET_BIT(GPIOA,4);
    rbuf=Hard_SPI_TransmitReceive(wbuf);
    __GPIO_SET_BIT(GPIOA,4);
    printf("rbuf:%#X\r\n",rbuf);
}