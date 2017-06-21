#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

#define BUFFSIZE 1024

int main(void)
{

	pid_t pid;

	if((pid = fork()) < 0)
	{
		printf("*** ERROR: forking child process failed\n");
		exit(1);
	}
	else if(pid == 0)
	{

		printf("Child process %d.\n", getpid());
		char **chptr; 
		chptr = malloc(sizeof(char *));

		char strlet[BUFFSIZE] = {0};

		printf("%% ");
		fgets(strlet, BUFFSIZE, stdin);

		// remove new-line character at the end.
		if(strlet[strlen(strlet) - 1] == '\n')
			strlet[strlen(strlet) - 1] = '\0';

		char *catch;
		catch = strtok(strlet, " ");

		int index = 0;
		if(catch != NULL)
		{
			do 
			{
				if(index != 0)
					chptr = realloc(chptr, (index+1) * sizeof(char *));	

				chptr[index++] = catch;

			} while ((catch = strtok(NULL, " ")) != NULL);

			// Add a NULL pointer at the end since execvp requires the array of
			// pointers to be terminated by a NULL pointer.
			chptr = realloc(chptr, (index+1) * sizeof(char *));	
			chptr[index++] = (char *)NULL;	
		}

		int status = execvp(chptr[0], chptr);
		if(status != 0)
			printf("ERROR *** Child process - execvp, %s (%d).\n", strerror(errno), errno);

		free(chptr);
	}
	else if(pid > 0)
	{
		int status = 0;
		printf("Parent process %d.\n", getpid());

		if((pid = wait(&status)) < 0)
			printf("Wait error: %d.\n", errno);

		if(status != 0)
			printf("ERROR *** Child process exit status: %d.\n", status);

	}

	return 0;
}