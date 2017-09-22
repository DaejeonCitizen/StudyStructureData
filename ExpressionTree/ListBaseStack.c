#include <stdio.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack)
{
	pstack->top = -1;
}

int SIsEmpty(Stack * pstack)
{
	return pstack->top == -1 ? TRUE : FALSE;
}

void SPush(Stack * pstack, Data data)
{
	if (pstack->top >= LIST_LEN - 1)
	{
		puts("Stack is full");
		return;
	}
	pstack->arr[++(pstack->top)] = data;
}

Data SPop(Stack * pstack)
{
	if (SIsEmpty(pstack))
	{
		puts("No data in stack");
		return NULL;
	}
	return pstack->arr[(pstack->top)--];
}

Data SPeek(Stack * pstack)
{
	if (SIsEmpty(pstack))
	{
		puts("No data in stack");
		return NULL;
	}
	return pstack->arr[pstack->top];
}