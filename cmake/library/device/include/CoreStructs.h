/**
 * @file CoreStructs.h
 * @author yusaka (luckychaoyue1@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2024-03-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef __CORESTRUCTS_H
#define __CORESTRUCTS_H

#include <stdio.h>

struct sa_list {
    struct sa_list *next;
    struct sa_list *prev;
};

inline void sa_list_init(struct sa_list *list);
inline void sa_list_insert_before(struct sa_list *list, struct sa_list *node);
inline void sa_list_insert_later(struct sa_list *list, struct sa_list *node);
inline void sa_list_remove(struct sa_list *node);


#endif // CORESTRUCTS_H
