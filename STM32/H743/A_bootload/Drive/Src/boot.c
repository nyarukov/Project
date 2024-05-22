#include "boot.h"

Load loadA;

OTAFlag otaflag;
UPData updata;

__asm void Set_MSP(uint32_t _Addr)
{
    MSR MSP, r0
                 BX r14
}

void BootClear(void)
{
    __HAL_RCC_USART1_CLK_DISABLE();
    __HAL_RCC_SPI1_CLK_DISABLE();
    __HAL_RCC_GPIOA_CLK_DISABLE();
    __HAL_RCC_GPIOC_CLK_DISABLE();
    __HAL_RCC_GPIOH_CLK_DISABLE();
}

void Jump_Main(uint32_t _Addr)
{
    if ((*(uint32_t *)_Addr >= SRAM_ADDRT) && *(uint32_t *)_Addr < (SRAM_ADDRT + SRAM_SIZE))
    {
        Set_MSP(*(uint32_t *)_Addr);
        loadA = (Load) * (uint32_t *)(_Addr + 4);
        BootClear();
        loadA();
    }
}


uint16_t CRC_Check(uint8_t *_crc, uint16_t _len)
{
    uint8_t i;
    uint16_t CrcInit = 0x0000;
    uint16_t CrcPdly = 0x1021;

    while (_len--)
    {
        CrcInit = (*_crc << 8) ^ CrcInit;
        for (i = 0; i < 8; i++)
        {
            if (CrcInit & 0x8000)
                CrcInit = (CrcInit << 1) ^ CrcPdly;
            else
                CrcInit = (CrcInit << 1);
        }
        _crc++;
    }
    return CrcInit;
}

void IAP_CMD_EraseApp(void)
{
    // 实现 IAP_CMD_EraseApp 命令的具体操作
}
void IAP_CMD_DownFirmware(void)
{
    // 实现 IAP_CMD_DownFirmware 命令的具体操作
}

void IAP_CMD_ShowVersion(void)
{
    // 实现 IAP_CMD_ShowVersion 命令的具体操作
}

void IAP_CMD_WriteVersion(void)
{
    // 实现 IAP_CMD_WriteVersion 命令的具体操作
}

void IAP_CMD_SystemReset(void)
{
    // 实现 IAP_CMD_SystemReset 命令的具体操作
}
void IAP_CMD_Exit(void)
{
    // 实现 IAP_CMD_Exit 命令的具体操作
}

void Ota_mode(void)
{
    uint8_t Wait_Timne;
    while (Wait_Timne++ < 30)
    {
        if (strcmp((char *)Uart1.Rxbuf, "OTA") == 0)
        {

            Command_t IAP_List[] = {
                {"擦除APP", IAP_CMD_EraseApp},
                {"下载固件", IAP_CMD_DownFirmware},
                {"加载固件", IAP_CMD_ShowVersion},
                {"查看版本号", IAP_CMD_WriteVersion},
                {"修改版本号", IAP_CMD_WriteVersion},
                {"重启", IAP_CMD_SystemReset},
                {"退出", IAP_CMD_Exit}};
            Register_Cmds(IAP_List, ARRAY_SIZE(IAP_List));
            return;
        }
        printf("%d\r\n",Wait_Timne);
        HAL_Delay(100);
    }
}
void Start_Boot(void)
{
    W25Qxx_Init();
    otaflag.OTA_Flag = OTA_UPDATA;
    W25Qxx_ReadOTAFlag();
    printf("OTA_Flag: %#X\r\n",otaflag.OTA_Flag);
    
    if (otaflag.OTA_Flag == OTA_UPDATA)
    {
        printf("进入OTA模式\r\n");
        Ota_mode();
    }
    else
    {
        printf("进入OTA模式\r\n");
        Jump_Main(BOOT_A_ADDR);
    }
}
