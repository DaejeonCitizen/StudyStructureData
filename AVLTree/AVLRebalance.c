#include <stdio.h>
#include "BinaryTree.h"

BTreeNode * RotateLL(BTreeNode * bst)
{
	BTreeNode * pNode = bst;
	BTreeNode * cNode = GetLeftSubTree(pNode);

	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
	ChangeRightSubTree(cNode, pNode);

	return cNode;
}

BTreeNode * RotateRR(BTreeNode * bst)
{
	BTreeNode * pNode = bst;
	BTreeNode * cNode = GetRightSubTree(pNode);

	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);
	
	return cNode;
}

BTreeNode * RotateLR(BTreeNode * bst)
{
	BTreeNode * pNode = bst;

	ChangeLeftSubTree(pNode, RotateRR(GetLeftSubTree(pNode)));
	return RotateLL(pNode);
}

BTreeNode * RotateRL(BTreeNode * bst)
{
	BTreeNode * pNode = bst;

	ChangeRightSubTree(pNode, RotateLL(GetRightSubTree(pNode)));
	return RotateRR(pNode);
}

int GetHeight(BTreeNode * bst)
{
	if (bst == NULL)
		return 0;

	int leftH;
	int rightH;

	leftH = GetHeight(GetLeftSubTree(bst));
	rightH = GetHeight(GetRightSubTree(bst));

	return leftH > rightH ? leftH + 1 : rightH + 1;
}

int GetHeightDiff(BTreeNode * bst)
{
	if (bst == NULL)
		return 0;
	
	int lsh, rsh;

	lsh = GetHeight(GetLeftSubTree(bst));
	rsh = GetHeight(GetRightSubTree(bst));
	return lsh - rsh;
}

BTreeNode * Rebalance(BTreeNode * Root)
{
	int hDiff = GetHeightDiff(Root);

	if (hDiff > 2)
		Root = GetHeightDiff(GetLeftSubTree(Root)) > 0 ? RotateLL(Root) : RotateLR(Root);
	if (hDiff < -1)
		Root = GetHeightDiff(GetRightSubTree(Root)) < 0 ? RotateRR(Root) : RotateRL(Root);

	return Root;
}