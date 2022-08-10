#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


queue_t queue_create()
{
    queue_t sq;
    sq = malloc(sizeof(*sq));
    if(sq == NULL)
        return NULL;
    
    sq->head = 0;
    sq->tail = 0;
    return sq;
}

int queue_enqueuq(queue_t queue,datatype *data)
{
    if((queue->tail + 1) % MAXSIZE == queue->head)
        return -1;
    
    queue->tail = (queue->tail + 1) % MAXSIZE;
    queue->data[queue->tail] = *data;

    return 0;
}

int queue_dequeue(queue_t queue,datatype *data)
{
    if(queue_isempty(queue))
        return -1;
    
    queue->head = (queue->head + 1) % MAXSIZE;

    *data = queue->data[queue->head];
    return 0; 
}

int queue_isempty(queue_t queue)
{
    return (queue->head == queue->tail);
}

void queue_travel(queue_t queue)
{
    if(queue_isempty(queue))
        return;

    int start = (queue->head + 1) % MAXSIZE;
    while(start != queue->tail)
    {
        printf("%d ",queue->data[start]);
        start = (start + 1) % MAXSIZE;
    }
    printf("%d\n",queue->data[start]);
}

void queue_clear(queue_t queue)
{
    queue->head = queue->tail;
}

void queue_destory(queue_t queue)
{
    free(queue);
}