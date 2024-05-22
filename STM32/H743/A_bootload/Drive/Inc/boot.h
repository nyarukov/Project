#ifndef __BOOT_H
#define __BOOT_H

#include "stm32h7xx_hal.h"
#include "main.h"
#include "bsp_cmd.h"

#define SRAM_ADDRT      (0x24000000UL)
#define SRAM_SIZE       (0x80000UL)

#define BOOT_B_ADDR     (0x08000000UL)
#define BOOT_B_SIZE     (0x20000UL)
#define BOOT_A_ADDR     (BOOT_B_ADDR+BOOT_B_SIZE)


#define OTA_UPDATA      (0xCD0989AFUL)
#define OTA_SIZE        (sizeof(OTAFlag))

#define XModem_SOH      ((uint8_t)0x01)         /* 128字节数据包开始 */
#define XModem_EOT      ((uint8_t)0x04)         /* 传输结束 */
#define XModem_ACK      ((uint8_t)0x06)         /* 应答 */
#define XModem_NAK      ((uint8_t)0x15)         /* 不应答 */



typedef void (*Load)(void);

typedef struct 
{
    uint32_t OTA_Flag;
    uint32_t OTA_Version;
    uint32_t FileLed[11];
}OTAFlag;

typedef struct 
{
    uint8_t UpDataBuf[1024];
    uint32_t W25Qxx_BlokNB;
    
}UPData;

extern OTAFlag otaflag;
extern UPData updata;

void Start_Boot(void);

#endif // !__BOOT_H
