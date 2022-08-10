#ifndef __STACK_H__
#define __STACK_H__

typedef int     datatype;
#define MAXSIZE         6

struct _node_stack
{
    datatype data[MAXSIZE];
    int top;
    /* data */
};

typedef struct _node_stack node_stack;

node_stack *stack_create(void);

int stack_isempty(node_stack *);

int stack_push(node_stack *,datatype *);
int stack_pop(node_stack *,datatype *);

int stack_top(node_stack *,datatype *);

void stack_travel(node_stack *);

int stack_destory(node_stack *);




#endif//__STACK_H__