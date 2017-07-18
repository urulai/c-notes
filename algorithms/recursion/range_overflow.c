#include <stdio.h>
#include <limits.h>

#define MAX(a,b) ((a > b)?a:b)
int main(int argc, char *argv[])
{
	short number1=SHRT_MAX;
	unsigned short number2=USHRT_MAX;

	printf("%hu %hu\n", number1, number2);

	printf("%hu %hu\n", (number1+1), (number2+1));
		
	printf("Max: %hu\n", MAX((number1+1), (number2+1)));
	return 0;
}
