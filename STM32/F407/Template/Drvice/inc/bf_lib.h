#ifndef __BF_LIB_H
#define __BF_LIB_H

#include "bf_def.h"

#if 0
// 缓存区操作命�?
#define BUFFER_WRITE_BIT            0x00        // 以位为单位向缓存区写入数据
#define BUFFER_READ_BIT             0x01        // 以位为单位从缓存区读取数据
#define BUFFER_WRITE_BYTE           0x02        // 以字节为单位向缓存区写入数据
#define BUFFER_READ_BYTE            0x03        // 以字节为单位从缓存区读取数据
#define BUFFER_WRITE_SHORT          0x04        // 以短整型为单位向缓存区写入数据
#define BUFFER_READ_SHORT           0x05        // 以短整型为单位从缓存区读取数据
#define BUFFER_WRITE_INT            0x06        // 以整型为单位向缓存区写入数据
#define BUFFER_READ_INT             0x07        // 以整型为单位从缓存区读取数据
#define BUFFER_WRITE_LONG           0x08        // 以长整型为单位向缓存区写入数据
#define BUFFER_READ_LONG            0x09        // 以长整型为单位从缓存区读取数据

#define BUFFER_SET_SIZE             0x0A        // 设置缓存区大小
#define BUFFER_SET_ADDRESS          0x0B        // 设置缓存区地址

#define BUFFER_CLEAR                0x0C        // 清空缓存区
#define BUFFER_TOTAL_SIZE           0x0D        // 获取缓存区的总大小
#define BUFFER_READ_POINTER         0x0E        // 获取缓存区的读指针位置
#define BUFFER_WRITE_POINTER        0x0F        // 获取缓存区的写指针位置
#define BUFFER_SPACE_LEFT           0x10        // 获取缓存区中剩余空间的大小
#else
typedef enum
{
    BUFFER_WRITE_BIT,           // 以位为单位向缓存区写入数据
    BUFFER_READ_BIT,            // 以位为单位从缓存区读取数据
    BUFFER_WRITE_BYTE,          // 以字节为单位向缓存区写入数据
    BUFFER_READ_BYTE,           // 以字节为单位从缓存区读取数据
    BUFFER_WRITE_SHORT,         // 以短整型为单位向缓存区写入数据
    BUFFER_READ_SHORT,          // 以短整型为单位从缓存区读取数据
    BUFFER_WRITE_INT,           // 以整型为单位向缓存区写入数据
    BUFFER_READ_INT,            // 以整型为单位从缓存区读取数据
    BUFFER_WRITE_LONG,          // 以长整型为单位向缓存区写入数据
    BUFFER_READ_LONG,           // 以长整型为单位从缓存区读取数据
    BUFFER_SET_SIZE,            // 设置缓存区大小
    BUFFER_SET_ADDRESS,         // 设置缓存区地址
    BUFFER_CLEAR,               // 清空缓存区 
    BUFFER_TOTAL_SIZE,          // 获取缓存区的总大小     
    BUFFER_READ_POINTER,        // 获取缓存区的读指针位置         
    BUFFER_WRITE_POINTER,       // 获取缓存区的写指针位置         
    BUFFER_SPACE_LEFT,          // 获取缓存区中剩余空间的大小    
    BUFFER_WRITTEN_COUNT        // 获取已经写入到缓存区的数据的数量，单位字节 
} BufferCmd;
#endif
// 缓存区定�?
typedef struct
{
    uint8_t *Buf;
    uint32_t BufSize;

    __IO uint32_t Write;
    __IO uint32_t Read;
    __IO uint32_t Count;
} Buffer_t;

Status BUffer_Config(Buffer_t *_pBuf,
                     void *_Data,
                     uint32_t _Size);

Status Buffer_Operation(Buffer_t *_pBuf,
                        void *_Data,
                        uint32_t _Len,
                        uint32_t _Cmd,
                        uint32_t *_Para);
                        

int str_len(char *_str);
void str_cpy(char *_tar, char *_src);
int str_cmp(char *s1, char *s2);

void mem_set(void *_ptr, int _value, int _len);
void mem_cpy(void *_dest, const void *_src, int _len);

uint16_t Check_CRC8(uint8_t *buf, uint16_t len);
uint16_t Check_Modbus_CRC16(uint8_t *buf, uint16_t len);
uint16_t Check_Xmodeme_CRC16(uint8_t *buf, uint16_t len);
uint16_t Check_Ymodeme_CRC16(uint8_t *buf, uint16_t len);




#endif // !__BF_LIB_H
