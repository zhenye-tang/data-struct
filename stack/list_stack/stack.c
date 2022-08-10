#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

STACK *stack_create(int initsize)
{
    return list_create(initsize);
}

int stack_push(STACK *st,void *data)
{
    return list_insert(st,data,LLIST_FORWARD);
}

static int always_match(const void *p0,const void *p1)
{
    return 0;
}

int stack_pop(STACK *st,void *data)
{
    return list_fetch(st,(void *)0,always_match,data);
}

void stack_destory(STACK *st)
{
    list_destory(st);
}
