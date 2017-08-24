#include <stdlib.h>
#include <stdio.h>
#include "LLBStack.h"

void StackInit(Stack * pstack)
{
	pstack->head = NULL;
}

int SIsEmpty(Stack * pstack)
{
	return pstack->head == NULL ? TRUE : FALSE;
}

void SPush(Stack * pstack, Data data)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pstack->head;
	pstack->head = newNode;
}

Data SPop(Stack * pstack)
{
	if (SIsEmpty(pstack))
	{
		puts("Stack memory error!");
		exit(-1);
	}

	Data tdata = pstack->head->data;
	Node * delNode = pstack->head;
	
	pstack->head = pstack->head->next;
	free(delNode);

	return tdata;
}

Data SPeek(Stack * pstack)
{
	if (SIsEmpty(pstack))
	{
		puts("Stack memory error!");
		exit(-1);
	}

	return pstack->head->data;
}