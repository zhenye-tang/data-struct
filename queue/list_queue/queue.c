#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

QUEUE *queue_create(int size)
{
    return list_create(size);
}

int queue_enqueuq(QUEUE *queue,datatype *data)
{
    return list_insert(queue,data,LLIST_BACKWARD);
}

static int alaway_match(const void *key,const void *data)
{
    return 0;
}

int queue_dequeue(QUEUE *queue,datatype *data)
{
    return list_fetch(queue,(void *)0,alaway_match,data);
}

void queue_travel(QUEUE *queue,void (*ops)(void *))
{
    list_travel(queue, ops);
}

void queue_destory(QUEUE *queue)
{
    list_destory(queue);
}