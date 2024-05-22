#include "bsp_ft5426.h"

bsp_ft5426_dev ft5426_dev;

void FT5426_IOInit(void)
{
    GPIO_InitTypeDef FT5426Struct;
    __HAL_RCC_GPIOE_CLK_ENABLE();
    FT5426Struct.Pin = GPIO_PIN_4;
    FT5426Struct.Mode = GPIO_MODE_IT_FALLING;
    FT5426Struct.Pull = GPIO_NOPULL;
    FT5426Struct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOE, &FT5426Struct);

    HAL_NVIC_SetPriority(EXTI4_IRQn, 4, 0);
    HAL_NVIC_EnableIRQ(EXTI4_IRQn);

    // FT5426Struct.Pin = 1 << FT5426_RST;
    // HAL_GPIO_Init(GPIOH, &FT5426Struct);
}

void FT5426_Init(void)
{
    u8 id[2];

    SoftIIC_Init();

    FT5426_IOInit();

    FT5426_Reads(FT5426_IDGLIB_VERSION1, id, 2);
    ft5426_dev.ID = (id[0] << 8) | id[1];

    FT5426_Send(FT5426_DEVICE_MODE, 0);
    FT5426_Send(FT5426_IDG_MODE, 1);

    // __GPIO_RESET_BIT(GPIOH, FT5426_RST);
    // delay(50);
    // __GPIO_SET_BIT(GPIOH, FT5426_RST);
}

static u8 ft5426_Pointx[30];

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == GPIO_PIN_4)
    {
        u8 i;
        ft5426_dev.Pointx = FT5426_Read(FT5426_TD_STATUS);
        for (i = 0; i < ft5426_dev.Pointx; i++)
        {
            FT5426_Reads(FT5426_TOUCH1_XH, ft5426_Pointx, ft5426_dev.Pointx * 6);
            
            ft5426_dev.XPoint[i] = ((ft5426_Pointx[(i * 6) + 2] << 8) | ft5426_Pointx[(i * 6) + 3]) & 0xFFF;
            ft5426_dev.YPoint[i] = ((ft5426_Pointx[i * 6] << 8) | ft5426_Pointx[(i * 6) + 1]) & 0xFFF;
           
            ft5426_dev.Event[i] = (ft5426_Pointx[i * 6] >> 6) & 0xFF;
            
        }
    }
}

void FT5426_Send(uint8_t RegAddress, uint8_t Data)
{

    SoftIIC_Start();
    SoftIIC_SendByte(FT5426_CMD_WR);
    SoftIIC_ReceiveACK();
    SoftIIC_SendByte(RegAddress);
    SoftIIC_ReceiveACK();
    SoftIIC_SendByte(Data);
    SoftIIC_ReceiveACK();
    SoftIIC_Stop();
}

uint8_t FT5426_Read(uint8_t RegAddress)
{

    uint8_t RegData;
    SoftIIC_Start();
    SoftIIC_SendByte(FT5426_CMD_WR);
    SoftIIC_ReceiveACK();
    SoftIIC_SendByte(RegAddress);
    SoftIIC_ReceiveACK();
    SoftIIC_Start();
    SoftIIC_SendByte(FT5426_CMD_RD);
    SoftIIC_ReceiveACK();
    RegData = SoftIIC_ReceiveByte();
    SoftIIC_SendACK(1);
    SoftIIC_Stop();
    return RegData;
}

void FT5426_Reads(uint8_t RegAddress, uint8_t *pData, u8 len)
{

    SoftIIC_Start();
    SoftIIC_SendByte(FT5426_CMD_WR);
    SoftIIC_ReceiveACK();
    SoftIIC_SendByte(RegAddress);
    SoftIIC_ReceiveACK();
    SoftIIC_Start();
    SoftIIC_SendByte(FT5426_CMD_RD);
    SoftIIC_ReceiveACK();
    SoftIIC_ReceiveBytes(pData, len);
    SoftIIC_Stop();
}