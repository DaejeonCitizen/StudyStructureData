#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue * pq)
{
	pq->f = 0;
	pq->r = 0;
}

int QIsEmpty(Queue * pq)
{
	return pq->f == pq->r ? TRUE : FALSE;
}

int NextPosIdx(int pos)
{
	return pos == QUE_LEN - 1 ? 0 : pos + 1;
}

int Enqueue(Queue * pq, Data data)
{
	if (pq->f == NextPosIdx(pq->r))
		return FALSE;

	pq->qArr[pq->r = NextPosIdx(pq->r)] = data;

	return TRUE;
}

Data Dequeue(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		puts("Queue memory error");
		exit(-1);
	}

	return pq->qArr[pq->f = NextPosIdx(pq->f)];
}

Data QPeek(Queue *pq)
{
	if (QIsEmpty(pq))
	{
		puts("Queue memory error");
		exit(-1);
	}

	return pq->qArr[NextPosIdx(pq->f)];
}