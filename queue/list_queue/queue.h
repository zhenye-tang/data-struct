#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "double_list.h"

typedef int datatype;

typedef LLIST QUEUE;

QUEUE *queue_create(int size);

int queue_enqueuq(QUEUE *,datatype *);
int queue_dequeue(QUEUE *,datatype *);
void queue_travel(QUEUE *queue,void (*ops)(void *));
void queue_destory(QUEUE *);
void queue_clear(QUEUE *);

#endif//