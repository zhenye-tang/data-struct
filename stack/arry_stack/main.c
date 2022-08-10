#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    int i = 0;
    datatype arry[] = {12,4,123,16,17,89};
    datatype data;
    node_stack *stack = stack_create();
    for(; i < sizeof(arry)/sizeof(*arry); i++)
        stack_push(stack,&arry[i]);

    stack_travel(stack);

    stack_pop(stack,&data);
    printf("pop data %d\n",data);

    stack_travel(stack);
    stack_destory(stack);
}