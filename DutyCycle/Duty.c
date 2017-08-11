#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Duty.h"

Staff * CreationStaffInfo(char * name, int num)
{
	Staff * info = (Staff *)malloc(sizeof(Staff));

	info->name = (char *)malloc(strlen(name) + 1);
	strcpy_s(info->name, strlen(name) + 1, name);
	info->num = num;

	return info;
}

void FreeStaffInfo(Staff * pinfo)
{
	free(pinfo->name);
	free(pinfo);
}

void PrintDuty(Staff * pinfo)
{
	printf("%s -> ", pinfo->name);
}