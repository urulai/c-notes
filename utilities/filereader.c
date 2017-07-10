#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("Usage: out [filename] [lines].\nProgram supports only one file for opening.\n");
		exit(1);
	}
	
	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		printf("File open: error.\n");
		exit(1);
	}

	char buffer[BUFSIZ], ch;
	int lines = 0, user_config_lines = 60;
	if(argv[2])
	{
		user_config_lines = atoi(argv[2]);
	}

	while(fgets(buffer, BUFSIZ, fp) != NULL)
	{
		if(++lines < user_config_lines)
		{
			// Dump content to standard output.
			fputs(buffer, stdout);
		}
		else 
		{
			buffer[strlen(buffer) - 1] = '\0';
			fputs(buffer, stdout);
			fflush(stdout);

			ch = getchar();
			if(ch == 'q' || ch == 'Q')
			{
				printf("user chose to quit.\n");
				fclose(fp);
				exit(0);
			}
			lines = 0;
		}
	}
	printf("\n");
	fclose(fp);

	return 0;
}
