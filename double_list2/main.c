#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

#define NAMESIZE  32

struct score_st
{
    int id;
    int math;
    int chinese;
    char name[NAMESIZE];
};

void print(void *ptr)
{
    struct score_st *stu = ptr;
    printf("%d %s %d %d\n",stu->id,stu->name,stu->chinese,stu->math);
}

static int id_find(const void *key,const void *dat)
{
    const struct score_st *data = dat;
    const int *id = key;
    return (*id - data->id);
}

int main(int argc, char *argv[])
{
    int i = 0;
    int id = 5,ret;
    LLIST *handler;
    struct score_st stu;
    handler = list_create(sizeof(struct score_st));

    for(i = 0 ;i < 7; i++)
    {
        stu.id = i;
        snprintf(stu.name,NAMESIZE,"stu%d",i);
        stu.chinese = rand() %101;
        stu.math = rand()%101;
        //list_insert(handler,&stu,LLIST_BACKWARD);
        list_insert(handler,&stu,LLIST_BACKWARD);
    }
    
    list_travel(handler,print);

    struct score_st *data = list_find(handler,&id,id_find);
    if(data != NULL)
    {
        printf("\n");
        print(data);
        printf("\n");
    }
    else printf("not find\n");
    struct score_st fetch_data;

    ret = list_delete(handler,&id,id_find);
    if(ret == 0)
    {
        list_travel(handler,print);
        printf("\n");
    }
    else printf("delete fail\n");
    id = 3;
    ret = list_fetch(handler,&id,id_find,&fetch_data);
    if(ret == 0)
    {
        print(&fetch_data);
        printf("\n");
        list_travel(handler,print);
    }
    else printf("fetch fail\n");

    list_destory(handler);

    return 0;
}