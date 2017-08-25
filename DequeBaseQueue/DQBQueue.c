#include <stdio.h>
#include <stdlib.h>
#include "DQBQueue.h"

void QueueInit(Queue * pq)
{
	DequeInit(pq);
}

int QIsEmpty(Queue * pq)
{
	return DQIsEmpty(pq) ? TRUE : FALSE;
}

void Enqueue(Queue * pq, Data data)
{
	DQAddFirst(pq, data);
}

Data Dequeue(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		puts("Queue memory error!");
		exit(-1);
	}
	return DQRemoveLast(pq);
}

Data QPeek(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		puts("Queue memory error!");
		exit(-1);
	}
	return DQGetLast(pq);
}