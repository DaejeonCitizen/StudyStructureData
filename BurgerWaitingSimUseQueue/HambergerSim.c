#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CircularQueue.h"

#define CUS_COME_SEC 15

#define TIMER 3600

enum BURGER { CHE_BUR, BUL_BUR, DUB_BUR }; // burger constant num

enum BUR_SEC { CHE_SEC = 12, BUL_SEC = 15, DUB_SEC = 24}; // burger making time(sec)

int main(void)
{
	int makeProc = 0;
	int cheOrder = 0, bulOrder = 0, dubOrder = 0;
	int sec;
	int howFull;
	int repeat;
	int reCnt;
	int success = 0;

	Queue que;
	Queue * pque = &que;

	srand((unsigned)time(NULL));

	printf("How many repeat?"); scanf_s("%d", &repeat);

	for (reCnt = 0; reCnt < repeat; reCnt++)
	{
		QueueInit(pque);

		for (sec = 0; sec < TIMER; sec++)
		{
			if (sec % CUS_COME_SEC == 0)
			{
				switch (rand() % 3)
				{
				case CHE_BUR:
					howFull = Enqueue(pque, CHE_SEC);
					cheOrder++;
					break;
				case BUL_BUR:
					howFull = Enqueue(pque, BUL_SEC);
					bulOrder++;
					break;
				case DUB_BUR:
					howFull = Enqueue(pque, DUB_SEC);
					dubOrder++;
					break;
				}
			}
			if (howFull == FALSE)
				break;
			if (makeProc <= 0 && !QIsEmpty(pque))
				makeProc = Dequeue(pque);

			makeProc--;
		}
		if (howFull == TRUE)
		{
			printf("---------------------------------\n");
			printf("%d cycle Simulation Report!\n", reCnt + 1);
			printf(" - Cheese burger: %d\n", cheOrder);
			printf(" - Bulgogi burger: %d\n", bulOrder);
			printf(" - Double burger: %d\n", dubOrder);
			printf(" - Waiting room size: %d\n", QUE_LEN);
			printf("---------------------------------\n\n\n");
			success++;
		}
		else
		{
			printf("---------------------------------\n");
			printf("%d cycle Simulation Report!\n", reCnt + 1);
			printf("---------------------------------\n\n\n");
		}

		cheOrder = 0, bulOrder = 0, dubOrder = 0;
	}
	printf("------------Statistics------------\n");
	printf("Success: %d, Failed: %d\n", success, repeat - success);
	printf("Probable: %g%%\n", ((double)success / (double)repeat) * 100);
	printf("----------------------------------\n");

	return 0;
}