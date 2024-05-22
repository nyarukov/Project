#ifndef __BSP_LIST_H
#define __BSP_LIST_H

struct list_head {
    struct list_head *next, *prev;
};

/****************************************************************/
#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
    struct list_head name = LIST_HEAD_INIT(name)

//���ֺ궨��ķ��������ڵ㶨���ͬʱ�����ҳ�ʼ�������������ˣ��Ͳ��ʺ����ַ�����

/****************************************************************/
static inline void INIT_LIST_HEAD(struct list_head *list)
{
    list->next = list;
    list->prev = list;
}
//���ַ����ǽڵ����ⲿ������ɺ󣬵��øú���������Ա��ֵ
/****************************************************************/
/*
 * ��������֪��������Ŀ֮�����һ������Ŀ��
 *
 * �������������֪�� 
 * ��һ��/��һ����Ŀ���ڲ��б������
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
*list_add -���һ������Ŀ
*@new: Ҫ��ӵ�����Ŀ
*@head: �г� head �Խ�����ӵ�����
*
*��ָ��ͷ֮�����һ������Ŀ��
*�������ڶ�ջ��ʵ�֡�
*/
static inline void list_add(struct list_head *new, struct list_head *head)
{
    __list_add(new, head, head->next);
}


/**
*list_add_tail -�������Ŀ
*@new��Ҫ��ӵ�����Ŀ
*@head: �г� head �Խ�����ӵ�ǰ��
*
*��ָ��ͷ֮ǰ����һ������Ŀ��
*�����ʵ�ֶ��к����á�
*/
static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
    __list_add(new, head->prev, head);
}

/*
*ͨ��������һ��/��һ����Ŀ��ɾ���б���Ŀ
*����ָ��Է���
*
*���������������֪���ڲ��б����
*��һ��/��һ����Ŀ�Ѿ����ˣ�
*/
static inline void __list_del(struct list_head * prev, struct list_head * next)
{
    next->prev = prev;
    prev->next = next;
}

/**
*list_del -���б���ɾ����Ŀ��
*@entry: Ҫ���б���ɾ����Ԫ�ء�
*ע�⣺��Ŀ�ϵ� list_empty() �ڴ�֮�󲻻᷵�� true������Ŀ��
*����δ����״̬��
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
*container_of -���ṹ��ĳ�Աת��Ϊ�����ṹ����ݽṹ��body
*@ptr:   �ĳ�Ա�����ĵ�ַ����������Ա����mem�Ľṹ��ĵ�ַ��ָ���Ա��ָ�롣�ṹ������г�Ա�ĵ�ַ
*@typ:  �ýṹ����Ƕ��������ṹ������͡� �ṹ������
*@member:   �ṹ���г�Ա�����ơ��ṹ������ľ�������
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

