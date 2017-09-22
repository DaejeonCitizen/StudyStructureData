#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BinarySearchTree.h"

#define NOD 999

void ShowData(BSTData data)
{
	printf("%4d", data);
}

int main(void)
{
	BTreeNode * bstRoot;
	BTreeNode * sNode;
	int i;

	BSTMakeAndInit(&bstRoot);

	srand((unsigned)time(NULL));

	for (i = 0; i < NOD; i++)
	{
		bstRoot = BSTInsert(&bstRoot, i);
	}

	for (i = 0; i < NOD; i++)
	{
		sNode = BSTSearch(bstRoot, i);
		if (sNode == NULL)
			printf("failed search!\n");
		else
			printf("Success search key: %d\n", BSTGetNodeData(sNode));
	}

	for (i = 0; i < NOD; i++)
	{
		sNode = BSTDelete(&bstRoot, i * 2);
		free(sNode);
	}

	BSTShowAll(bstRoot, ShowData);

	return 0;
}