#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LLBStack.h"

int GetOpPrec(char op);
void FillExp(char exp[], char temp);
void ConvertToRPNExp(Stack * pstack, char arr[], char exp[]);

int main(void)
{
	Stack stack;
	Stack * pstack = &stack;
	char * arr = "(((4-2)*(2+4)*2)*2)+3";
	char exp[50];

	StackInit(pstack);


	ConvertToRPNExp(pstack, arr, exp);

	printf("%s", exp);

	return 0;

}

int GetOpPrec(char op)
{
	switch (op)
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	default:
		return -1;
	}
}

void FillExp(char exp[], char temp)
{
	static int i;
	exp[i++] = temp;
}

void ConvertToRPNExp(Stack * pstack, char arr[], char exp[])
{
	int i;
	int op;
	int top;
	char temp;

	for (i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] == ')')
		{
			while (!SIsEmpty(pstack))
			{
				temp = SPop(pstack);
				if (temp == '(')
					break;
				FillExp(exp, temp);
			}
		}
		else if (arr[i] == '\0')
		{
			while (!SIsEmpty(pstack))
				FillExp(exp, SPop(pstack));
		}
		else
		{
			if ((arr[i] >= '0') && (arr[i] <= +'9'))
				FillExp(exp, arr[i]);
			else
			{
				op = GetOpPrec(arr[i]);

				if (SIsEmpty(pstack))
					SPush(pstack, arr[i]);
				else
				{
					if ((top = GetOpPrec(SPeek(pstack))) == -1)
					{
						puts("wrong expression!");
						return;
					}

					if ((op == top) && (top != op))
						FillExp(exp, arr[i]);
					else if (op > top)
						SPush(pstack, arr[i]);
					else if (op < top)
					{
						while (!SIsEmpty(pstack))
							FillExp(exp, SPop(pstack));
						SPush(pstack, arr[i]);
					}
				}
			}
		}
	}

	while (!SIsEmpty(pstack))
		FillExp(exp, SPop(pstack));
	FillExp(exp, '\0');
}