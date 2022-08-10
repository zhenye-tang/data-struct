#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

int main(void)
{
    int i = 0;
    datatype arr[] = {12,14,18,46};
    datatype arr1[] = {12,14,67,98};
    sqlist *list;
    sqlist *list1;
    sqlist_create(&list);
    sqlist_create(&list1);
    if(list == NULL)
    {
        fprintf(stderr,"sqlist_create() failed!\n");
        exit(0);
    }

    for(i = 0; i < sizeof(arr)/sizeof(*arr); i++)
    {
        sqlist_insert(list,0,&arr[i]);
        sqlist_insert(list1,0,&arr1[i]);
    }
    datatype a = 10;
    sqlist_display(list);
    sqlist_display(list1);
    sqlist_union(list,list1);
    sqlist_display(list);
    sqlist_destory(list);
    sqlist_destory(list1);
    return 0;
}