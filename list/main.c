#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void)
{
    Linklist List = NULL;
    printf("%p\n", List);
    Creat_List(&List, 5);
    printf("%p\n", List);
    Print_List(List);

    Data d1;
    d1.age = 18;
    Add_Node(List, 2, d1);
    Print_List(List);
    Delete_Node(List, 1);
    Print_List(List);
    Delete_List(&List);

    printf("%p", List);
    return 0;
}

