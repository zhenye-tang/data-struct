#ifndef __DOUBLE_LIST_H__
#define __DOUBLE_LIST_H__

#define LLIST_FORWARD       1
#define LLIST_BACKWARD      2

typedef void list_op(void *);
typedef int cmp(const void *,const void *);

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
    int (*list_insert)(struct list_head *,const void *,int );
    int (*list_delete)(struct list_head *,const void *,cmp *);
    int (*list_fetch)(struct list_head *,const void *,cmp *,void *);
    void *(*list_find)(struct list_head *,const void *,cmp *);
    void (*list_travel)(struct list_head *, list_op *);
    void (*list_destory)(struct list_head *);
};
typedef struct list_head LLIST;

LLIST *list_create(int size);

#endif