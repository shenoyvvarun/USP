// create a file
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

// does umask affect the file creation?
// can we change umask with in a pgm in 'c'? any system call?
// can we create an existing file?
// in that case, what permissions come into effect?
// how big is the file descriptor array?
int main()
{
	int fd;
	// fd = creat("myfile.dat", S_IRUSR | S_IWUSR | S_IRGRP);
	fd = creat(".", S_IRUSR | S_IWUSR | S_IRGRP);
	if(fd < 0)
	{
	// how big can the number be?
	// how do we get this value in the environment?
		perror("create : ");
		printf("errno : %d\n", errno);
		if(errno == EISDIR)
		{
			printf("dir cannot be opened using create\n");
		}
		exit(1);
	}
	printf("fd %d\n", fd);
	close(fd);
	return 0;
}
