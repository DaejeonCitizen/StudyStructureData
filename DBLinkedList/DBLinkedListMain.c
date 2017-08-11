#include <stdio.h>
#include "DBLinkedList.h"

int main(void)
{
	// creation variable
	List list;
	List * plist = &list;
	Data data;

	// init list
	ListInit(plist);

	// insert data
	LInsert(plist, 1); LInsert(plist, 2);
	LInsert(plist, 3); LInsert(plist, 4);
	LInsert(plist, 5); LInsert(plist, 6);
	LInsert(plist, 7); LInsert(plist, 8);

	// print all data
	printf("Total num of data : %d\n", list.numOfData);
	if (LFirst(plist, &data))
	{
		printf("%d ", data);

		while (LNext(plist, &data))
			printf("%d ", data);
		while (LPrevious(plist, &data))
			printf("%d ", data);

		printf("\n");
	}
	
	// remove multiples
	if (LFirst(plist, &data))
	{
		if ((data % 2) == 0)
			LRemove(plist);
		while (LNext(plist, &data))
			if ((data % 2) == 0)
				LRemove(plist);
	}

	// print all data after deleted data
	if (LFirst(plist, &data))
	{
		printf("%d ", data);
		while (LNext(plist, &data))
			printf("%d ", data);
		while (LNext(plist, &data))
			printf("%d ", data);

		printf("\n\n");
	}

	return 0;
}