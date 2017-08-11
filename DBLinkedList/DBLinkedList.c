#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List * plist)
{
	plist->head = (Node *)malloc(sizeof(Node));
	plist->tail = (Node *)malloc(sizeof(Node));

	plist->head->next = plist->tail;
	plist->head->prev = NULL;

	plist->tail->next = NULL;
	plist->tail->prev = plist->head;

	plist->cur = NULL;
	plist->numOfData = 0;
}

void LInsert(List * plist, Data data)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = plist->tail->prev;
	newNode->next = plist->tail;

	plist->tail->prev->next = newNode;
	plist->tail->prev = newNode;

	(plist->numOfData)++;
}
int LFirst(List * plist, Data * data)
{
	if (plist->head->next == NULL)
		return FALSE;
	plist->cur = plist->head->next;
	*data = plist->cur->data;

	return TRUE;
}

int LNext(List * plist, Data * data)
{
	if (plist->cur->next->next == NULL)
		return FALSE;
	plist->cur = plist->cur->next;
	*data = plist->cur->data;

	return TRUE;
}

int LPrevious(List * plist, Data * data)
{
	if (plist->cur->prev->prev == NULL)
		return FALSE;
	plist->cur = plist->cur->prev;
	*data = plist->cur->data;

	return TRUE;
}

Data LRemove(List * plist)
{
	Data data = plist->cur->data;
	Node * dtemp = plist->cur->prev;

	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;
	free(plist->cur);

	plist->cur = dtemp;

	(plist->numOfData)--;

	return data;
}

int LCount(List * plist)
{
	return plist->numOfData;
}