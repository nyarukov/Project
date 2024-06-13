#ifndef __BSP_LIST_H
#define __BSP_LIST_H

struct list_head {
    struct list_head *next, *prev;
};

/****************************************************************/
#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
    struct list_head name = LIST_HEAD_INIT(name)

//这种宏定义的方法，将节点定义的同时，并且初始化，如果定义好了，就不适合这种方法了

/****************************************************************/
static inline void INIT_LIST_HEAD(struct list_head *list)
{
    list->next = list;
    list->prev = list;
}
//这种方法是节点在外部定义完成后，调用该函数，给成员赋值
/****************************************************************/
/*
 * 在两个已知的连续条目之间插入一个新条目。
 *
 * 这仅适用于我们知道 
 * 上一个/下一个条目的内部列表操作！
 */
#ifndef CONFIG_DEBUG_LIST
static inline void __list_add(struct list_head *new,
                  struct list_head *prev,
                  struct list_head *next)
{
    next->prev = new;
    new->next = next;
    new->prev = prev;
    prev->next = new;
}
#else
extern void __list_add(struct list_head *new,
                  struct list_head *prev,
                  struct list_head *next);
#endif

/**
*list_add -添加一个新条目
*@new: 要添加的新条目
*@head: 列出 head 以将其添加到后面
*
*在指定头之后插入一个新条目。
*这有利于堆栈的实现。
*/
static inline void list_add(struct list_head *new, struct list_head *head)
{
    __list_add(new, head, head->next);
}


/**
*list_add_tail -添加新条目
*@new：要添加的新条目
*@head: 列出 head 以将其添加到前面
*
*在指定头之前插入一个新条目。
*这对于实现队列很有用。
*/
static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
    __list_add(new, head->prev, head);
}

/*
*通过创建上一个/下一个条目来删除列表条目
*互相指向对方。
*
*这仅适用于我们所知的内部列表操作
*上一个/下一个条目已经有了！
*/
static inline void __list_del(struct list_head * prev, struct list_head * next)
{
    next->prev = prev;
    prev->next = next;
}

/**
*list_del -从列表中删除条目。
*@entry: 要从列表中删除的元素。
*注意：条目上的 list_empty() 在此之后不会返回 true，该条目是
*处于未定义状态。
*/
#ifndef CONFIG_DEBUG_LIST
static inline void list_del(struct list_head *entry)
{
    __list_del(entry->prev, entry->next);
}
#else
extern void list_del(struct list_head *entry);
#endif




#define offsetof(TYPE, MEMBER)  ((size_t)&((TYPE *)0)->MEMBER)



/**
*container_of -将结构体的成员转换为包含结构体根据结构体body
*@ptr:   的成员变量的地址导出包含成员变量mem的结构体的地址：指向成员的指针。结构体变量中成员的地址
*@typ:  该结构体所嵌入的容器结构体的类型。 结构体类型
*@member:   结构体中成员的名称。结构体变量的具体名称
*
*/
#define container_of(ptr, type, member) ({                      \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) );})


#define list_entry(ptr, type, member) \
        container_of(ptr, type, member)



#define list_for_each_entry(pos, head, member)              \
    for (pos = list_entry((head)->next, typeof(*pos), member);  \
         &pos->member != (head);    \
         pos = list_entry(pos->member.next, typeof(*pos), member)) \



#endif // __BSP_LIST_H

