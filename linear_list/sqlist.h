#ifndef __SQLIST_H__
#define __SQLIST_H__

#define SIZE    1024
typedef int     datatype;

struct node_st
{
    datatype  data[SIZE];
    int last;
};
typedef struct node_st sqlist;

void sqlist_create(sqlist **);
int sqlist_destory(sqlist *);
int sqlist_insert(sqlist *,int i,datatype *);;
int sqlist_delete(sqlist *, int i);
int sqlist_find(sqlist *, datatype *);
int sqlist_isempty(sqlist *);
int sqlist_set_empty(sqlist *);
int sqlist_get_num(sqlist *);
int sqlist_display(sqlist *);
int sqlist_union(sqlist *,sqlist *);

#endif //__SQLIST_H__