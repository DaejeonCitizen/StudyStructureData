#ifndef __LLB_STACK_H__
#define __LLB_STACK_H__

#define TRUE	1
#define FALSE	0

typedef char Data;

typedef struct _node
{
	Data data;
	struct _node * next;
} Node;

typedef struct _linkedlist
{
	Node * head;
} LinkedList;

typedef LinkedList Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);
void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

#endif