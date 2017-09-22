#ifndef __LIST_BASE_STACK_H__
#define __LIST_BASE_STACK_H__

#include "BinaryTree.h"
#define TRUE	1
#define FALSE	0

#define LIST_LEN 50

typedef BTreeNode * Data;

typedef struct _listbasestack
{
	Data arr[LIST_LEN];
	int top;
} ListBaseStack;

typedef ListBaseStack Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);
void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

#endif