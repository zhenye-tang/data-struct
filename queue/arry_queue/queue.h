#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef int datatype;

#define MAXSIZE   5

struct queue
{
    datatype data[MAXSIZE];
    int tail;
    int head;
    /* data */
};

typedef struct queue *queue_t;

queue_t queue_create();

int queue_enqueuq(queue_t,datatype *);
int queue_dequeue(queue_t,datatype *);

int queue_isempty(queue_t);

void queue_travel(queue_t);

void queue_destory(queue_t);

void queue_clear(queue_t queue);

#endif//