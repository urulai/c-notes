#include <stdio.h>
#include <stdlib.h>

// The program fails for larger numbers.
// Stack overflow happens.

int mul(int x, int y)
{
	if(x == 0 || y == 0)
		return 0;

	return x + mul(x, y-1);
}

int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		printf("Usage: ./out '2 integers separated by space'.\n");
		return 0;
	}
	
	int x = atoi(argv[1]), y = atoi(argv[2]);

	int result = mul(x,y);
	printf("res : %d\n", result);
	return 0;
}
