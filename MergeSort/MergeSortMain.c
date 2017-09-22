#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SimpleHeap.h"

#define ARR_LEN 1000

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int LFIdx = left;
	int RFIdx = mid + 1;
	int taIdx = 0;
	int i;

	int * tmpArr = (int *)malloc(sizeof(int) * (right - left + 1));

	while (LFIdx <= mid && RFIdx <= right)
		tmpArr[taIdx++] = arr[LFIdx] <= arr[RFIdx] ? arr[LFIdx++] : arr[RFIdx++];

	if (LFIdx > mid)
		for (i = RFIdx; i <= right; i++, taIdx++)
			tmpArr[taIdx] = arr[i];
	else
		for (i = LFIdx; i <= mid; i++, taIdx++)
			tmpArr[taIdx] = arr[i];

	for (i = left, taIdx = 0; i <= right; i++, taIdx++)
		arr[i] = tmpArr[taIdx];

	free(tmpArr);
}
void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		MergeTwoArea(arr, left, mid, right);
	}
}
int main(void)
{
	int arr[ARR_LEN];
	int i;
	srand((unsigned)time(NULL));

	for (i = 0; i < ARR_LEN; i++)
		arr[i] = rand() % 100;

	for (i = 0; i < ARR_LEN; i++)
	{
		printf("%3d", arr[i]);

		if ((i + 1) % 20 == 0)
			printf("\n");
	}
	MergeSort(arr, 0, (sizeof(arr) / sizeof(int)) - 1);

	for (i = 0; i < ARR_LEN; i++)
	{
		printf("%3d", arr[i]);

		if ((i + 1) % 20 == 0)
			printf("\n");
	}

	printf("\n\n\n");
	return 0;
}