#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;
	fd = creat("a.txt", S_IRUSR | S_IWUSR | 
		S_IWGRP | S_IRGRP | S_IROTH);
	if(fd < 0)
	{
		perror("creat");
		exit(1);
	}
	if(close(fd) < 0)
	{
		perror("close");
		exit(2);
	}
	return 0; 
}


