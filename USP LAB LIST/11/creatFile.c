#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int n;
	printf("Enter the size in bytes\n");
	scanf("%d",&n);
	int fd = open("file",O_CREAT|O_WRONLY,0644);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
	if(lseek(fd,n-1,SEEK_END) == -1)
	{
		perror("lseek");
		exit(2);
	}
	if(write(fd," ",1) == -1)
	{
		perror("write");
		exit(2);
	}
	
	if(close(fd)<0)
	{
		perror("close");
		exit(3);
	}
}
