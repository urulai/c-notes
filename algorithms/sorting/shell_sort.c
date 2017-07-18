#include <stdio.h>
#include <stdlib.h>

#define SIZE(x) sizeof(x)/sizeof(x[0])

void shell_sort(int *arr, int size)
{
	int gaps[3] = {3, 2, 1};
	int gap, temp, gap_idx, idx_1, idx_2;

	for(gap_idx = 0; gap_idx < SIZE(gaps); ++gap_idx)
	{
		gap = gaps[gap_idx];

		for(idx_1 = 0; idx_1 < size; idx_1 += gap)
		{
			idx_2 = idx_1;

			while(idx_2 > 0 && arr[idx_2-gap] > arr[idx_2])
			{
				//swap elements.
				temp = arr[idx_2 - gap];
				arr[idx_2 -gap] = arr[idx_2];
				arr[idx_2] = temp;

				idx_2 -= gap;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("Usage: shell_sort <list_of_numbers>.\n");
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
	
	// Trigger shell sort
	shell_sort(arr, size);

	printf("After sort:\n");
	for(idx = 0; idx < size; idx++)
	{
		printf("%d ", arr[idx]);
	}
	printf("\n");

	return 0;
}
