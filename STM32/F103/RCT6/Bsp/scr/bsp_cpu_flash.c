#include "bsp_cpu_flash.h"

/**
 * @brief 擦除Flash页面
 *
 * @param _Addr 要擦除的Flash页面的起始地址
 */
void CPU_Flash_ErasePage(uint32_t _Addr)
{
    FLASH_Unlock(); // 解锁Flash

    // 在Flash页面擦除之前，必须禁止全局中断
    __disable_irq();

    FLASH_ErasePage(_Addr); // 擦除页面

    // 擦除完成后，重新使能全局中断
    __enable_irq();

    FLASH_Lock(); // 锁定Flash
}

/**
 * @brief 将数据写入Flash，256bit写入
 *
 * @param _Addr Flash起始地址
 * @param _pbuf 指向包含要写入数据的缓冲区的指针
 * @param _len 要写入的32位数据的个数(8*32)
 */
void CPU_Flash_Write(uint32_t _Addr, uint32_t *_pbuf, uint32_t _len)
{
    uint32_t i;
    FLASH_Unlock(); // 解锁Flash

    for (i = 0; i < _len; i++)
    {
        FLASH_ProgramWord(_Addr, _pbuf[i]); // 逐个写入32位数据
        _Addr += 4;                         // 指针偏移4字节
    }

    FLASH_Lock(); // 锁定Flash
}

/**
 * @brief 从Flash读取数据到指定缓冲区
 *
 * @param _Addr Flash起始地址
 * @param _pbuf 指向存储数据的缓冲区的指针
 * @param _len 要读取的32位数据的个数
 */
void CPU_Flash_Read(uint32_t _Addr, uint32_t *_pbuf, uint32_t _len)
{
    uint32_t i;

    for (i = 0; i < _len; i++)
    {
        _pbuf[i] = *(__IO uint32_t *)_Addr; // 逐个读取32位数据
        _Addr += 4;                         // 指针偏移4字节
    }
}
