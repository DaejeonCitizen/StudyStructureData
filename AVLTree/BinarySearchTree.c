#include <stdlib.h>
#include <stdio.h>
#include "BinaryTree.h"
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
	return GetData(bst);
}

BTreeNode * BSTInsert(BTreeNode ** pRoot, BSTData data)
{
	if (*pRoot == NULL)
	{
		*pRoot = MakeBTreeNode();
		SetData(*pRoot, data);
	}
	else if (data < GetData(*pRoot))
	{
		BSTInsert(&((*pRoot)->left), data);
		*pRoot = Rebalance(*pRoot);
	}
	else if (data > GetData(*pRoot))
	{
		BSTInsert(&((*pRoot)->right), data);
		*pRoot = Rebalance(*pRoot);
	}
	else
		return NULL;
	return *pRoot;
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
	BTreeNode * cNode = bst;
	BSTData cd;

	while (cNode != NULL)
	{
		cd = GetData(cNode);

		if (target == cd)
			return cNode;
		else if (target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}
	return NULL;
}

BTreeNode * BSTDelete(BTreeNode ** pRoot, BSTData target)
{
	BTreeNode * pvRoot = MakeBTreeNode();
	BTreeNode * pNode = pvRoot;
	BTreeNode * cNode = *pRoot;
	BTreeNode * dNode;

	ChangeRightSubTree(pvRoot, *pRoot);

	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;
		
		cNode = target < GetData(cNode) ? GetLeftSubTree(cNode) : GetRightSubTree(cNode);
	}

	if (cNode == NULL)
		return NULL;

	dNode = cNode;

	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		GetLeftSubTree(pNode) == dNode ? RemoveLeftSubTree(pNode) : RemoveRightSubTree(pNode);
	}

	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode * dcNode;

		dcNode = GetLeftSubTree(dNode) != NULL ? GetLeftSubTree(dNode) : GetRightSubTree(dNode);
		
		GetLeftSubTree(pNode) != NULL ? ChangeLeftSubTree(pNode, dcNode) : ChangeRightSubTree(pNode, dcNode);
	}
	else
	{
		BTreeNode * mNode = GetRightSubTree(dNode);
		BTreeNode * mpNode = dNode;
		BSTData delData;

		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		delData = GetData(dNode);
		SetData(dNode, GetData(mNode));

		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData);
	}

	if (GetRightSubTree(pvRoot) != *pRoot)
		*pRoot = GetRightSubTree(pvRoot);

	free(pvRoot);
	*pRoot = Rebalance(*pRoot);
	return dNode;
}

void BSTShowAll(BTreeNode * bst, VisitFuncPtr action)
{
	if (bst == NULL) {
		printf("Data not found!");
		return;
	}
	InorderTraverse(bst, action);
}