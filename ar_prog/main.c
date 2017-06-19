#include "greeting.h"

int main(void)
{
	const char *str = "Subramanian"	;

	printf("Login to system.\n");
	hello(str);

	printf("Initiate logout.\n");
	bubye(str);

	return 0;
}