/**
 * @file list.h
 * @author yusaka (luckychaoyue1@gmail.com)
 * @brief
 * @version 1.0
 * @date 2024-03-24
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef __LIST_H
#define __LIST_H

#include <stdio.h>
#include "math.h"

/**
 * @brief 单向链表
 * 
 */
typedef struct bf_Slist
{
    struct bf_Slist *next;
};

inline void cf_Slist_init(struct bf_Slist *list)
{
    list->next = NULL;
}

/**
 * @brief 在节点之后插入一个新节点
 *
 * @param list 原节点
 * @param node 新节点
 */
inline void bf_Slist_insert_after(struct bf_Slist *list, struct bf_Slist *node)
{
    node->next = list->next;
    list->next = node;
}

/**
 * @brief 双向链表节点
 *
 */
typedef struct bf_Dlist
{
    struct bf_Dlist *next; ///< 指向下一个节点的指针
    struct bf_Dlist *prev; ///< 指向前一个节点的指针
} bf_Dlist;

/**
 * @brief 分配新的链表节点
 *
 * @param type 数据类型
 * @return 分配的链表节点指针
 */

#define bf_new_node(type) (type *)malloc(sizeof(bf_Dlist) + sizeof(type))

/**
 * @brief 
 * 
 * @param list 
 */
inline void bf_Dlist_init(struct bf_Dlist *list)
{
    list->next = list;
    list->prev = list;
}

/**
 * @brief 在节点之前插入一个新节点
 *
 * @param list 原节点
 * @param node 新节点
 */
inline void bf_Dlist_insert_before(struct bf_Dlist *list, struct bf_Dlist *node)
{
    list->prev->next = node;
    node->prev = list->prev;
    node->next = list;
    list->prev = node;
}

/**
 * @brief 在节点之后插入一个新节点
 *
 * @param list 原节点
 * @param node 新节点
 */
inline void bf_Dlist_insert_after(struct bf_Dlist *list, struct bf_Dlist *node)
{
    list->next->prev = node;
    node->next = list->next;
    node->prev = list;
    list->next = node;
}

/**
 * @brief 
 * 
 * @param node 
 */
inline void bf_Dlist_remove(struct bf_Dlist *node)
{

    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->next = node->prev = node;
}

#endif // LIST_H
