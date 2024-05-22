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
 * \brief ������ڵ�ǰ����ڵ�.
 * 
 * \param list ����
 * \param node �ڵ�
 */
inline void bf_list_insert_before(struct bf_list *list, struct bf_list *node)
{
    list->prev->next = node;
    node->prev = list->prev;
    node->next = list;
    list->prev = node;
}
/**
 * \brief ������ڵ�����ڵ�.
 * 
 * \param list ����
 * \param node �ڵ�
 */
inline void bf_list_insert_later(struct bf_list *list, struct bf_list *node)
{
    list->next->prev = node;
    node->next = list->next;
    node->prev = list;
    list->next = node;
}
/**
 * \brief ���������Ƴ�һ���ڵ�.
 * 
 * \param node �Ƴ��Ľڵ�
 */
inline void bf_list_remove(struct bf_list *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->next = node->prev = node;
}


#endif // !__BF_LIST_H
