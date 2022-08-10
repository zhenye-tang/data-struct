#ifndef __DOUBLE_LIST_H__
#define __DOUBLE_LIST_H__

#define LLIST_FORWARD       1
#define LLIST_BACKWARD      2

typedef void LLIST;
typedef void list_op(void *);
typedef int cmp(const void *,const void *);

LLIST *list_create(int size);
int list_insert(LLIST *,const void *data,int mode);
int list_delete(LLIST *,const void *,cmp *);
int list_fetch(LLIST *,const void *,cmp *,void *data);
void *list_find(LLIST *,const void *,cmp *);
void list_travel(LLIST *, list_op *);
void list_destory(LLIST *);

#endif