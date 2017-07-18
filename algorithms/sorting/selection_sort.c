#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *arr, int size)
{
	int temp, idx_1, idx_2, min_idx;

	for(idx_1 = 0; idx_1 < (size - 1); idx_1++)
	{

		min_idx = idx_1;

		for(idx_2 = (idx_1 + 1); idx_2 < size; idx_2++)
		{
			if(arr[idx_2] < arr[min_idx])
			{
				min_idx = idx_2;
			}
		}

		//swap min_idx with idx_1
		if(idx_1 != min_idx)
		{
			temp = arr[idx_1];
			arr[idx_1] = arr[min_idx];
			arr[min_idx] = temp;
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("Usage: selection_sort <list_of_numbers>.\n");
		return 1; 
	}

	printf("Number of elements: %d.\n", argc-1);
	int size = argc-1;
	int arr[size];
	
	int idx= 0;
	for(; idx < size; idx++)
	{
		arr[idx] = atoi(argv[idx+1]);
	}
	
	printf("Before sort:\n");
	for(idx = 0; idx < size; idx++)
	{
		printf("%d ", arr[idx]);
	}
	printf("\n");
	
	// Trigger selection sort
	selection_sort(arr, size);

	printf("After sort:\n");
	for(idx = 0; idx < size; idx++)
	{
		printf("%d ", arr[idx]);
	}
	printf("\n");

	return 0;
}