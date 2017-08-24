#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ABQueue.h"

int main(void)
{
	Queue queue;
	int i;
	srand((unsigned)time(NULL));

	QueueInit(&queue);

	for (i = 0; i < 30; i++)
		Enqueue(&queue, rand() % 50);

	while(!QIsEmpty(&queue))
		printf("%-3d ", Dequeue(&queue));
	printf("\n");

	for (i = 0; i < 30; i++)
		Enqueue(&queue, rand() % 50);

	while (!QIsEmpty(&queue))
		printf("%-3d ", Dequeue(&queue));
	printf("\n");

	return 0;
}