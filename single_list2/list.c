#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int list_insert(list **mylist,score *data)
{
    list *node;
    node = malloc(sizeof(*node));
    if(node == NULL)
    {
        return -1;
    }

    node->data = *data;
    node->next = *mylist;
    *mylist = node;
}

int list_delete(list **mylist)
{
    list *node;
    if(*mylist == NULL)
        return -1;
    
    node = *mylist;
    *mylist = (*mylist)->next;
    free(node);
    return 0;
}

score *list_find(list *mylist,int id)
{
    list *node = mylist;

    while(node)
    {
        if(node->data.id == id)
        {
            return &node->data;
        }
        node = node->next;
    }
    return NULL;
}

int list_insert_tail(list **mylist,score *data)
{
    list *node,*p = *mylist;
    node = malloc(sizeof(*node));
    node->data = *data;
    node->next = NULL;

    if(node == NULL)
    {
        return -1;
    }

    if(*mylist == NULL)
    {
        *mylist = node;
    }
    else
    {
        while(p->next)
        {
            p = p->next;
        }
        p->next = node;
    }
    return 0;
}

int list_show(list *mylist)
{
    while(mylist)
    {
        printf("%d %s %d %d\n",mylist->data.id,mylist->data.name,mylist->data.math,mylist->data.chinese);
        mylist = mylist->next;
    }
    printf("\n");
}

int list_destory(list *mylist)
{

    list *node = mylist;
    if(mylist == NULL)
    {
        return -1;
    }
    while(mylist)
    {
        node = mylist->next;
        free(mylist);
        mylist = node;
    }
    return 0;
}