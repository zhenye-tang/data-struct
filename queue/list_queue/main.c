#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define NAMESIZE        32

struct student
{
    int id;
    int math;
    char name[NAMESIZE];
};

void print(void *data)
{
    struct student *stu = data;
    printf("id:%d math:%d name:%s\n",stu->id,stu->math,stu->name);
}

int main()
{
    struct student tzy;
    int i = 0;
    QUEUE *queue = queue_create(sizeof(tzy));
    if(queue == NULL)
        exit(0);

    for(i = 0; i < 5; i++)
    {
        tzy.id = i;
        tzy.math = rand()%101;
        snprintf(tzy.name,NAMESIZE,"stu%d",i);
        queue_enqueuq(queue,(void *)&tzy);
    }

    queue_travel(queue,print);
    struct student tzy1;
    queue_dequeue(queue,(void *)&tzy1);

    printf("dequeue id:%d math:%d name:%s\n",tzy1.id,tzy1.math,tzy1.name);

    queue_travel(queue,print);
    queue_destory(queue);

    return 0;
}