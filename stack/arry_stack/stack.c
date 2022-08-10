#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

node_stack *stack_create(void)
{
    node_stack *st;
    st = malloc(sizeof(*st));

    st->top = -1;
    return st;
}

int stack_isempty(node_stack *st)
{
    return (st->top == -1);
}

int stack_push(node_stack *st,datatype *data)
{
    if(st->top == (MAXSIZE-1))
        return -1;
    
    st->data[++st->top] = *data;
    return 0;
}

int stack_pop(node_stack *st,datatype *data)
{
    if(stack_isempty(st))
        return -1;
    
    *data = st->data[st->top--];
    return 0;
}

int stack_top(node_stack *st,datatype *data)
{
      if(stack_isempty(st))
        return -1;
    
    *data = st->data[st->top];
    return 0;
}

void stack_travel(node_stack *st)
{
    int i = 0;
    if(st->top == -1)
        return ;
    

    for(; i <= st->top; i++)
        printf("%d ",st->data[i]);
    
    printf("\n");
}

int stack_destory(node_stack *st)
{
    free(st);
}