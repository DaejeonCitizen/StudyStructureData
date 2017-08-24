#include <stdio.h>
#include <stdlib.h>
#include "ABQueue.h"

void QueueInit(Queue * pq)
{
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue * pq)
{
	return (pq->front) == (pq->rear) ? TRUE : FALSE;
}

int NextPosIndex(int pos)
{
	return pos == LIST_LEN - 1 ? 0 : pos + 1;
}

void Enqueue(Queue * pq, Data data)
{
	if (NextPosIndex(pq->rear) == pq->front)
	{
		puts("memory is full, you don't insert data");
		return;
	}
	pq->arr[pq->rear = NextPosIndex(pq->rear)] = data;
}

Data Dequeue(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		puts("Data does not exist");
		exit(-1);
	}
	return pq->arr[pq->front = NextPosIndex(pq->front)];
}

Data Qpeek(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		puts("Data does net exist");
		exit(-1);
	}
	return pq->arr[NextPosIndex(pq->front)];
}