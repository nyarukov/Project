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
#define Create_Root ({RM_List = bf_malloc(bf_list); bf_list_init(RM_List);})

/**
 * \brief ע��·����Ϣ
 * 
 * \param [in] _ID ģ��ID
 * \param [in] _Recv ���ܺ���
 * \return Status 
 */
Status Routin_Register(int _ID, Status (*_Recv)(int, int, void*, int))
{
    if(bf_list_empty(RM_List))
    {
        if(bf_list_empty(RM_List))
            Create_Root;
    }

    struct bf_list *node = bf_new_node(Routin_Module);
    if (bf_list_empty(RM_List))
        return BF_ERROR;

    bf_get_elem(node, Routin_Module)->ID = _ID;
    bf_get_elem(node, Routin_Module)->Send = _Recv;
    bf_get_elem(node, Routin_Module)->Recv = Route_Forward;
    
    bf_list_insert_later(RM_List, node);

    return BF_OK;
}


/**
 * @brief ע��·����Ϣ
 * 
 * @param _ID ģ��ID
 * @return Status 
 */
Status Routin_ID_Cancle(int _ID)
{
    bf_list_foreach(RM_List)
    {
        Routin_Module *Clear_Module = bf_get_elem(count,Routin_Module);
        if(Clear_Module->ID == _ID)
        {
          bf_list_remove(count);
          bf_free_node(count);
          return BF_OK;
        }
    }
    _LOG_Routin("ID NULL!\r\n", NULL);
    return BF_NOT_FOUND;
}

/**
 * @brief ע������·����Ϣ
 * 
 * @return Status 
 */
Status Routin_ALL_Cancle(void)
{
  bf_list_foreach(RM_List) { 
    printf("--->> a\r\n");
    bf_list_remove(count);
    bf_free_node(count);
  }
  return BF_OK;
}


/**
 * @brief ����·�ɱ�
 * 
 */
void Routin_Foreach(void)
{
    bf_list_foreach(RM_List)
    {
        _LOG_Routin("--> ID: %d\r\n", bf_get_elem(count,Routin_Module)->ID);
    }
}

/**
 * \brief ·��ת�����ݵ�Ŀ��ģ��
 * 
 * \param [in] _Src Դģ��ID���ɸ��ݴ�ID��һЩ����Ĳ������簴Դģ���ʽ���н������
 * \param [in] _Dst Ŀ��ģ��ID�����ݴ��ҵ�Ŀ��ģ��·�ɣ�������Ŀ��ģ���recv�ӿ�
 * \param [in] _pBuf ��������ݣ��������ض���ʽ�����ݣ����ڴ˽ӿ��н�������
 * \param [in] _Len ��������ݳ���
 * \return Status 
 */
Status Route_Forward(int _Src, int _Dst, void * _pBuf, int _Len)
{
    bf_list_foreach(RM_List)
    {
        if(bf_get_elem(count,Routin_Module)->ID == _Dst)
        {
            if(bf_get_elem(count,Routin_Module)->Send)
            {
                bf_get_elem(count,Routin_Module)->Send(_Src,_Dst,_pBuf,_Len);
                return BF_OK;
            }
            else
            {
                _LOG_Routin("Send() NULL!\r\n",NULL);
                return BF_NOT_FOUND;
            }
        }
    }
    _LOG_Routin("_Dst NULL!\r\n", NULL);
    return BF_NOT_FOUND;
}
