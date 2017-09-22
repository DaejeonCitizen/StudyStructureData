#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "SimpleHeap.h"

#define TRUE	1
#define FALSE	0

typedef HData PQData;
typedef Heap PQueue;

void PQueueInit(PQueue * ppq, PriorityComp pc);
int PQIsEmpty(PQueue * ppq);

void PEnqueue(PQueue * ppq, PQData data);
PQData PDequeue(PQueue * ppq);
PQData PQPeek(PQueue * ppq);

#endif