#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int fd = open("file",O_RDWR);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
	if(lseek(fd,0,SEEK_END)<0)
	{
		perror("lseek a");
		exit(2);
	}
	char *ch = (char *)malloc(sizeof(char));
	while(lseek(fd,-2,SEEK_CUR) != -1)
	{
		if(read(fd,ch ,1)<0)
		{
			perror("read");
			exit(4);
		}
		printf("%c",*ch);		
	}
}
