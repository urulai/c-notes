#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	FILE *fInput = fopen("./input.txt", "r"), \
	*fOutput = fopen("./output.txt", "w");
	
	if(fInput == NULL || fOutput == NULL)  
	{	
		printf("File open error\n");
		exit(1);
	}

	int N, Q, lastAnswer = 0;

	fscanf(fInput, "%d %d", &N, &Q);

	typedef struct sequenceList
	{
		int *arr;
		int cur_idx;
	} seqList;

	// Making use of variable length arrays.
	seqList dyn_arr[N];
	
	int index =  0;
	
	// Initialize the pointers and cur_idx.
	for(;index < N; index++)
	{
		dyn_arr[index].cur_idx = 0;
		dyn_arr[index].arr = NULL;
	}
	
	index = 0;
	for(; index < Q; index++)
	{
		int temp_1, temp_2, temp_3;
		fscanf(fInput, "%d %d %d", &temp_1, &temp_2, &temp_3);

		// Query 1 : 1 x y
		// 1. Find the sequence, seq, at index ((X XOR lastAnswer) % N) in seqList
		// 2. Append integer y to sequence seq.


		// Query 2 : 2 x y
		// 1. Find the sequence, seq, at index  ((X XOR lastAnswer) %N) in seqlist
		// 2. Find the value of element y % size in seq ( where size is the size of seq ) and assign it to lastAnswer.
		// 3. Print the new value of lastAnswer on a new line.

		if(temp_1 == 1)
		{
			// Appending mode to the array.
			int seq = (temp_2 ^ lastAnswer) % N;

			// Found seq, append temp_3 to the list.
			// dyn_arr[seq].arr[dyn_arr[seq].cur_idx++] = temp_3;
			
			if(dyn_arr[seq].cur_idx == 0)
			{
				dyn_arr[seq].arr = (int *) malloc(sizeof(int));		
			}
			else
			{
				dyn_arr[seq].arr = realloc(dyn_arr[seq].arr, (dyn_arr[seq].cur_idx+1) *sizeof(int));
			}

			dyn_arr[seq].arr[dyn_arr[seq].cur_idx++] = temp_3;
		}
		else if(temp_1 == 2)
		{
			// Retrieval mode of lastAnswer and print it.

			int seq = (temp_2 ^ lastAnswer) % N;
			int idx = temp_3 % dyn_arr[seq].cur_idx;    // modulo by seq's size.
			lastAnswer = dyn_arr[seq].arr[idx];
			fprintf(fOutput, "%d\n", lastAnswer);
		}
	}

	index = 0;
	for(; index < N; index++)
	{	
		if(dyn_arr[index].arr != NULL)
			free(dyn_arr[index].arr);
	}

	return 0;

}