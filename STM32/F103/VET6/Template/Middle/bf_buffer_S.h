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

    BUFFER_CLEAR,               // 清空缓存区 
    BUFFER_SET_SIZE,            // 设置缓存区大小
    BUFFER_SET_ADDRESS,         // 设置缓存区地址
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

/**  
 * \brief 配置环形缓存区。  
 *  
 * 该函数用于初始化或重新配置一个环形缓存区。  
 *  
 * \param [in] _pBuf 指向环形缓存区结构体的指针，用于存储缓存区的配置和数据。  
 * \param [in] _Data 指向用于初始化缓存区数据的内存区域的指针（如果需要初始化的话）。  
 *              如果不需要初始化，可以传递NULL。  
 * \param [in] _Size 缓存区的大小（以字节为单位）。  
 *  
 * \return 操作的状态。  
 *   - BF_OK：缓存区配置成功。  
 *   - BF_NULL_POINTER：输入时传递了空指针。  
*/  
Status Buffer_Config(Buffer_t *_pBuf, void *_Data, uint32_t _Size);


/**
 * \brief  以位为单位向缓存区写入数据。
 * 
 * \param [in] _pBuf 指向环形缓存区结构体的指针。
 * \param [in] _Data 指向要从缓存区读取或写入的数据的指针。
 * \param [in] _Len 要处理的数据长度。
 * \return 操作的状态。
 *   - BF_OK：操作成功完成。
 *   - BF_NULL_POINTER：输入时传递了空指针。
 *   - FULL：缓存区已满，无法执行操作。
 *   - EMPTY：缓存区为空或值为空(读取过多)，无法执行操作。
*/
Status Buffer_WriteBit(Buffer_t *_pBuf, void *_Data, uint32_t _Len);

/**  
 * \brief 从缓存区以位为单位读取数据。  
 *   
 * \param [in] _pBuf 指向环形缓存区结构体的指针。  
 * \param [out] _Data 指向用于存储从缓存区读取的数据的指针。  
 * \param [in] _Len 要处理的数据长度（位数）。  
 * \return 操作的状态。  
 *   - BF_OK：操作成功完成。  
 *   - BF_NULL_POINTER：输入时传递了空指针。  
 *   - EMPTY：缓存区为空或值为空(读取过多)，无法执行操作。  
*/  
Status Buffer_ReadBit(Buffer_t *_pBuf, void *_Data, uint32_t _Len);  
  
/**  
 * \brief 向缓存区写入一个字节的数据。  
 *   
 * \param [in] _pBuf 指向环形缓存区结构体的指针。  
 * \param [in] _Data 指向要写入缓存区的字节数据的指针。  
 * \param [in] _Len 要写入的字节数（注意：应为1的倍数）。  
 * \return 操作的状态。  
 *   - BF_OK：操作成功完成。  
 *   - BF_NULL_POINTER：输入时传递了空指针。  
 *   - FULL：缓存区已满，无法执行操作。  
*/  
Status Buffer_WriteByte(Buffer_t *_pBuf, void *_Data, uint32_t _Len);  
  
/**  
 * \brief 从缓存区读取一个字节的数据。  
 *   
 * \param [in] _pBuf 指向环形缓存区结构体的指针。  
 * \param [out] _Data 指向用于存储从缓存区读取的字节数据的指针。  
 * \param [in] _Len 要读取的字节数（注意：应为1的倍数）。  
 * \return 操作的状态。  
 *   - BF_OK：操作成功完成。  
 *   - BF_NULL_POINTER：输入时传递了空指针。  
 *   - EMPTY：缓存区为空或值为空(读取过多)，无法执行操作。  
*/  
Status Buffer_ReadByte(Buffer_t *_pBuf, void *_Data, uint32_t _Len);  
  
/**  
 * \brief 向缓存区写入一个短整数（16位）的数据。  
 *   
 * \param [in] _pBuf 指向环形缓存区结构体的指针。  
 * \param [in] _Data 指向要写入缓存区的短整数数据的指针。  
 * \param [in] _Len 要写入的短整数数（注意：应为2的倍数）。  
 * \return 操作的状态。  
 *   - BF_OK：操作成功完成。  
 *   - BF_NULL_POINTER：输入时传递了空指针。  
 *   - FULL：缓存区已满，无法执行操作。  
*/  
Status Buffer_WriteShort(Buffer_t *_pBuf, void *_Data, uint32_t _Len);  
  
/**  
 * \brief 从缓存区读取一个短整数（16位）的数据。  
 *   
 * \param [in] _pBuf 指向环形缓存区结构体的指针。  
 * \param [out] _Data 指向用于存储从缓存区读取的短整数数据的指针。  
 * \param [in] _Len 要读取的短整数数（注意：应为2的倍数）。  
 * \return 操作的状态。  
 *   - BF_OK：操作成功完成。  
 *   - BF_NULL_POINTER：输入时传递了空指针。  
 *   - EMPTY：缓存区为空或值为空(读取过多)，无法执行操作。  
*/  
Status Buffer_ReadShort(Buffer_t *_pBuf, void *_Data, uint32_t _Len);  
  
/**  
 * \brief 向缓存区写入一个整数（32位）的数据。  
 *   
 * \param [in] _pBuf 指向环形缓存区结构体的指针。  
 * \param [in] _Data 指向要写入缓存区的整数数据的指针。  
 * \param [in] _Len 要写入的整数数（注意：应为4的倍数）。  
 * \return 操作的状态。  
 *   - BF_OK：操作成功完成。  
 *   - BF_NULL_POINTER：输入时传递了空指针。  
 *   - FULL：缓存区已满，无法执行操作。  
*/  
Status Buffer_WriteInt(Buffer_t *_pBuf, void *_Data, uint32_t _Len);  
  
/**  
 * \brief 从缓存区读取一个整数（32位）的数据。  
 *   
 * \param [in] _pBuf 指向环形缓存区结构体的指针。  
 * \param [out] _Data 指向用于存储从缓存区读取的整数数据的指针。
 * \param [in] _Len 要读取的整数数（注意：应为4的倍数）。
 * \return 操作的状态。
 *   - BF_OK：操作成功完成。
 *   - BF_NULL_POINTER：输入时传递了空指针。
 *   - EMPTY：缓存区为空或值为空(读取过多)，无法执行操作。
*/
Status Buffer_ReadInt(Buffer_t *_pBuf, void *_Data, uint32_t _Len);

/**
 * \brief 向缓存区写入一个长整数（64位）的数据。
 * \param [in] _pBuf 指向环形缓存区结构体的指针。
 * \param [in] _Data 指向要写入缓存区的长整数数据的指针。
 * \param [in] _Len 要写入的长整数数（注意：应为8的倍数）。
 * \return 操作的状态。
 *   - BF_OK：操作成功完成。
 *   - BF_NULL_POINTER：输入时传递了空指针。
 *   - FULL：缓存区已满，无法执行操作。
*/
Status Buffer_WriteLong(Buffer_t *_pBuf, void *_Data, uint32_t _Len);

/**
 * \brief 从缓存区读取一个长整数（64位）的数据。
 * \param [in] _pBuf 指向环形缓存区结构体的指针。
 * \param [out] _Data 指向用于存储从缓存区读取的长整数数据的指针。
 * \param [in] _Len 要读取的长整数数（注意：应为8的倍数）。
 * \return 操作的状态。
 *   - BF_OK：操作成功完成。
 *   - BF_NULL_POINTER：输入时传递了空指针。
 *   - EMPTY：缓存区为空或值为空(读取过多)，无法执行操作。
*/
Status Buffer_ReadLong(Buffer_t *_pBuf, void *_Data, uint32_t _Len);

/**  
 * @brief 获取缓冲区的总大小  
 *  
 * @param _pBuf 缓冲区指针  
 *  
 * @return 缓冲区的总大小  
 */  
uint32_t Buffer_GetTotalSize(Buffer_t *_pBuf);
  
/**  
 * @brief 获取缓冲区的读指针位置  
 *  
 * @param _pBuf 缓冲区指针  
 *  
 * @return 读指针位置  
 */  
uint32_t Buffer_GetReadPointer(Buffer_t *_pBuf);
  
/**  
 * @brief 获取缓冲区的写指针位置  
 *  
 * @param _pBuf 缓冲区指针  
 *  
 * @return 写指针位置  
 */  
uint32_t Buffer_GetWritePointer(Buffer_t *_pBuf);

/**  
 * @brief 获取缓冲区剩余的可用空间  
 *  
 * @param _pBuf 缓冲区指针  
 *  
 * @return 剩余可用空间大小，如果缓冲区为空但_pBuf->Count不为0则返回0  
 */  
uint32_t Buffer_GetSpaceLeft(Buffer_t *_pBuf);
  
/**  
 * @brief 获取缓冲区已写入的数据数量  
 *  
 * @param _pBuf 缓冲区指针  
 *  
 * @return 已写入的数据数量  
 */  
uint32_t Buffer_GetWrittenCount(Buffer_t *_pBuf);

/**
 * \brief 对环形缓存区执行各种操作。
 *
 * 此函数允许执行诸如向缓存区写入、从缓存区读取、清除和查询等操作。
 *
 * \param [in] _pBuf 指向环形缓存区结构体的指针。
 * \param [in] _Data 指向要从缓存区读取或写入的数据的指针。
 * \param [in] _Len 要处理的数据长度。
 * \param [in] _Cmd 表示要在缓存区上执行的操作的命令。可以使用以下预定义的命令：
 *   - BUFFER_WRITE_BIT: 			以位为单位向缓存区写入数据。
 *   - BUFFER_READ_BIT: 			以位为单位从缓存区读取数据。
 *   - BUFFER_WRITE_BYTE: 			以字节为单位向缓存区写入数据。
 *   - BUFFER_READ_BYTE: 			以字节为单位从缓存区读取数据。
 *   - BUFFER_WRITE_SHORT: 			以短整型为单位向缓存区写入数据。
 *   - BUFFER_READ_SHORT: 			以短整型为单位从缓存区读取数据。
 *   - BUFFER_WRITE_INT: 			以整型为单位向缓存区写入数据。
 *   - BUFFER_READ_INT: 			以整型为单位从缓存区读取数据。
 *   - BUFFER_WRITE_LONG: 			以长整型为单位向缓存区写入数据。
 *   - BUFFER_LONG_REA: 			以长整型为单位从缓存区读取数据。
 *
 *   - BUFFER_SET_SIZE:					设置缓存区的大小
 * 	 - BUFFER_SET_ADDRESS:				设置缓存区的起始地址。
 *
 *   - BUFFER_CLEAR: 				清空缓存区。
 *   - BUFFER_TOTAL_SIZE: 			获取缓存区的总大小。
 *   - BUFFER_READ_POINTER: 		获取缓存区的读指针位置。
 *   - BUFFER_WRITE_POINTER: 		获取缓存区的写指针位置。
 *   - BUFFER_SPACE_LEFT:		 	获取缓存区中剩余空间的大小。
 *   - BUFFER_WRITTEN_COUNT         获取已经写入到缓存区的数据的数量，单位字节 
 * \param [in] _Para 用于某些命令的附加参数。具体用法如下：
 *   - 当 `_Cmd` 为 `BUFFER_CLEAR` 时，`_Para` 用于设置清除缓存区的值。
 *   - 当 `_Cmd` 为 `BUFFER_TOTAL_SIZE` 时，`_Para` 用于存储缓存区的总大小。
 *   - 当 `_Cmd` 为 `BUFFER_READ_POINTER` 时，`_Para` 用于存储缓存区的读指针位置。
 *   - 当 `_Cmd` 为 `BUFFER_WRITE_POINTER` 时，`_Para` 用于存储缓存区的写指针位置。
 *   - 当 `_Cmd` 为 `BUFFER_SPACE_LEFT` 时，`_Para` 用于存储缓存区中剩余空间的大小。
 *   - 当 `_Cmd` 为 `BUFFER_SPACE_LEFT` 时，`_Para` 用于存储缓存区中入到缓存区的数据的数量。
 * \return 操作的状态。
 *   - BF_OK：操作成功完成。
 *   - BF_NULL_POINTER：输入时传递了空指针。
 *   - FULL：缓存区已满，无法执行操作。
 *   - EMPTY：缓存区为空或值为空(读取过多)，无法执行操作。
 */
Status Buffer_Operation(Buffer_t *_pBuf,
                        void *_Data,
                        uint32_t _Len,
                        Buffer_Cmd _Cmd,
                        uint32_t *_Para);
    
#endif // !__BF_BUFFER_H


