#include <stdio.h>
#include <stdlib.h>
#include "LLBQueue.h"

void QueueInit(Queue * pq)
{
	pq->tail = NULL;
	pq->numOfData = 0;
}

int QIsEmpty(Queue * pq)
{
	return pq->numOfData == 0 ? TRUE : FALSE;
}

void Enqueue(Queue * pq, Data data)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	if (QIsEmpty(pq))
	{
		pq->tail = newNode;
		pq->tail->next = newNode;
	}
	else
	{
		newNode->next = pq->tail->next;
		pq->tail->next = newNode;
		pq->tail = newNode;
	}
	(pq->numOfData)++;
}

Data Dequeue(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		puts("file does not exist");
		exit(-1);
	}
	Data tdata = pq->tail->next->data;
	Node * delNode = pq->tail->next;

	pq->tail->next = pq->tail->next->next;
	free(delNode);

	(pq->numOfData)--;

	return tdata;
}

Data QPeek(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		puts("file does not exist");
		exit(-1);
	}

	return pq->tail->next->data;
}