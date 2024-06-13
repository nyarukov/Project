#ifndef __BSP_LISTNODE_H
#define __BSP_LISTNODE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct
{
    int val;
    struct listnode* prev;
    struct listnode* next;
}listnode;

listnode* listnode_init(void);
void listnode_delete(listnode* _pos);
void listnode_inster(listnode* _pos,int _val);
void listnode_pushback(listnode* _list, int _val);
void listnode_pushhand(listnode* _list, int _val);
void listnode_popback(listnode* _list);
void listnode_pophand(listnode* _list);
int listnode_length(listnode* _list);
void print_list(listnode * _list);

#endif // !__BSP_LISTNODE_H