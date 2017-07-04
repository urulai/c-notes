#include <stdio.h>

int main(void)
{
	FILE *f = fopen("./myoutput.txt", "r");
	int N;
	
	while(1)
	{
		if(feof(f))
		{
			printf("\nHit EOF\nExit program\n");
			break;
		}
	
		fscanf(f, "%d", &N);
		printf("%d ", N);
	}
	return 0;
}
