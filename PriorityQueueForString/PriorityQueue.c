#include "PriorityQueue.h"

void PQueueInit(PQueue * ppq, PriorityComp pc)
{
	HeapInit(ppq, pc);
}

int PQIsEmpty(PQueue * ppq)
{
	return HIsEmpty(ppq) ? TRUE : FALSE;
}

void PEnqueue(PQueue * ppq, PQData data)
{
	HInsert(ppq, data);
}

PQData PDequeue(PQueue * ppq)
{
	return HDelete(ppq);
}

PQData PQPeek(PQueue * ppq)
{
	PQData tmpData = HDelete(ppq);
	HInsert(ppq, tmpData);
	return tmpData;
}