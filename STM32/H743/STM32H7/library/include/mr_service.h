/*
 * @copyright (c) 2023-2024, MR Development Team
 *
 * @license SPDX-License-Identifier: Apache-2.0
 *
 * @date 2023-10-20    MacRsh       First version
 */

#ifndef _MR_SERVICE_H_
#define _MR_SERVICE_H_

#include "mr_def.h"

#ifdef __cplusplus
extern "C" {
#endif/*__cplusplus*/
/**
*@addtogroup 基本
*@{
*/
/**
*@brief 该宏函数连接两个字符串。
*
*@param a 第一个字符串。
*@param b 第二个字符串。
*
*@return 连接的字符串。
*/
#define MR_CONCAT(a, b)                 a##b

/**
*@brief 该宏函数将整数转换为字符串。
*
*@param a 要转换的整数。
*
*@return 整数的字符串表示形式。
*/
#define MR_STR(a)                       #a

/**
*@brief 该宏函数从其成员获取其结构。
*
*@param pointer 指向结构体的指针。
*@param type 结构的类型。
*@param member 结构体的成员。
*
*@return 指向结构的指针。
*/
#define MR_CONTAINER_OF(pointer, type, member) \
    ((type *)((char *)(pointer) - (unsigned long)(&((type *)0)->member)))

/**
*@brief 该宏函数将值向上对齐。
*
*@param value 要对齐的值。
*@paramalign 对齐方式。
*
*@return 对齐值。
*/
#define MR_ALIGN_UP(value, align)       (((value) + (align) - 1) & ~((align) - 1))

/**
*@brief 该宏函数将值向下对齐。
*
*@param value 要对齐的值。
*@param align 对齐方式。
*
*@return 对齐值。
*/
#define MR_ALIGN_DOWN(value, align)     ((value) & ~((align) - 1))

/**
*@brief 该宏函数检查是否设置了值。
*
*@param value 要检查的值。
*@param mask 要检查的掩码。
*/
#define MR_BIT_IS_SET(value, mask)      (((value) & (mask)) == (mask))

/**
 * @brief This macro function sets a value.
 *
 * @param value The value to set.
 * @param mask The mask to set.
 */
#define MR_BIT_SET(value, mask)         ((value) |= (mask))

/**
 * @brief This macro function clears a value.
 *
 * @param value The value to clear.
 * @param mask The mask to clear.
 */
#define MR_BIT_CLR(value, mask)         ((value) &= ~(mask))

/**
*@brief 该宏函数创建一个局部变量。
*
*@param type 变量的类型。
*@param ...参数。
*
*@return 指向变量的指针。
*
*@note 该变量是局部变量，请谨慎使用。
*/
#define MR_MAKE_LOCAL(type, ...)        (&((type){__VA_ARGS__}))

/**
 * @brief This macro function gets the number of elements in an array.
 *
 * @param array The array.
 *
 * @return The number of elements in the array.
 */
#define MR_ARRAY_NUM(array)             (sizeof(array)/sizeof((array)[0]))

/**
*@brief 该宏函数获取两个值中的最大值。
*
*@param a 第一个值。
*@param b 第二个值。
*
*@return 两个值中的最大值。
*/
#define MR_MAX(a, b)                    ({typeof (a) _a = (a); typeof (b) _b = (b); _a > _b ? _a : _b; })

/**
 * @brief This macro function gets the minimum of two values.
 *
 * @param a The first value.
 * @param b The second value.
 *
 * @return The minimum of the two values.
 */
#define MR_MIN(a, b)                    ({typeof (a) _a = (a); typeof (b) _b = (b); _a < _b ? _a : _b; })

/**
*@brief 该宏函数确保一个值在指定的范围内。
*
*@param value 值。
*@param min 最小值。
*@param max 最大值。
*
*@return 指定范围内的值。
*/
#define MR_BOUND(value, min, max) \
    ({__typeof__(value) _value = (value); __typeof__(min) _min = (min); __typeof__(max) _max = (max); \
    (_value) < (_min) ? (_min) : ((_value) > (_max) ? (_max) : (_value));})

/**
*@brief 该宏函数确保一个值在指定的范围内。
*
*@param value 值。
*@param min 最小值。
*@param max 最大值。
*/
#define MR_LIMIT(value, min, max)       (value) = MR_BOUND(value, min, max)

/**
*@brief 该宏函数交换两个值。
*
*@param a 第一个值。
*@param b 第二个值。
*/
#define MR_SWAP(a, b)                   do { typeof (a) temp = (a); (a) = (b); (b) = temp; } while (0)

/**
*@brief 该宏函数将值转换为布尔值。
*
*@param value 要转换的值。
*
*@return 布尔值。
*/
#define MR_TO_BOOL(value)               (!!(value))
/**@}*/
/**
*@addtogroup 日志
*@{
*/
/**
*@brief 用颜色记录消息。
*/
#ifdef MR_USING_LOG_COLOR
#define MR_LOG_COLOR_RED(str, fmt)      "\033[31m"str, fmt"\033[0m" /**< Log red color */
#define MR_LOG_COLOR_YELLOW(str, fmt)   "\033[33m"str, fmt"\033[0m" /**< Log yellow color */
#define MR_LOG_COLOR_BLUE(str, fmt)     "\033[34m"str, fmt"\033[0m" /**< Log blue color */
#define MR_LOG_COLOR_PURPLE(str, fmt)   "\033[35m"str, fmt"\033[0m" /**< Log purple color */
#define MR_LOG_COLOR_GREEN(str, fmt)    "\033[32m"str, fmt"\033[0m" /**< Log green color */
#else
#define MR_LOG_COLOR_RED(str, fmt)      str, fmt
#define MR_LOG_COLOR_YELLOW(str, fmt)   str, fmt
#define MR_LOG_COLOR_BLUE(str, fmt)     str, fmt
#define MR_LOG_COLOR_PURPLE(str, fmt)   str, fmt
#define MR_LOG_COLOR_GREEN(str, fmt)    str, fmt
#endif /* MR_USING_LOG_COLOR */

#ifdef MR_USING_LOG_ERROR
/* Print error message */
#define MR_LOG_ERROR(fmt, ...)          mr_printf("%-8s %s\r\n", MR_LOG_COLOR_RED("ERROR:", fmt), ##__VA_ARGS__)
#else
#define MR_LOG_ERROR(fmt, ...)
#endif /* MR_USING_LOG_ERROR */
#ifdef MR_USING_LOG_WARN
/* Print warning message */
#define MR_LOG_WARN(fmt, ...)           mr_printf("%-8s %s\r\n", MR_LOG_COLOR_YELLOW("WARNING:", fmt), ##__VA_ARGS__)
#else
#define MR_LOG_WARN(fmt, ...)
#endif /* MR_USING_LOG_WARN */
#ifdef MR_USING_LOG_INFO
/* Print information message */
#define MR_LOG_INFO(fmt, ...)           mr_printf("%-8s %s\r\n", MR_LOG_COLOR_BLUE("INFO:", fmt), ##__VA_ARGS__)
#else
#define MR_LOG_INFO(fmt, ...)
#endif /* MR_USING_LOG_INFO */
#ifdef MR_USING_LOG_DEBUG
/* Print debug message */
#define MR_LOG_DEBUG(fmt, ...)          mr_printf("%-8s %s\r\n", MR_LOG_COLOR_PURPLE("DEBUG:", fmt), ##__VA_ARGS__)
#else
#define MR_LOG_DEBUG(fmt, ...)
#endif /* MR_USING_LOG_DEBUG */
#ifdef MR_USING_LOG_SUCCESS
/* Print success message */
#define MR_LOG_SUCCESS(fmt, ...)        mr_printf("%-8s %s\r\n", MR_LOG_COLOR_GREEN("SUCCESS:", fmt), ##__VA_ARGS__)
#else
#define MR_LOG_SUCCESS(fmt, ...)
#endif/*MR_USING_LOG_SUCCESS*/
/**@}*/
/**
*@addtogroup 断言
*@{
*/
/**
*@brief 该宏函数断言一个条件。
*
*@param ex 断言的条件。
*/
#ifdef MR_USING_ASSERT
#define MR_ASSERT(ex)                   \
    do                                  \
    {                                   \
        if (!(ex))                      \
        {                               \
            mr_printf("%-8s "           \
                      "failed: %s, "    \
                      "function: %s, "  \
                      "file: %s, "      \
                      "line: %d.\r\n",  \
                      "ASSERT:",        \
                      #ex,              \
                      (__FUNCTION__),   \
                      (__FILE__),       \
                      (__LINE__));      \
            while(1);                   \
        }                               \
    } while(0)
#else
#define MR_ASSERT(ex)
#endif/*MR_USING_ASSERT*/
/**@}*/
/**
*@addtogroup 列表
*@{
*/
/**
*@brief 该宏函数初始化一个列表。
*
*@param list 要初​​始化的列表。
*/
#define MR_LIST_INIT(list)              {&(list), &(list)}

/**
*@brief 该函数检查列表是否为空。
*
*@param list 要检查的列表。
*
*@return 如果列表为空则为 True，否则为 mr_false。
*/
MR_INLINE int mr_list_is_empty(struct mr_list *list)
{
    return list->next == list;
}

/**
*@brief 该函数初始化一个双列表。
*
*@param list 要初​​始化的列表。
*/
MR_INLINE void mr_list_init(struct mr_list *list)
{
    list->next = list;
    list->prev = list;
}

/**
*@brief 该函数在双链表中的一个节点之后插入一个节点。
*
*@param list 要插入到后面的列表。
*@param node 要插入的节点。
*/
MR_INLINE void mr_list_insert_after(struct mr_list *list, struct mr_list *node)
{
    list->next->prev = node;
    node->next = list->next;
    list->next = node;
    node->prev = list;
}

/**
*@brief 此函数在双列表中的节点之前插入一个节点。
*
*@param list 要插入之前的列表。
*@param node 要插入的节点。
*/
MR_INLINE void mr_list_insert_before(struct mr_list *list, struct mr_list *node)
{
    list->prev->next = node;
    node->prev = list->prev;
    list->prev = node;
    node->next = list;
}

/**
*@brief 该函数从双链表中删除一个节点。
*
*@param node 要删除的节点。
*/
MR_INLINE void mr_list_remove(struct mr_list *node)
{
    node->next->prev = node->prev;
    node->prev->next = node->next;
    node->next = node->prev = node;
}

/**
*@brief 该函数获取双列表的长度。
*
*@param list 要获取长度的列表。
*
*@return 列表的长度。
*/
MR_INLINE size_t mr_list_get_len(struct mr_list *list)
{
    struct mr_list *node = list;
    size_t len = 0;

    while (node->next != list) {
        node = node->next;
        len++;
    }
    return len;
}
/** @} */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _MR_SERVICE_H_ */
