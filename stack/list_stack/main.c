#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define NAMESIZW 32

struct student
{
    int id;
    int math;
    char name[NAMESIZW];
};

void print(struct student *data)
{
    printf("id: %d math: %d name: %s\n",data->id,data->math,data->name);
}

int main()
{
    int i = 0;
    struct student tzy;
    STACK *stack = stack_create(sizeof(struct student));
    if(!stack)
        exit(0);

    for(i = 0; i < 7; i++)
    {
        tzy.id = i;
        tzy.math = rand()%100;
        snprintf(tzy.name,NAMESIZW,"stu%d",i);
        stack_push(stack,&tzy);
        print(&tzy);
    }

    printf("\n");

    for(i = 0; i < 7; i++)
    {
        if(stack_pop(stack,&tzy) < 0)
            exit(0);
        print(&tzy);
    }

    stack_destory(stack);
    return 0;
}