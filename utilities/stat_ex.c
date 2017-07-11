#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>

#define REG_FILE "REGULAR_FILE"
#define DIR_TYPE "DIRECTORY"
#define LINK_TYPE "SYMBOLIC_LINK"
#define CHAR_TYPE "CHARACTER DEVICE"
#define FIFO_TYPE "FIFO (Named Pipe)?"
#define BLK_TYPE "BLOCK DEVICE"
#define SOCK_TYPE "SOCKET"
#define UNKNOWN_TYPE "Unknown file type"

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("Usage: ./out 'file or directory name'\n");
		exit(0);
	}
	
	do
	{
		--argc;
		++argv;
	
		//int fd = open(argv[0], O_RDONLY);
		//if(fd == -1)
		//{
		//	printf("%s: %s\n", argv[0], strerror(errno));
		//	exit(1);
		//}

		struct stat stat_var;
		int status = lstat(argv[0], &stat_var);
		if(status == -1)
		{
			printf("%s: %s\n", argv[0], strerror(errno));
			continue;
		}
		
		char str[32] = {0};

		if(S_ISREG(stat_var.st_mode))
			strncpy(str, REG_FILE, strlen(REG_FILE));
		else if(S_ISDIR(stat_var.st_mode))
			strncpy(str, DIR_TYPE, strlen(DIR_TYPE));
		else if(S_ISLNK(stat_var.st_mode))
			strncpy(str, LINK_TYPE, strlen(LINK_TYPE));
		else if(S_ISCHR(stat_var.st_mode))
			strncpy(str, CHAR_TYPE, strlen(CHAR_TYPE));
		else if(S_ISBLK(stat_var.st_mode))
			strncpy(str, BLK_TYPE, strlen(BLK_TYPE));
		else if(S_ISSOCK(stat_var.st_mode))
			strncpy(str, SOCK_TYPE, strlen(SOCK_TYPE));
		else if(S_ISFIFO(stat_var.st_mode))
			strncpy(str, FIFO_TYPE, strlen(FIFO_TYPE));
		else
			strncpy(str, UNKNOWN_TYPE, strlen(UNKNOWN_TYPE));

		printf("%s => type: %s, size: %zu\n", argv[0], str, stat_var.st_size); 
		
	} while(argc != 1);
	return 0;
}
