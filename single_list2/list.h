#ifndef __LIST_H__
#define __LIST_H__

#define NAMESIZE  10

struct score_st
{
    int id;
    int math;
    int chinese;
    char name[NAMESIZE];
};

typedef struct score_st score;

struct node_st
{
    score data;
    struct node_st *next;
};

typedef struct node_st list;

int list_insert(list **,score *);
int list_insert_tail(list **,score *);
int list_show(list *);
int list_delete(list **);
score *list_find(list *,int);
int list_destory(list *);


#endif