#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_LEN 10000

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int ChoicePivot(int arr[], int left, int right)
{
	int center = (right - left) / 2;
	int mididx;

	if ((arr[center] >= arr[left] && arr[left] >= arr[right]) ||
		(arr[right] >= arr[left] && arr[left] >= arr[center]))
		mididx = left;
	if ((arr[left] >= arr[center] && arr[center] >= arr[right]) ||
		(arr[right] >= arr[center] && arr[center] >= arr[left]))
		mididx = center;
	else
		mididx = right;

	Swap(arr, left, mididx);

	return arr[left];
}

int partition(int arr[], int left, int right)
{
	int pivot = ChoicePivot(arr, left, right);
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (pivot >= arr[low] && low <= right)
			low++;
		while (pivot < arr[high] && high >= (left)+1)
			high--;

		if (low <= high)
			Swap(arr, low, high);
	}
	Swap(arr, left, high);
	return high;
}

void QuickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int part = partition(arr, left, right);
		QuickSort(arr, left, part - 1);
		QuickSort(arr, part + 1, right);
	}
}
int main(void)
{
	int arr[ARR_LEN];
	int i;

	srand((unsigned)time(NULL));

	for (i = 0; i < ARR_LEN; i++)
		arr[i] = rand() % 50;

	QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (i = 0; i < ARR_LEN; i++)
	{
		printf("%3d", arr[i]);

		if ((i + 1) % 20 == 0)
			printf("\n");
	}

	printf("\n\n\n");
	return 0;
}