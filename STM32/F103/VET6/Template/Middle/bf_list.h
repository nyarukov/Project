#ifndef __BF_LIST_H
#define __BF_LIST_H

#include "bf_middle.h"

struct bf_list {
    struct bf_list *next;
    struct bf_list *prev;
};

#define BF_NEW_NODE(type)   (struct type*)malloc(sizeof(bf_list) + sizeof(type))

inline void bf_list_init(struct bf_list *list)
{
    list->next = list;
    list->prev = list;
}

/**
 * \brief 在链表节点前插入节点.
 * 
 * \param list 链表
 * \param node 节点
 */
inline void bf_list_insert_before(struct bf_list *list, struct bf_list *node)
{
    list->prev->next = node;
    node->prev = list->prev;
    node->next = list;
    list->prev = node;
}
/**
 * \brief 在链表节点后插入节点.
 * 
 * \param list 链表
 * \param node 节点
 */
inline void bf_list_insert_later(struct bf_list *list, struct bf_list *node)
{
    list->next->prev = node;
    node->next = list->next;
    node->prev = list;
    list->next = node;
}
/**
 * \brief 从链表中移除一个节点.
 * 
 * \param node 移除的节点
 */
inline void bf_list_remove(struct bf_list *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->next = node->prev = node;
}


#endif // !__BF_LIST_H
