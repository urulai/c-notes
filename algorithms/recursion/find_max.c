#include <stdio.h>
#include <stdlib.h>

// Uses integers as datatype, so larger numbers above 2^32-1
int max(int a, int b)
{
	return a > b? a : b;
}

int find_max(int *arr, int N)
{
	if(N <= 0)
		return arr[N];

	return max(find_max(arr, N-1), arr[N-1]);
}

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("Usage: ./out 'N numbers separated by space'.\n");
		return 0;
	}
	
	int i = 0, arr[argc-1];
	for(i = 0; i < argc-1; i++) 
	{
		arr[i] = atoi(argv[i+1]);
		printf("%d\n", arr[i]); 
	}

	int maximum = find_max(arr, argc - 1);
	printf("max : %d\n", maximum);
	
	return 0;
}
