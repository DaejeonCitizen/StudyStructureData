#ifndef __DUTY_H__
#define __DUTY_H__

typedef struct _staff
{
	char * name;
	int num;
} Staff;

Staff * CreationStaffInfo(char * name, int num);
void FreeStaffInfo(Staff * pinfo);
void PrintDuty(Staff * pinfo);

#endif