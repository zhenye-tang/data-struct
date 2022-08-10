#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "double_list.h"

struct list_node
{
    struct list_node *prev;
    struct list_node *next;
    char data[0];
};

struct list_head
{
    int size;
    struct list_node head;
};

LLIST *list_create(int size)
{
    struct list_head *node;
    node = malloc(sizeof(*node));
    if(node == NULL)
    {   
        return NULL;
    }
    node->size = size;
    node->head.next = &node->head;
    node->head.prev = &node->head;
    return node;
}

int list_insert(LLIST *ptr,const void *data,int mode)
{
    struct list_node *newnode;
    struct list_head *head = ptr;
    newnode = malloc(sizeof(*newnode) + head->size);
    if(newnode == NULL) return -1;

    memcpy(newnode->data,data,head->size);

    if(mode == LLIST_FORWARD)
    {
        newnode->prev = &head->head;
        newnode->next = head->head.next;
        head->head.next->prev = newnode;
        head->head.next = newnode;
    }
    else if(mode == LLIST_BACKWARD)
    {
        newnode->prev = head->head.prev;
        newnode->next = &head->head;
        head->head.prev->next = newnode;
        head->head.prev = newnode;
    }
    else return -3;
}

static struct list_node *_find(struct list_head *ptr,const void *key,cmp *cb)
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

void *list_find(LLIST *ptr,const void *key,cmp *cb)
{
    struct list_node *node;
    struct list_head *head = ptr;
    node = _find(ptr,key,cb);
    if(node == &head->head)
        return NULL;
    return node->data;
}

int list_delete(LLIST *ptr,const void *key,cmp *cb)
{
    struct list_node *node;
    struct list_head *head = ptr;
    node = _find(ptr,key,cb);
    if(node == &head->head)
        return -1;
    
    node->next->prev = node->prev;
    node->prev->next = node->next;
    node->next = node;
    node->next = node;
    free(node);
    return 0;
}

int list_fetch(LLIST *ptr,const void *key,cmp *cb,void *data)
{
    struct list_node *node;
    struct list_head *head = ptr;
    node = _find(ptr,key,cb);
    if(node == &head->head)
        return -1;
    if(data == NULL)
        return -2;

    memcpy(data,node->data,head->size);
    node->next->prev = node->prev;
    node->prev->next = node->next;
    node->next = node;
    node->next = node;
    free(node);
    return 0;
}

void list_travel(LLIST *ptr, list_op *ops)
{
    struct list_node *cur,*next;
    struct list_head *head = ptr;
    for(cur = head->head.next; cur != &head->head; cur = cur->next)
    {
        ops(cur->data);
    }
}

void list_destory(LLIST *ptr)
{
    struct list_node *cur,*next;
    struct list_head *head = ptr;
    for(cur = head->head.next ; cur != &head->head ; cur = next)
    {
        next = cur->next;
        free(cur);
    }
    free(ptr);
}