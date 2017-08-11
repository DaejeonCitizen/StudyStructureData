#include <stdio.h>
#include <string.h>
#include "CLinkedList.h"
#include "Duty.h"

Staff * HowDutyTurn(List * plist, char * name, int num, int day);

int main(void)
{
	List list;
	List * plist = &list;
	Data data;
	int i = 0;

	ListInit(plist);

	LInsert(plist, CreationStaffInfo("Kim", 1001));
	LInsert(plist, CreationStaffInfo("Hong", 1002));
	LInsert(plist, CreationStaffInfo("Park", 1003));
	LInsert(plist, CreationStaffInfo("Jeon", 1004));

	printf("---Printf duty cycle---\n\n");
	if (LFirst(plist, &data))
	{
		PrintDuty(data);
		while (LNext(plist, &data) && (i < 30))
		{
			PrintDuty(data);
			i++;
		}
		printf("\n");
	}

	data = HowDutyTurn(plist, "Hong", 1002, 7);
	printf("after 7 days tudy of staff %s : %s(%d) \n", "Kim", data->name, data->num);

	if (LFirst(plist, &data))
	{
		data = LRemove(plist);
		FreeStaffInfo(data);
		while (LNext(plist, &data))
		{
			data = LRemove(plist);
			FreeStaffInfo(data);
			if (plist->numOfData == 0)
				break;
		}

	}

	return 0;
}

Staff * HowDutyTurn(List * plist, char * name, int num, int day)
{
	int i = 1;
	Data tempdata;
	if (LFirst(plist, &tempdata))
	{
		if ((!strcmp(tempdata->name, name)) && (tempdata->num == num))
		{
			while (i < day)
			{
				LNext(plist, &tempdata);
				i++;
			}
		}
		else
		{
			while (LNext(plist, &tempdata) && i < day)
			{
				if ((!strcmp(tempdata->name, name)) && (tempdata->num == num))
					while (i < day)
					{
						LNext(plist, &tempdata);
						i++;
					}
			}
		}
	}

	return tempdata;
}