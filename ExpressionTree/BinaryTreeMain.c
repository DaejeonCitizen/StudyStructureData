#include <stdio.h>
#include "BinaryTree.h"
#include "ExprssionTree.h"

int main(void)
{
	char exp[] = "1122*++";

	BTreeNode * eTree = MakeExpTree(exp);

	printf("Pre fix type: ");
	ShowPrefixTypeExp(eTree); putchar('\n');

	printf("In fix type: ");
	ShowInfixTypeExp(eTree); putchar('\n');

	printf("Post fix type: ");
	ShowPostfixTypeExp(eTree); putchar('\n');

	printf("result: %d \n", EvaluateExpTree(eTree));

	return 0;
}