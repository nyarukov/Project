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
    // ʵ�� IAP_CMD_EraseApp ����ľ������
}
void IAP_CMD_DownFirmware(void)
{
    // ʵ�� IAP_CMD_DownFirmware ����ľ������
}

void IAP_CMD_ShowVersion(void)
{
    // ʵ�� IAP_CMD_ShowVersion ����ľ������
}

void IAP_CMD_WriteVersion(void)
{
    // ʵ�� IAP_CMD_WriteVersion ����ľ������
}

void IAP_CMD_SystemReset(void)
{
    // ʵ�� IAP_CMD_SystemReset ����ľ������
}
void IAP_CMD_Exit(void)
{
    // ʵ�� IAP_CMD_Exit ����ľ������
}

void Ota_mode(void)
{
    uint8_t Wait_Timne;
    while (Wait_Timne++ < 30)
    {
        if (strcmp((char *)Uart1.Rxbuf, "OTA") == 0)
        {

            Command_t IAP_List[] = {
                {"����APP", IAP_CMD_EraseApp},
                {"���ع̼�", IAP_CMD_DownFirmware},
                {"���ع̼�", IAP_CMD_ShowVersion},
                {"�鿴�汾��", IAP_CMD_WriteVersion},
                {"�޸İ汾��", IAP_CMD_WriteVersion},
                {"����", IAP_CMD_SystemReset},
                {"�˳�", IAP_CMD_Exit}};
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
        printf("����OTAģʽ\r\n");
        Ota_mode();
    }
    else
    {
        printf("����OTAģʽ\r\n");
        Jump_Main(BOOT_A_ADDR);
    }
}
