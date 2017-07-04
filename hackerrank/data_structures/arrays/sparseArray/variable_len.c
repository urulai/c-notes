#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


// N, Q <= 1000
// Length of string less than 21 characters. 

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int N = 0, Q = 0;
	
	scanf("%d", &N);
	
	char str[N][20];
	int idx= 0;

	memset(str, 0, N*20);
	for(; idx < N; idx++)
	{
		scanf("%s", str[idx]);
	}

	// for(idx = 0; idx < N; idx++)
	// {
	// 	printf("%s\n", str[idx]);
	// }


	scanf("%d", &Q);
	int occurrences[Q];
	char query[Q][20];
	memset(occurrences, 0, sizeof(occurrences));
	memset(query, 0, Q*20);

	for(idx = 0; idx < Q; idx++)
	{
		scanf("%s", query[idx]);
	}
	
	// for(idx = 0; idx < Q; idx++)
	// {
	// 	printf("%s\n", query[idx]);
	// }


	for(idx = 0; idx < Q; idx++)
	{
		int temp_idx = 0;
		for(; temp_idx < N; temp_idx++)
		{
			if(!strcmp(query[idx], str[temp_idx])) 
			{
				++occurrences[idx];
			}
		}
	}

	for(idx = 0; idx < Q; idx++)
		printf("%d\n", occurrences[idx]);

	return 0;
}
