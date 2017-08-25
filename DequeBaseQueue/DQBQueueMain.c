#include <stdio.h>
#include "DQBQueue.h"

int main(void)
{
	Queue q;
	Queue * pq = &q;
	int i;

	QueueInit(pq);

	for (i = 0; i < 10; i++)
		Enqueue(pq, i);

	while (!QIsEmpty(pq))
		printf("%d ", Dequeue(pq));
	printf("\n");

	return 0;
}