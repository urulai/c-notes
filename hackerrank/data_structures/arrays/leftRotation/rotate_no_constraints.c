#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void leftRotate(int *arr, int n, int d)
{
	int idx = 0;
	int *dup = (int *) calloc(n ,sizeof(int));
	int *swapPtr = NULL;
	
	while(d > 0)
	{
		int idx = 0;
		for( ;idx < n; idx++)
		{
			if(idx == 0)
				dup[n-1] = arr[idx];
			else 
				dup[idx-1] = arr[idx];
		}
		// Copy dup to original array.
		swapPtr = arr;
		arr = dup;
		dup = swapPtr;
		
		--d;
	}

	for( ; idx < n; idx++)
	{
		if(idx != n - 1)
			printf("%d ", arr[idx]);
		else
			printf("%d\n", arr[idx]);
	}

	free(arr); free(dup);
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    

	int n, d, *arr = NULL;

	scanf("%d %d", &n, &d);

	if(d <= 0 || n < 0)
	{
		printf("Number of elements should be at least 1 and rotation constant cannot be negative.\n");
		exit(1);
	}

	arr = (int *) calloc(n, sizeof(int));

	int idx = 0;
	for( ; idx < n; idx++)
	{
		scanf("%d", &arr[idx]);
	}

	leftRotate(arr, n, d);

	return 0;
}