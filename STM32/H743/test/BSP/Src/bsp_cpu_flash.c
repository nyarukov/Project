#include "bsp_cpu_flash.h"

static uint8_t CPU_FLASH_GetSeccotr(uint32_t _Addr);

/**
 * @brief 擦除Flash扇区
 * 
 * @param _Addr Flash起始地址
 */
void CPU_Flash_EraseSector(uint32_t _Addr){
    
    if((_Addr<ADDR_FLASH_START) || (_Addr>ADDR_FLASH_END)){
        Error_Handler(__FILE__,__LINE__);
    }
	FLASH_EraseInitTypeDef EraseInitStruct={0};
	uint32_t SectorError=0;

	HAL_FLASH_Unlock();
	
	EraseInitStruct.TypeErase=FLASH_TYPEERASE_SECTORS;
	EraseInitStruct.VoltageRange=FLASH_VOLTAGE_RANGE_3;
	if(_Addr >=ADDR_FLASH_SECTOR_0_BANK2){
		EraseInitStruct.Banks=FLASH_BANK_2;
	}else
	{
		EraseInitStruct.Banks=FLASH_BANK_1;
	}
	EraseInitStruct.Sector=CPU_FLASH_GetSeccotr(_Addr);
	EraseInitStruct.NbSectors=1;

	if(HAL_FLASHEx_Erase(&EraseInitStruct,&SectorError)!=HAL_OK){
		Error_Handler(__FILE__,__LINE__);
	}
	HAL_FLASH_Lock();
    if(_Addr >=ADDR_FLASH_SECTOR_0_BANK2){
        FLASH_WaitForLastOperation(50000,FLASH_BANK_2);
	}else
	{
        FLASH_WaitForLastOperation(50000,FLASH_BANK_1);
	}
    
}

/**
 * @brief 将数据写入Flash ,256bit写入
 * 
 * @param _Addr Flash起始地址
 * @param _pbuf 指向包含要写入数据的缓冲区的指针
 * @param _len 要写入的32位数据的个数(8*32)
 */
void CPU_Flash_Write(uint32_t _Addr, uint32_t *_pbuf,uint32_t _len){
    if((_Addr<ADDR_FLASH_START) || (_Addr>ADDR_FLASH_END)){
        Error_Handler(__FILE__,__LINE__);
    }

	HAL_FLASH_Unlock();
    uint32_t *buffer=NULL;
    uint16_t i;
    for ( i = 0; i < _len; i++)
    {
        buffer=&_pbuf[i*8];
        if(HAL_FLASH_Program(FLASH_TYPEPROGRAM_FLASHWORD,_Addr,(uint32_t)buffer)!=HAL_OK){
            Error_Handler(__FILE__,__LINE__);
        }
        _Addr+=32;
    }
	HAL_FLASH_Lock();
    if(_Addr >=ADDR_FLASH_SECTOR_0_BANK2){
        FLASH_WaitForLastOperation(50000,FLASH_BANK_2);
	}else
	{
        FLASH_WaitForLastOperation(50000,FLASH_BANK_1);
	}
}

/**
 * @brief 从Flash读取数据到指定缓冲区
 * 
 * @param _Addr Flash起始地址
 * @param _pbuf 指向存储数据的缓冲区的指针
 * @param _len 要读取的32位数据的个数
 */
void CPU_Flash_Read(uint32_t _Addr, uint32_t *_pbuf,uint32_t _len){
    if((_Addr<ADDR_FLASH_START) || (_Addr>ADDR_FLASH_END)){
        Error_Handler(__FILE__,__LINE__);
    }

    uint16_t i;
    for ( i = 0; i < _len; i++)
    {
        _pbuf[i]= *(uint32_t*)(_Addr+(i*4));
    }
}

/**
 * @brief 获取指定Flash地址所在的扇区号
 * 
 * @param _Addr Flash地址
 * @return uint8_t 扇区号
 */
static uint8_t CPU_FLASH_GetSeccotr(uint32_t _Addr)
{
    if (((_Addr >= ADDR_FLASH_SECTOR_0_BANK1) && (_Addr < ADDR_FLASH_SECTOR_1_BANK1)) ||
        ((_Addr >= ADDR_FLASH_SECTOR_0_BANK2) && (_Addr < ADDR_FLASH_SECTOR_1_BANK2)))
    {
        return 0;
    }
    else if (((_Addr >= ADDR_FLASH_SECTOR_1_BANK1) && (_Addr < ADDR_FLASH_SECTOR_2_BANK1)) ||
            ((_Addr >= ADDR_FLASH_SECTOR_1_BANK2) && (_Addr < ADDR_FLASH_SECTOR_2_BANK2)))
    {
        return 1;
    }
    else if (((_Addr >= ADDR_FLASH_SECTOR_2_BANK1) && (_Addr < ADDR_FLASH_SECTOR_3_BANK1)) ||
            ((_Addr >= ADDR_FLASH_SECTOR_2_BANK2) && (_Addr < ADDR_FLASH_SECTOR_3_BANK2)))
    {
        return 2;
    }
    else if (((_Addr >= ADDR_FLASH_SECTOR_3_BANK1) && (_Addr < ADDR_FLASH_SECTOR_4_BANK1)) ||
            ((_Addr >= ADDR_FLASH_SECTOR_3_BANK2) && (_Addr < ADDR_FLASH_SECTOR_4_BANK2)))
    {
        return 3;
    }
    else if (((_Addr >= ADDR_FLASH_SECTOR_4_BANK1) && (_Addr < ADDR_FLASH_SECTOR_5_BANK1)) ||
            ((_Addr >= ADDR_FLASH_SECTOR_4_BANK2) && (_Addr < ADDR_FLASH_SECTOR_5_BANK2)))
    {
        return 4;
    }
    else if (((_Addr >= ADDR_FLASH_SECTOR_5_BANK1) && (_Addr < ADDR_FLASH_SECTOR_6_BANK1)) ||
            ((_Addr >= ADDR_FLASH_SECTOR_5_BANK2) && (_Addr < ADDR_FLASH_SECTOR_6_BANK2)))
    {
        return 5;
    }
    else if (((_Addr >= ADDR_FLASH_SECTOR_6_BANK1) && (_Addr < ADDR_FLASH_SECTOR_7_BANK1)) ||
            ((_Addr >= ADDR_FLASH_SECTOR_6_BANK2) && (_Addr < ADDR_FLASH_SECTOR_7_BANK2)))
    {
        return 6;
    }
    else if (((_Addr >= ADDR_FLASH_SECTOR_7_BANK1) && (_Addr < (ADDR_FLASH_SECTOR_7_BANK1 + ADDR_FLASH_SECTOR_SIZE))) ||
            ((_Addr >= ADDR_FLASH_SECTOR_7_BANK2) && (_Addr < (ADDR_FLASH_SECTOR_7_BANK2 + ADDR_FLASH_SECTOR_SIZE))))
    {
        return 7;
    }else{
		return 10;
	}
}
