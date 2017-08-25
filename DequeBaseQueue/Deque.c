#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque * pdeq)
{
	pdeq->head = (Node *)malloc(sizeof(Node));
	pdeq->tail = (Node *)malloc(sizeof(Node));

	pdeq->head->next = pdeq->tail;
	pdeq->head->prev = NULL;
	pdeq->tail->next = NULL;
	pdeq->tail->prev = pdeq->head;
}

int DQIsEmpty(Deque * pdeq)
{
	return (pdeq->head->next == pdeq->tail) || (pdeq->tail->prev == pdeq->head) ? TRUE : FALSE;
}

void DQAddFirst(Deque * pdeq, Data data)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = pdeq->head->next;
	newNode->prev = pdeq->head;
	newNode->next->prev = newNode;

	pdeq->head->next = newNode;
}

void DQAddLast(Deque * pdeq, Data data)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = pdeq->tail->prev;
	newNode->next = pdeq->tail;
	newNode->prev->next = newNode;

	pdeq->tail->prev = newNode;
}

Data DQRemoveFirst(Deque * pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		puts("Deque memory error!");
		exit(-1);
	}
	Data delData = pdeq->head->next->data;
	Node * delNode = pdeq->head->next;

	pdeq->head->next = pdeq->head->next->next;
	pdeq->head->next->prev = pdeq->head;

	free(delNode);
	return delData;
}

Data DQRemoveLast(Deque * pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		puts("Deque memory error!");
		exit(-1);
	}
	Data delData = pdeq->tail->prev->data;
	Node * delNode = pdeq->tail->prev;

	pdeq->tail->prev = pdeq->tail->prev->prev;
	pdeq->tail->prev->next = pdeq->tail;

	free(delNode);
	return delData;
}

Data DQGetFirst(Deque * pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		puts("Deque memory error!");
		exit(-1);
	}
	return pdeq->head->next->data;
}

Data DQGetLast(Deque * pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		puts("Deque memory error!");
		exit(-1);
	}
	return pdeq->tail->prev->data;
}