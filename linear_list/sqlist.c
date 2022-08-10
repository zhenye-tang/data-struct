#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

void sqlist_create(sqlist **ptr)
{
    *ptr = malloc(sizeof(**ptr));

    if(*ptr == NULL)
    {
        return;
    }
    (*ptr)->last = -1;
    return;
}

int sqlist_destory(sqlist *list)
{
    free(list);
    return 0;
}

int sqlist_insert(sqlist *list,int i,datatype *data)
{
    int j;
    if(list->last == SIZE -1)
    {
        return -1;
    }

    if(i < 0 || i > list->last +1)
    {
        return -2;
    }
    
    for(j = list->last; i <= j; j--)
    {
        list->data[j+1] = list->data[j];
    }
    list->data[i] = *data;
    list->last++;
}

int sqlist_display(sqlist *list)
{
    int i = 0;

    if(list->last == -1)
    {
        return -1;
    }
    
    for(i = 0 ; i <= list->last ; i++)
    {
        printf("%d ",list->data[i]);
    }

    printf("\n");
    return 0;
}

int sqlist_delete(sqlist *list, int i)
{
    int j;
    if(i < 0 || i > list->last)
        return -1;
    
    for(j = i+1; j <= list->last ; j++)
    {
        list->data[j-1] = list->data[j];
    }
    list->last--;
    return 0;
}

int sqlist_find(sqlist *list, datatype *data)
{
    int i = 0;
    if(sqlist_isempty(list) < 0)
        return -1;

    for(i = 0 ;i <= list->last ;i++)
    {
        if(list->data[i] == *data)
        {
            return i;
        }
    }
    return -2;
}

int sqlist_isempty(sqlist *list)
{
    if(list->last == -1)
        return -1;
    return 0;
}

int sqlist_set_empty(sqlist *list)
{
    list->last = -1;
    return 0;
}

int sqlist_get_num(sqlist *list)
{
    return (list->last+1);
}

int sqlist_union(sqlist *dis_list,sqlist *src_list)
{
    int i = 0;
    if(sqlist_isempty(src_list) < 0)
        return -1;
    for(i = 0 ;i <= src_list->last ; i++)
    {
        if(sqlist_find(dis_list,&src_list->data[i]) < 0)
        {
            sqlist_insert(dis_list,0,&src_list->data[i]);
        }
    }
}