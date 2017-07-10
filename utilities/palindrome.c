#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char buffer[1024] = {0};
	if(argc < 2)
		strcpy(buffer, "");  //Empty string.
	else
		strcpy(buffer, argv[1]);
	
	char user[2];

	do 
	{
		unsigned int N = strlen(buffer);
		int i = 0, l = N-1;

		while((i < N/2) && buffer[i++] == buffer[l--])
			;

		if(i != 0 && i == N/2) // added i! = 0 condition for empty string
			printf("'%s' is palindrome\n", buffer);
		else
			printf("'%s' is not a palindrome. Try again.\n", buffer);

		sleep(1);
		
		printf("Do you want to continue? (y/n) => ");
		scanf("%s", user);
		
		if(user[0]!= 'y')
			break;
		else
		{
			memset(buffer, 0, sizeof buffer);
			printf("Enter some string for checking: ");

			scanf("%s", buffer);
		}
	} while(user[0] == 'y' || user[0] == 'Y');

	return 0;
}
