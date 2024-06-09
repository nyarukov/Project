/*
 * ��Ŀ����: list
 * �汾:1.0
 * ����: Yusaka
 * ��������: 2024-06-01
 * ����޸�����: 2024-06-01 18:31:22
 * ����: ����
 */

#ifndef __LIST_H
#define __LIST_H

// ͷ�ļ�����...

#include "middle.h"

 /**
  * @brief ˫������ڵ�ṹ�嶨��
  */
typedef struct bf_blist
{
    struct bf_blist* next; /**< ָ����һ���ڵ��ָ�� */
    struct bf_blist* prev; /**< ָ����һ���ڵ��ָ�� */
} bf_blist;

/**
 * @brief ����ָ�����ʹ�С���ڴ�
 *
 * @param [in] _type Ҫ�����ڴ������
 * @return ����ָ������ڴ��ָ��
 */
#define bf_blist_malloc(_type)               \
    (_type *)malloc(sizeof(_type))

 /**
  * @brief ����һ������ڵ�
  *
  * @param [in] _type ������Ԫ�ص�����
  * @return �����´���������ڵ�ָ��
  */
#define bf_blist_new_node(_type)             \
    (bf_blist *)malloc(sizeof(bf_blist) + sizeof(_type))

  /**
   * @brief ��������ڵ㣬��ȡ�ڵ��Ԫ��
   *
   * @param [in] _node ���������ڵ�ָ��
   * @param [in] _type ����Ԫ�ص�����
   * @return ����_typeԪ�ص�ָ��
   */
#define bf_blist_get_elem(_node, _type)      \
    ((_type *)(((char *)_node) + sizeof(bf_blist)))

   /**
   * @brief ��ʼ������ͷ�ڵ�
   *
   * @param [in] _list ����ͷ�ڵ�ָ��
   */
#define bf_blist_init(_list)                 \
    do                                      \
    {                                       \
        _list->next = _list;                \
        _list->prev = _list;                \
    } while (0);

   /**
    * @brief �жϽڵ��Ƿ�Ϊ��
    *
    * @param [in] _list ����ڵ�
    */
#define bf_blist_empty(_list)    __CMP_REG(_list,NULL)

    /**
     * @brief ���ڵ���뵽ָ���ڵ�֮ǰ
     *
     * @param [in] _list �����е�ĳ���ڵ�ָ��
     * @param [in] _node Ҫ����Ľڵ�ָ��
     */
#define bf_blist_insert_before(_list, _node) \
    do                                      \
    {                                       \
        _list->prev->next = _node;          \
        _node->prev = _list->prev;          \
        _node->next = _list;                \
        _list->prev = _node;                \
    } while (0);


     /**
      * @brief ���ڵ���뵽ָ���ڵ�֮��
      *
      * @param [in] _list �����е�ĳ���ڵ�ָ��
      * @param [in] _node Ҫ����Ľڵ�ָ��
      */
#define bf_blist_insert_later(_list, _node) \
    do                                     \
    {                                      \
        _list->next->prev = _node;         \
        _node->next = _list->next;         \
        _node->prev = _list;               \
        _list->next = _node;               \
    } while (0);


      /**
       * @brief ���������Ƴ�ָ���ڵ�
       *
       * @param [in] _node Ҫ�Ƴ��Ľڵ�ָ��
       */
#define bf_blist_remove(_node)              \
    do                                     \
    {                                      \
        _node->prev->next = _node->next;   \
        _node->next->prev = _node->prev;   \
        free(_node);                       \
        _node = NULL;                      \
    } while (0);

       /**
       * @brief ��������
       *
       * @param [in] _node ����ڵ�
       */
#define bf_blist_foreach(_node)              \
    for (bf_blist *count =  (_node) ? (_node->next) : NULL; count != _node; count = count->next)

       /**
        * @brief ��������ɾ���ڵ�
        *
        * @param [in]  _node ����ڵ�
       */
#define bf_blist_for_remove(_node)           \
    for (bf_blist *pos = _node->next, *n = pos->next; pos != _node; pos = n, n = pos->next)

#endif
