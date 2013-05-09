#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	umask(0);
	int fd = open("var.dat",O_CREAT|O_WRONLY,0666);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
	if(close(1)<0)
	{
		perror("close");
		exit(2);
	}
	if(dup(fd)<0)
	{
		perror("dup");
		exit(3);
	}
	if(close(fd)<0)
	{
		perror("close");
		exit(4);
	}
	char s[100];
	gets(s);
	puts(s);
}
