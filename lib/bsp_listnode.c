#include "bsp_listnode.h"

listnode *listnode_init(void)
{
    listnode *newnode = (listnode *)malloc(sizeof(listnode));
    newnode->prev = newnode;
    newnode->next = newnode;
    return newnode;
}

void listnode_delete(listnode *_pos)
{
    assert(_pos);
    listnode *posnext = _pos->next;
    listnode *posprev = _pos->prev;

    posnext->prev = posprev;
    posprev->next = posnext;
    free(_pos);
    _pos = NULL;
}

void listnode_inster(listnode *_pos, int _val)
{
    assert(_pos);
    listnode *posprev = _pos->prev;
    listnode *newnode = (listnode *)malloc(sizeof(listnode));
    newnode->val = _val;

    // posprev newnode _pos
    posprev->next = newnode;
    newnode->prev = posprev;
    newnode->next = _pos;
    _pos->prev = newnode;
}

void listnode_pushback(listnode *_list, int _val)
{
    assert(_list);
    listnode_inster(_list, _val);
}

void listnode_pushhand(listnode *_list, int _val)
{
    assert(_list);
    listnode_inster(_list->next, _val);
}

void listnode_popback(listnode *_list)
{
    assert(_list);
    assert(_list->prev != _list);
    listnode_delete(_list->prev);
}

void listnode_pophand(listnode *_list)
{
    assert(_list);
    assert(_list->next != _list);
    listnode_delete(_list->next);
}
int listnode_length(listnode *_list)
{
    assert(_list);
    int count = 0;
    listnode *p = _list->next;
    while (p != _list)
    {
        count++;
        p = p->next;
    }
    return count;
}
void print_list(listnode *_list)
{
    assert(_list);
    listnode *p = _list->next;
    while (p != _list)
    {
        printf("%d\t", p->val);
        p = p->next;
    }
}