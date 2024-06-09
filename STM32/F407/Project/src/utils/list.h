/*
 * 项目名称: list
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-01
 * 最后修改日期: 2024-06-01 18:31:22
 * 描述: 链表
 */

#ifndef __LIST_H
#define __LIST_H

// 头文件内容...

#include "middle.h"

 /**
  * @brief 双向链表节点结构体定义
  */
typedef struct bf_blist
{
    struct bf_blist* next; /**< 指向下一个节点的指针 */
    struct bf_blist* prev; /**< 指向上一个节点的指针 */
} bf_blist;

/**
 * @brief 分配指定类型大小的内存
 *
 * @param [in] _type 要分配内存的类型
 * @return 返回指向分配内存的指针
 */
#define bf_blist_malloc(_type)               \
    (_type *)malloc(sizeof(_type))

 /**
  * @brief 创建一个链表节点
  *
  * @param [in] _type 链表中元素的类型
  * @return 返回新创建的链表节点指针
  */
#define bf_blist_new_node(_type)             \
    (bf_blist *)malloc(sizeof(bf_blist) + sizeof(_type))

  /**
   * @brief 传入链表节点，获取节点的元素
   *
   * @param [in] _node 传入的链表节点指针
   * @param [in] _type 链表元素的类型
   * @return 返回_type元素的指针
   */
#define bf_blist_get_elem(_node, _type)      \
    ((_type *)(((char *)_node) + sizeof(bf_blist)))

   /**
   * @brief 初始化链表头节点
   *
   * @param [in] _list 链表头节点指针
   */
#define bf_blist_init(_list)                 \
    do                                      \
    {                                       \
        _list->next = _list;                \
        _list->prev = _list;                \
    } while (0);

   /**
    * @brief 判断节点是否为空
    *
    * @param [in] _list 链表节点
    */
#define bf_blist_empty(_list)    __CMP_REG(_list,NULL)

    /**
     * @brief 将节点插入到指定节点之前
     *
     * @param [in] _list 链表中的某个节点指针
     * @param [in] _node 要插入的节点指针
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
      * @brief 将节点插入到指定节点之后
      *
      * @param [in] _list 链表中的某个节点指针
      * @param [in] _node 要插入的节点指针
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
       * @brief 从链表中移除指定节点
       *
       * @param [in] _node 要移除的节点指针
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
       * @brief 遍历链表
       *
       * @param [in] _node 链表节点
       */
#define bf_blist_foreach(_node)              \
    for (bf_blist *count =  (_node) ? (_node->next) : NULL; count != _node; count = count->next)

       /**
        * @brief 遍历链表删除节点
        *
        * @param [in]  _node 链表节点
       */
#define bf_blist_for_remove(_node)           \
    for (bf_blist *pos = _node->next, *n = pos->next; pos != _node; pos = n, n = pos->next)

#endif
