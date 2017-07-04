#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// N, Q <= 1000
// Length of string less than 21 characters. 

int main(int argc, char *argv[]) 
{
	FILE *fptr, *fOutput = fopen("./myoutput.txt", "w");
 	if(argc < 2)
	{
		printf("[Usage] out filename.\n");
		exit(1);
	}
	
	fptr = fopen(argv[1], "r");
	
	if(fptr == NULL || fOutput == NULL)
	{
		printf("File open error.\n");
		exit(1);
	}

	int N = 0, Q = 0;

	fscanf(fptr, "%d", &N);

	char *str[N], *pc, buffer[21] = {0};
	int idx = 0;
	for(; idx < N; idx++)
	{
		fscanf(fptr, "%s", buffer);
		pc = calloc(1, sizeof(strlen(buffer+1)));
		strncpy(pc, buffer, strlen(buffer));

		str[idx] = pc;
		memset(buffer, 0, sizeof(buffer));
	}

	fscanf(fptr, "%d", &Q);
	int occurrences[Q];
	memset(occurrences, 0, sizeof(occurrences));

	for(idx = 0; idx < Q; idx++)
	{
		fscanf(fptr, "%s", buffer);

		int temp_idx = 0;
		for(; temp_idx < N; temp_idx++)
		{
			if(!strcmp(buffer, str[temp_idx])) 
			{
				++occurrences[idx];
			}
		}
		fprintf(fOutput, "%d\n", occurrences[idx]);
		memset(buffer, 0, sizeof(buffer));
	}

	fclose(fOutput); fclose(fptr);

	return 0;
}
