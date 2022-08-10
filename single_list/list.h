#ifndef __LIST_H__
#define __LIST_H__

typedef int datatype;

struct _node
{
    datatype data;
    struct _node *next;
};

typedef struct _node list;

list *list_creat();
int list_insert_at(list *,int i, datatype *);
int list_ordef_insert(list *,datatype *);
int list_delete_at(list *,int i,datatype *);
int list_delete(list *,datatype *);
int list_isempty(list *);
int list_destory(list *);
int list_display(list *);
#endif