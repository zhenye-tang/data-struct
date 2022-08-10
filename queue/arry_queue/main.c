#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    int i = 0;
    queue_t queue;
    int arry[] = {32,123,30,50,60};
    queue = queue_create();
    if(queue == NULL)
        exit(0);

    for(i = 0; i < sizeof(arry)/sizeof(*arry); i++)
    {
        queue_enqueuq(queue,&arry[i]);
    }

    queue_travel(queue);

    int data = 0;
    queue_dequeue(queue,&data);
    printf("data = %d\n",data);

    queue_clear(queue);

    queue_destory(queue);

    return 0;
}