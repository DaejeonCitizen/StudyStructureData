#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LLBQueue.h"

int main(void)
{
	Queue queue;
	Queue * pq = &queue;
	int i;
	srand((unsigned)time(NULL));

	QueueInit(pq);

	for (i = 0; i < 500; i++)
		Enqueue(pq, i);

	i = 1;
	while (!QIsEmpty(pq))
	{
		printf("%-3d ", Dequeue(pq));
		if (!(i % 10))
			printf("\n");
		i++;
	}

	return 0;
}