#ifndef __BF_BUFFER_H
#define __BF_BUFFER_H

#include "bf_middle.h"

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
} Buffer_Cmd;

typedef struct
{
    uint8_t *Buf;
    uint32_t BufSize;
    __IO uint32_t Write;
    __IO uint32_t Read;
    __IO uint32_t Count;
} Buffer_t;

Status Buffer_Config(Buffer_t *_pBuf,
                     void *_Data,
                     uint32_t _Size);

Status Buffer_Operation(Buffer_t *_pBuf,
                        void *_Data,
                        uint32_t _Len,
                        Buffer_Cmd _Cmd,
                        uint32_t *_Para);
    
#endif // !__BF_BUFFER_H

