#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#define TRUE	1
#define FALSE	0

#define QUE_LEN 25

typedef int Data;

typedef struct _arrayqueue
{
	Data qArr[QUE_LEN];
	int f;
	int r;
} ArrayQueue;

typedef ArrayQueue Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);
int Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

#endif