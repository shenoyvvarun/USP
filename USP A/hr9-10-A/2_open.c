#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;
        int size;
	fd = open("a.txt", O_WRONLY | 
O_CREAT, S_IRUSR | S_IWUSR | 
		S_IWGRP | S_IRGRP | S_IROTH);
	if(fd < 0)
	{
		perror("creat");
		exit(1);
	}
	if((size = write(fd, "shocked", 7)) != 7)
		{
			perror("write");
			exit(3);

		}  
	if(close(fd) < 0)
	{
		perror("close");
		exit(2);
	}
	return 0; 
}


