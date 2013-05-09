// read a file
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
	int n = 20;
	int sq;
	int size;
	fd = open("myfile.dat", O_RDONLY);
	if(fd < 0)
	{
		perror("open: ");
		exit(1);
	}
	printf("fd %d\n", fd);
	while( (size = read(fd, &sq, sizeof(int))) > 0)
	{
		printf("square : %d\n", sq);
	}
	close(fd);
	return 0;
}


