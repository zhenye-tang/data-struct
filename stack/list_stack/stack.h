#ifndef __STACK_H__
#define __STACK_H__

#include "double_list.h"

typedef  LLIST STACK;

STACK *stack_create(int);
void stack_destory(STACK *);
int stack_push(STACK *,void *);
int stack_pop(STACK *,void *);


#endif//__STACK_H__