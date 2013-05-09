// create a file
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
	int i;
	int sq;
	fd = open("myfile.dat", O_WRONLY);
	if(fd < 0)
	{
		perror("open: ");
		exit(1);
	}
	printf("fd %d\n", fd);
	for(i = 1; i <= n; ++i)
	{
		sq = i * i;
		if(write(fd, &sq, sizeof(int)) != sizeof(int))
			perror("write : "), exit(1);
	}
	close(fd);
	return 0;
}


