#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list *list_creat(void)
{
    list *head;
    head = malloc(sizeof(*head));
    if(head == NULL)
        return 0;
    head->next = NULL;
    return head;
}

int list_insert_at(list *mylist,int i, datatype *data)
{
    int j = 0;
    list *node = mylist;
    list *newnode = NULL;
    while(j < i && node != NULL)
    {
        node = node->next;
        j++;
    }

    if(node)
    {
        newnode = malloc(sizeof(*newnode));
        if(newnode == NULL)
            return -3;
        newnode->data = *data;
        newnode->next = node->next;
        node->next = newnode;
    }
    else 
        return -2;
}

int list_display(list *mylist)
{
    list *node = mylist->next;
    if(list_isempty == 0)
        return -1;
    while(node != NULL)
    {
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
    return 0;
}

int list_ordef_insert(list *mylist,datatype *data)
{
    list *node,*newnode;
    node = mylist;
    while(node->next && node->next->data < *data)
    {
        node = node->next;
    }

    newnode = malloc(sizeof(*newnode));
    if(newnode == NULL)
        return -1;
    newnode->data = *data;
    newnode->next = node->next;
    node->next = newnode;

    return 0;
}

int list_delete_at(list *mylist,int i,datatype *data)
{
    
}

int list_delete(list *mylist,datatype *data)
{
    list *node,*q;
    node = mylist;
    while(node->next && node->next->data != *data)
    {
        node = node->next;
    }

    if(node->next == NULL)
    {
        printf("not find\n");
    }
    else
    {
        q = node->next;
        node->next = q->next;
        free(q);
        q = NULL; 
    }
    return 0;
}

int list_isempty(list *mylist)
{
    if(mylist->next == NULL)
    {
        return 0;
    }

    return 1;
}

int list_destory(list *mylist)
{
    list *node,*next;
    for(node = mylist->next; node != NULL; node = next)
    {
        next = node->next;
        free(node);
    }
    free(mylist);
    return 0;
}