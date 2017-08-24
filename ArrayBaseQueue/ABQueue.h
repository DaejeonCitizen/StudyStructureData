#ifndef __AB_QUEUE_H__
#define __AB_QUEUE_H__

#define TRUE	1
#define FALSE	0

#define LIST_LEN 50

typedef int Data;

typedef struct _arraylist
{
	Data arr[LIST_LEN];
	int front;
	int rear;
} List;

typedef List Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);
void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pa);

#endif