#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void leftRotate(int *arr, int n, int d)
{
	int idx = 0;
	int *dup = (int *) calloc(n ,sizeof(int));
	int *swapPtr = NULL;

	int offset = n - d;

	if(offset) 
	{
		for(idx = 0; idx < n; idx++)
		{
			if((idx + offset) < n)
			{
				dup[idx+offset] = arr[idx];
			}
			else 
			{
				dup[(idx+offset)-n] = arr[idx];
			}
		}
		swapPtr = arr;
		arr = dup;
		dup = swapPtr;
	}

	for(idx = 0; idx < n; idx++)
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

	arr = (int *) calloc(n, sizeof(int));

	int idx = 0;
	for( ; idx < n; idx++)
	{
		scanf("%d", &arr[idx]);
	}

	leftRotate(arr, n, d);

	return 0;
}