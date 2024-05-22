#include "bsp_hard_i2c.h"

#define I2C_PORT            GPIOB

#define I2C_SCL_Pin         GPIO_PIN_10
#define I2C_SDA_Pin         GPIO_PIN_11

#define I2C_HOST_ADDRE      0x1A
I2C_HandleTypeDef hI2C;


/**
 * @brief 初始化硬件I2C
 */
void Hard_I2C_Init(void)
{
    hI2C.Instance=I2C2;
    hI2C.Init.Timing=0x60201E2B;
    hI2C.Init.OwnAddress1=0;
    hI2C.Init.AddressingMode=I2C_ADDRESSINGMODE_7BIT;
    hI2C.Init.DualAddressMode=I2C_DUALADDRESS_DISABLE;
    hI2C.Init.OwnAddress2=0;
    hI2C.Init.OwnAddress2Masks=I2C_OA2_NOMASK;
    hI2C.Init.GeneralCallMode=I2C_GENERALCALL_DISABLE;
    hI2C.Init.NoStretchMode=I2C_NOSTRETCH_DISABLE;
    
    if(HAL_I2C_Init(&hI2C)!=HAL_OK){
        Error_Handler(__FILE__, __LINE__);
    }

    if(HAL_I2CEx_AnalogFilter_Config(&hI2C,I2C_ANALOGFILTER_ENABLE)!=HAL_OK){
        Error_Handler(__FILE__, __LINE__);
    }
}

void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c){
    RCC_PeriphCLKInitTypeDef I2C_Per={0};
    GPIO_InitTypeDef hI2C_Struct={0};

    __HAL_RCC_I2C2_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();

    I2C_Per.PeriphClockSelection=RCC_PERIPHCLK_I2C2;
    I2C_Per.I2c123ClockSelection=RCC_I2C123CLKSOURCE_D2PCLK1;   //120MHZ
    if(HAL_RCCEx_PeriphCLKConfig(&I2C_Per)!=HAL_OK){
        Error_Handler(__FILE__,__LINE__);
    }

    hI2C_Struct.Pin = I2C_SCL_Pin | I2C_SDA_Pin;
    hI2C_Struct.Mode = GPIO_MODE_OUTPUT_OD;
    hI2C_Struct.Pull = GPIO_NOPULL;
    hI2C_Struct.Speed = GPIO_SPEED_FREQ_HIGH;
    hI2C_Struct.Alternate=GPIO_AF4_I2C2;
    HAL_GPIO_Init(I2C_PORT, &hI2C_Struct);
}