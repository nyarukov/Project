#ifndef __W25Q32_H
#define __W25Q32_H

#include "common.h"
#include "myspi.h"

#define W25Q64_WRITE_ENABLE                         0x06
#define W25Q64_WRITE_DISABLE                        0x04
#define W25Q64_READ_STATUS_REGISTER_1               0x05
#define W25Q64_READ_STATUS_REGISTER_2               0x35
#define W25Q64_WRITE_STATUS_REGISTER                0x01
#define W25Q64_PAGE_PROGRAM                         0x02
#define W25Q64_QUAD_PAGE_PROGRAM                    0x32
#define W25Q64_BLOCK_ERASE_64KB                     0xD8
#define W25Q64_BLOCK_ERASE_32KB                     0x52
#define W25Q64_SECTOR_ERASE_4KB                     0x20
#define W25Q64_CHIP_ERASE                           0xC7
#define W25Q64_ERASE_SUSPEND                        0x75
#define W25Q64_ERASE_RESUME                         0x7A
#define W25Q64_POWER_DOWN                           0xB9
#define W25Q64_HIGH_PERFORMANCE_MODE                0xA3
#define W25Q64_CONTINUOUS_READ_MODE_RESET           0xFF
#define W25Q64_RELEASE_POWER_DOWN_HPM_DEVICE_ID     0xAB
#define W25Q64_MANUFACTURER_DEVICE_ID               0x90
#define W25Q64_READ_UNIQUE_ID                       0x4B
#define W25Q64_JEDEC_ID                             0x9F
#define W25Q64_READ_DATA                            0x03
#define W25Q64_FAST_READ                            0x0B
#define W25Q64_FAST_READ_DUAL_OUTPUT                0x3B
#define W25Q64_FAST_READ_DUAL_IO                    0xBB
#define W25Q64_FAST_READ_QUAD_OUTPUT                0x6B
#define W25Q64_FAST_READ_QUAD_IO                    0xEB
#define W25Q64_OCTAL_WORD_READ_QUAD_IO              0xE3

#define W25Q64_DUMMY_BYTE                           0xFF

typedef enum{
    W25Q80 = 0x4014,
    W25Q16 = 0x4015,
    W25Q32 = 0x4016,
    W25Q64 = 0x4017,
}W25Q64_DeviceID;

typedef enum{
    ERASE_4KB=W25Q64_SECTOR_ERASE_4KB,
    ERASE_32KB=W25Q64_BLOCK_ERASE_32KB,
    ERASE_64KB=W25Q64_BLOCK_ERASE_64KB,
    ERASE_Chip=W25Q64_CHIP_ERASE,
}W25Q64_ERASE_Size;

void W25Q32_Init(void);
uint16_t W25Q32_ReadID(void);
void W25Q32_Enable(void);
void W25Q32_Disable(void);
void W25Q32_State(void);
void W25Q32_PageProgram(uint32_t Address,uint8_t *DataArr,uint16_t length);
void W25Q32_SectorErase(uint32_t Address,W25Q64_ERASE_Size Size);
void W25Q32_ReadData(uint32_t Address,uint8_t *DataArr,uint32_t length);


#endif