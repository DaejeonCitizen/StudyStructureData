#include <string.h>
#include <stdlib.h>
#include "Strio.h"

void RemoveBSN(char str[])
{
	str[strlen(str) - 1] = 0;
}

char * AllocStrLength(char str[])
{
	char * rtnStr = (char *)malloc(strlen(str) + 1);
	strcpy_s(rtnStr, strlen(str) + 1, str);
	return rtnStr;
}

void DeleteStrMemory(char * str)
{
	free(str);
}