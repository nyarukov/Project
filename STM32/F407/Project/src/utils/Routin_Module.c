/**
 * @file Routin_Module.c
 * @author yusaka (luckychaoyue1@gmail.com)
 * @brief
 * @version 1.0
 * @date 2024-05-22
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "Routin_Module.h"

struct bf_list *RM_List = NULL;
#define Create_Root                   \
    do                                \
    {                                 \
        RM_List = bf_malloc(bf_list); \
        bf_list_init(RM_List);        \
    } while (0);

/**
 * \brief 注册路由信息
 *
 * \param [in] _ID 模块ID
 * \param [in] _Recv 接受函数
 * \return Status
 */
Status Routin_Register(int _ID, Status (*_Recv)(int, int, void *, int))
{
    if (bf_list_empty(RM_List))
    {
        if (bf_list_empty(RM_List))
            Create_Root;
    }

    struct bf_list *node = bf_new_node(Routin_Module);
    if (bf_list_empty(RM_List))
        return BF_ERROR;

    bf_get_elem(node, Routin_Module)->ID = _ID;
    bf_get_elem(node, Routin_Module)->Send = _Recv;
    bf_get_elem(node, Routin_Module)->Recv = Route_Forward;

    bf_list_insert_later(RM_List, node);

    return BF_SUCCESS;
}

/**
 * @brief 注销路由信息
 *
 * @param _ID 模块ID
 * @return Status
 */
Status Routin_ID_Cancle(int _ID)
{
    bf_list_foreach(RM_List)
    {
        Routin_Module *Clear_Module = bf_get_elem(count, Routin_Module);
        if (Clear_Module->ID == _ID)
        {
            bf_list_remove(count);
            bf_free_node(count);
            return BF_SUCCESS;
        }
    }
    _LOG_Routin("ID NULL!\r\n");
    return BF_NOT_FOUND;
}

/**
 * @brief 注销所有路由信息
 *
 * @return Status
 */
Status Routin_ALL_Cancle(void)
{
    bf_list_foreach(RM_List)
    {
        printf("--->> a\r\n");
        bf_list_remove(count);
        bf_free_node(count);
    }
    return BF_SUCCESS;
}

/**
 * @brief 遍历路由表
 *
 */
void Routin_Foreach(void)
{
    bf_list_foreach(RM_List)
    {
        _LOG_Routin("--> ID: %d\r\n", bf_get_elem(count, Routin_Module)->ID);
    }
}

/**
 * \brief 路由转发数据到目的模块
 *
 * \param [in] _Src 源模块ID，可根据此ID做一些额外的操作，如按源模块格式进行解包分析
 * \param [in] _Dst 目的模块ID，根据此找到目的模块路由，并调用目的模块的recv接口
 * \param [in] _pBuf 输出的数据，可以是特定格式的数据，并在此接口中解析数据
 * \param [in] _Len 输入的数据长度
 * \return Status
 */
Status Route_Forward(int _Src, int _Dst, void *_pBuf, int _Len)
{
    bf_list_foreach(RM_List)
    {
        if (bf_get_elem(count, Routin_Module)->ID == _Dst)
        {
            if (bf_get_elem(count, Routin_Module)->Send)
            {
                bf_get_elem(count, Routin_Module)->Send(_Src, _Dst, _pBuf, _Len);
                return BF_SUCCESS;
            }
            else
            {
                _LOG_Routin("Send() NULL!\r\n");
                return BF_NOT_FOUND;
            }
        }
    }
    _LOG_Routin("_Dst NULL!\r\n");
    return BF_NOT_FOUND;
}
