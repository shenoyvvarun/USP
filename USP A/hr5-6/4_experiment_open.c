// experiment open
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
	int fd;
	int fd1;
	int sq;
	int sq1;
	// no error checking!	
	fd = open("myfile.dat", O_RDONLY);
	printf("fd %d\n", fd);
	fd1 = open("myfile.dat", O_RDONLY);
	printf("fd %d\n", fd1);
	read(fd, &sq, sizeof(int));
	close(fd);
	read(fd1, &sq1, sizeof(int));
	printf("%d %d\n", sq, sq1);
	close(fd1);
	
	
#if 0
	while( (size = read(fd, &sq, sizeof(int))) > 0)
	{
		printf("square : %d\n", sq);
	}
#endif
	return 0;
}


