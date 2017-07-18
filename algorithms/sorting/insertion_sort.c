#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *arr, int size)
{
	int temp, idx_1, idx_2;

	for(idx_1 = 1; idx_1 < size; idx_1++)
	{
		idx_2 = idx_1;

		while(idx_2 > 0 && arr[idx_2-1] > arr[idx_2])
		{
			// swao elements.
			temp = arr[idx_2-1];
			arr[idx_2-1] = arr[idx_2];
			arr[idx_2] = temp;
			
			idx_2--;
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("Usage: insertion_sort <list_of_numbers>.\n");
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
	insertion_sort(arr, size);

	printf("After sort:\n");
	for(idx = 0; idx < size; idx++)
	{
		printf("%d ", arr[idx]);
	}
	printf("\n");

	return 0;
}
