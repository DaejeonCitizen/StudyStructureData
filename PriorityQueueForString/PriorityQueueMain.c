#include <stdio.h>
#include "string.h"
#include "PriorityQueue.h"
#include "Strio.h"

int DataPriorityComp(char * str1, char * str2)
{
	return strlen(str2) - strlen(str1);
}
int main(void)
{
	PQueue pqueue;

	char tmpStr[STR_LEN];
	char * pStr;

	PQueueInit(&pqueue, DataPriorityComp);

	puts("If you want stop insert, insert \"stop\"");
	while (1)
	{
		printf("Insert string: ");
		fgets(tmpStr, sizeof(tmpStr), stdin);
		RemoveBSN(tmpStr);
		if (strcmp(tmpStr, "stop") == 0)
			break;

		PEnqueue(&pqueue, AllocStrLength(tmpStr));
	}

	while (!PQIsEmpty(&pqueue))
	{
		pStr = PDequeue(&pqueue);
		printf("Output string: %s\n", pStr);
		DeleteStrMemory(pStr);
	}
	return 0;
}