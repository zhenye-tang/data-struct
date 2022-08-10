#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "double_list.h"

static int list_insert(LLIST *ptr,const void *data,int mode)
{
    struct list_node *newnode;
    newnode = malloc(sizeof(*newnode) + ptr->size);
    if(newnode == NULL) return -1;

    memcpy(newnode->data,data,ptr->size);

    if(mode == LLIST_FORWARD)
    {
        newnode->prev = &ptr->head;
        newnode->next = ptr->head.next;
        ptr->head.next->prev = newnode;
        ptr->head.next = newnode;
    }
    else if(mode == LLIST_BACKWARD)
    {
        newnode->prev = ptr->head.prev;
        newnode->next = &ptr->head;
        ptr->head.prev->next = newnode;
        ptr->head.prev = newnode;
    }
    else return -3;
}

static struct list_node *_find(LLIST *ptr,const void *key,cmp *cb)
{
    struct list_node *cur;
    for(cur = ptr->head.next; cur != &ptr->head; cur = cur->next)
    {
        if(cb(key,cur->data) == 0)
        {
            break;
        }
    }
    return cur;
}

static void *list_find(LLIST *ptr,const void *key,cmp *cb)
{
    struct list_node *node;
    node = _find(ptr,key,cb);
    if(node == &ptr->head)
        return NULL;
    return node->data;
}

static int list_delete(LLIST *ptr,const void *key,cmp *cb)
{
    struct list_node *node;
    node = _find(ptr,key,cb);
    if(node == &ptr->head)
        return -1;
    
    node->next->prev = node->prev;
    node->prev->next = node->next;
    node->next = node;
    node->next = node;
    free(node);
    return 0;
}

static int list_fetch(LLIST *ptr,const void *key,cmp *cb,void *data)
{
    struct list_node *node;
    node = _find(ptr,key,cb);
    if(node == &ptr->head)
        return -1;
    if(data == NULL)
        return -2;

    memcpy(data,node->data,ptr->size);
    node->next->prev = node->prev;
    node->prev->next = node->next;
    node->next = node;
    node->next = node;
    free(node);
    return 0;
}

static void list_travel(LLIST *ptr, list_op *ops)
{
    struct list_node *cur,*next;
    
    for(cur = ptr->head.next; cur != &ptr->head; cur = cur->next)
    {
        ops(cur->data);
    }
}

static void list_destory(LLIST *ptr)
{
   struct list_node *cur,*next;

    for(cur = ptr->head.next ; cur != &ptr->head ; cur = next)
    {
        next = cur->next;
        free(cur);
    }
    free(ptr);
}

LLIST *list_create(int size)
{
    LLIST *node;
    node = malloc(sizeof(*node));
    if(node == NULL)
    {   
        return NULL;
    }
    node->size = size;
    node->head.next = &node->head;
    node->head.prev = &node->head;
    node->list_insert = list_insert;
    node->list_travel = list_travel;
    node->list_delete = list_delete;
    node->list_destory = list_destory;
    node->list_fetch = list_fetch;
    node->list_find = list_find;
    return node;
}