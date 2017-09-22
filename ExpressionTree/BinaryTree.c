#include <stdlib.h>
#include <stdio.h>
#include "BinaryTree.h"

BTreeNode * MakeBTreeNode(void)
{
	BTreeNode * nd = (BTreeNode *)malloc(sizeof(BTreeNode));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

BTData GetData(BTreeNode * bt)
{
	return bt->data;
}

void SetData(BTreeNode * bt, BTData data)
{
	bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt)
{
	return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
	main->left = sub;
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
	main->right = sub;
}

void InorderTraverse(BTreeNode * bt, VisitFuncPtr Action)
{
	if (bt == NULL)
		return;
	InorderTraverse(bt->left, Action);
	Action(bt->data);
	InorderTraverse(bt->right, Action);
}

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr Action)
{
	if (bt == NULL)
		return;
	Action(bt->data);
	PreorderTraverse(bt->left, Action);
	PreorderTraverse(bt->right, Action);
}

void PostorderTraverse(BTreeNode * bt, VisitFuncPtr Action)
{
	if (bt == NULL)
		return;
	PostorderTraverse(bt->left, Action);
	PostorderTraverse(bt->right, Action);
	Action(bt->data);
}

void DeleteTree(BTreeNode * bt)
{
	if (bt == NULL)
		return;
	DeleteTree(bt->left);
	DeleteTree(bt->right);
	printf("Delete node data: %d\n", bt->data);
	free(bt);
}