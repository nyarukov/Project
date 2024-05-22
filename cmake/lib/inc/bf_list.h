/**
 * @file bf_list.h
 * @author yusaka (luckychaoyue1@gmail.com)
 * @brief
 * @version 1.0
 * @date 2024-05-22
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef __BF_LIST_H
#define __BF_LIST_H

#include "bf_middle.h"

/**
 * \brief 双向链表节点结构体定义
 */
typedef struct bf_list
{
    struct bf_list *next; /**< 指向下一个节点的指针 */
    struct bf_list *prev; /**< 指向上一个节点的指针 */
} bf_list;

/**
 * \brief 分配指定类型大小的内存
 * \param [in] _type 要分配内存的类型
 * \return 返回指向分配内存的指针
 */
#define bf_malloc(_type) (_type *)malloc(sizeof(_type))

/**
 * \brief 创建一个链表节点
 * \param [in] _type 链表中元素的类型
 * \return 返回新创建的链表节点指针
 */
#define bf_new_node(_type) (bf_list *)malloc(sizeof(bf_list) + sizeof(_type))

/**
 * \brief 传入链表节点，获取节点的元素
 * \param [in] _node 传入的链表节点指针
 * \param [in] _type 链表元素的类型
 * \return 返回_type元素的指针
 */
#define bf_get_elem(_node, _type) ((_type *)(((char *)_node) + sizeof(bf_list)))

/**
 * \brief 初始化链表头节点
 * \param [in] _list 链表头节点指针
 */
#define bf_list_init(_list)  \
    ({                       \
        _list->next = _list; \
        _list->prev = _list; \
    })

/**
 * \brief 将节点插入到指定节点之前
 * \param [in] _list 链表中的某个节点指针
 * \param [in] _node 要插入的节点指针
 */
#define bf_list_insert_before(_list, _node) \
    ({                                      \
        _list->prev->next = _node;          \
        _node->prev = _list->prev;          \
        _node->next = _list;                \
        _list->prev = _node;                \
    })

/**
 * \brief 将节点插入到指定节点之后
 * \param [in] _list 链表中的某个节点指针
 * \param [in] _node 要插入的节点指针
 */
#define bf_list_insert_later(_list, _node) \
    ({                                     \
        _list->next->prev = _node;         \
        _node->next = _list->next;         \
        _node->prev = _list;               \
        _list->next = _node;               \
    })

/**
 * \brief 从链表中移除指定节点
 * \param [in] _node 要移除的节点指针
 */
#define bf_list_remove(_node)              \
    ({                                     \
        _node->prev->next = _node->next;   \
        _node->next->prev = _node->prev;   \
        _node->next = _node->prev = _node; \
    })

#define bf_list_foreach(_list) \
    for (bf_list *count = _list->next; count != _list; count = count->next)

#endif // !__BF_LIST_H
