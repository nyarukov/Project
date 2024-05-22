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

void Serial_Xmodem(void)
{

    if ((Uart1.Rxbuf[1] == updata.Xmodem_NB + 1))
    {
        if (Uart1.Rxbuf[2] == (0xFF - (updata.Xmodem_NB + 1)))
        {
        }
        //     updata.Xmodem_CRC = (Uart1.Rxbuf[131] << 8) | Uart1.Rxbuf[132];
        //     if (updata.Xmodem_CRC == CRC_Check(&Uart1.Rxbuf[3], 128))
        //     {
        //         memcpy(&updata.UpDataBuf[updata.Xmodem_NB * 128], &Uart1.Rxbuf[3], 128);
        //         updata.Xmodem_NB++;
        //         memset(&Uart1.Rxbuf,0,1024);
        //         printf("\x06");
        //     }else{
        //         // Uart1.RXFlag = 1;
        //         memset(&Uart1.Rxbuf,0,1024);
        //         printf("72 ���ݲ��԰�\r\n");
        //     }
        // }else{
        //     memset(&Uart1.Rxbuf,0,1024);
        //     printf("75 ���ݲ��԰�\r\n");
    }
}
// if (updata.Xmodem_NB == 7)
// {
//     uint16_t W25;
//     W25 = W25Qxx_Write(0x10000, updata.UpDataBuf, 1024);
//     printf("д��ҳ:%d,��������:%d", W25 & 0xFF, (W25 >> 8) & 0xFF);
//     updata.W25Qxx_BlokNB++;
//     updata.Xmodem_NB = 0;
//     memset(&updata.UpDataBuf, 0, 1024);
// }

void IAP_EraseApp(void)
{
    printf("����APP\r\n");
    // ʵ�� IAP_EraseApp ����ľ������
}
void IAP_DownFirmware(void)
{
    // ʵ�� IAP_DownFirmware ����ľ������
    printf("���ع̼�\r\n");
    updata.Fir_Flag = 1;

    while (1)
    {
        switch (updata.Fir_Flag)
        {
        case 1:
            printf("C");
            HAL_Delay(1000);
            if (Uart1.Rxbuf[0] == XModem_SOH)
            {
                updata.Fir_Flag = 2;
            }
            break;
        case 2:
            if ((Uart1.Rxbuf[1] == (updata.Xmodem_NB + 1)) && (Uart1.Rxbuf[2] == (0xFF - (updata.Xmodem_NB + 1))))
            {
                updata.Xmodem_CRC = (Uart1.Rxbuf[131] << 8) | Uart1.Rxbuf[132];
                if (updata.Xmodem_CRC == CRC_Check(&Uart1.Rxbuf[3], 128))
                {
                    memcpy(&updata.UpDataBuf[updata.Xmodem_NB * 128], &Uart1.Rxbuf[3], 128);
                    updata.Xmodem_NB++;
                    updata.Fir_Flag = 5;
                }
                // else
                // {
                //     updata.Fir_Flag = 6;
                // }
            }
            break;
        case 5:
            Uart1.RxCnt = 0;
            memset(&Uart1.Rxbuf, 0, 1024);
            printf("\x06");
            updata.Fir_Flag = 1;
            break;
        case 6:
            printf("\x15");
            break;
        }
    }
}

void IAP_LoadFirmware(void)
{
    // ʵ�� IPA_CMD_LoadFirmware ����ľ������
    printf("���ع̼�\r\n");
}
void IAP_ShowVersion(void)
{
    // ʵ�� IAP_ShowVersion ����ľ������
    printf("���ع̼�\r\n");
}

void IAP_WriteVersion(void)
{
    // ʵ�� IAP_WriteVersion ����ľ������
    printf("�鿴�汾��\r\n");
}

void IAP_SystemReset(void)
{
    // ʵ�� IAP_SystemReset ����ľ������
    printf("����\r\n");
    NVIC_SystemReset();
}
void IAP_Exit(void)
{
    // ʵ�� IAP_Exit ����ľ������
    printf("�˳�\r\n");
    Jump_Main(BOOT_A_ADDR);
}

void Ota_mode(void)
{
    uint8_t Wait_Timne = 30;
    while (Wait_Timne--)
    {
        if (strcmp((char *)Uart1.Rxbuf, "OTA") == 0)
        {
            printf("ע��IAP����\r\n");
            Command_t IAP_List[] = {
                {"����APP", IAP_EraseApp},
                {"���ع̼�", IAP_DownFirmware},
                {"���ع̼�", IAP_LoadFirmware},
                {"�鿴�汾��", IAP_ShowVersion},
                {"�޸İ汾��", IAP_WriteVersion},
                {"����", IAP_SystemReset},
                {"�˳�", IAP_Exit}};
            Register_Cmds(IAP_List, ARRAY_SIZE(IAP_List));
            return;
        }
        HAL_Delay(100);
    }
    printf("��ʱ,Jump_Main\r\n");
    Jump_Main(BOOT_A_ADDR);
}
void Start_Boot(void)
{
    W25Qxx_Init();
    // otaflag.OTA_Flag = OTA_UPDATA;
    // W25qxx_WriteOTAFlag();
    W25Qxx_ReadOTAFlag();
    printf("OTA_Flag: %#X\r\n", otaflag.OTA_Flag);

    if (otaflag.OTA_Flag == OTA_UPDATA)
    {
        printf("����OTAģʽ\r\n");
        IAP_DownFirmware();
        // Ota_mode();
    }
    else
    {
        printf("����Jump_Main\r\n");
        Jump_Main(BOOT_A_ADDR);
    }
}
