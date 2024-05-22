#include "bf_middle.h"

typedef struct
{
    int age;
}std;

void test_function()
{
    struct bf_list *l1 = bf_malloc(bf_list);
    bf_list_init(l1);
    struct bf_list *s1 = NULL;

    for (size_t i = 0; i < 10; i++)
    {
        s1 = bf_new_node(std);
        bf_get_elem(s1, std)->age =  i;
        bf_list_insert_later(l1, s1);
    }

    
    bf_list_foreach(l1){
        printf("Age: %d\n", bf_get_elem(count, std)->age);
    }
    
}

int main()
{
    test_function();
    return 0;
}