#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "BinaryTree.h"
#include "ListBaseStack.h"

BTreeNode * MakeExpTree(char exp[])
{
	Stack stack;
	Stack * pstack = &stack;
	BTreeNode * pnode;

	int i;

	StackInit(pstack);

	for (i = 0; exp[i] != '\0'; i++)
	{
		pnode = MakeBTreeNode();

		if (isdigit(exp[i]))
			SetData(pnode, exp[i] - '0');
		else
		{
			MakeRightSubTree(pnode, SPop(pstack));
			MakeLeftSubTree(pnode, SPop(pstack));
			SetData(pnode, exp[i]);
		}

		SPush(pstack, pnode);
	}

	return SPop(pstack);
}

int EvaluateExpTree(BTreeNode * bt)
{
	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
		return GetData(bt);

	int op1, op2;

	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch (GetData(bt))
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}

	return 0;
}

void ShowNodeData(int data)
{
	if (0 <= data && 9 >= data)
		printf("%d ", data);
		else
		printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode * bt)
{
	PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode * bt)
{
	if (bt == NULL)
		return;

	if (bt->left != NULL || bt->right != NULL)
		printf(" ( ");

	ShowInfixTypeExp(bt->left);
	ShowNodeData(bt->data);
	ShowInfixTypeExp(bt->right);

	if (bt->left != NULL || bt->right != NULL)
		printf(" ) ");
}

void ShowPostfixTypeExp(BTreeNode * bt)
{
	PostorderTraverse(bt, ShowNodeData);
}
