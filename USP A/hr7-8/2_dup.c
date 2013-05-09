#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd1;
	int fd2;
	char name1[10];
	char name2[10];
	fd1 = open("names.txt", O_RDONLY);
	if(fd1 < 0)
	{
		perror("open"); exit(1);
	}
	// gives another file descriptor for the same file
	//	refer to the same entry in the global file table
	// is the smallest number available
	fd2 = dup(fd1);
	if(fd2 < 0)
	{
		perror("dup"); exit(1);
	}
	printf("fd1 : %d fd2 : %d\n", fd1, fd2);
	read(fd1, name1, 4);
	name1[4] = '\0';
	printf("%s\n", name1);
	read(fd2, name2, 4);
	name2[4] = '\0';
	printf("%s\n", name2);
	if(close(fd1) < 0)
	{
		perror("close"); exit(2);
	}
	if(close(fd2) < 0)
	{
		perror("close"); exit(2);
	}
	return 0;
}
