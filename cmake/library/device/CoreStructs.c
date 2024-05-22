/**
 * @file CoreStructs.c
 * @author yusaka (luckychaoyue1@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2024-03-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "./include/CoreStructs.h"
/**
 * @brief Initialize the singly linked list.
 * 
 * @param list Pointer to the list to be initialized.
 */
inline void sa_list_init(struct sa_list *list)
{
    list->next = list;
    list->prev = list;
}

/**
 * @brief Insert a node before the specified list node.
 * 
 * @param list The list node before which the new node will be inserted.
 * @param node The new node to be inserted.
 */
inline void sa_list_insert_before(struct sa_list *list, struct sa_list *node)
{
    list->prev->next = node;
    node->prev = list->prev;
    node->next = list;
    list->prev = node;
}
/**
 * @brief Remove a node from the list.
 * 
 * @param node The node to be removed from the list.
 */
inline void sa_list_insert_later(struct sa_list *list, struct sa_list *node)
{
    list->next->prev = node;
    node->next = list->next;
    node->prev = list;
    list->next = node;
}
/**
 * @brief 从列表中移除一个节点
 * 
 * @param node 要从列表中移除的节点
 */
inline void sa_list_remove(struct sa_list *node)
{

    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->next = node->prev = node;
}
