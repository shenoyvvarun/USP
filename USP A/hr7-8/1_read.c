#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;
	char name[10];
	fd = open("names.txt", O_RDONLY);
	if(fd < 0)
	{
		perror("open"); exit(1);
	}
	read(fd, name, 4);
	name[4] = '\0';
	printf("%s\n", name);
	sleep(100);
	read(fd, name, 4);
	name[4] = '\0';
	printf("%s\n", name);
	if(close(fd) < 0)
	{
		perror("close"); exit(2);
	}
	return 0;
}
