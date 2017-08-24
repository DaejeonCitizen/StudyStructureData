#ifndef __LLB_QUEUE_H__
#define __LLB_QUEUE_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node * next;
} Node;

typedef struct _linkedlist
{
	Node * tail;
	int numOfData;
} LinkedList;

typedef LinkedList Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);
void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

#endif