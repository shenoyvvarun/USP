#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
// file descriptor flag:
//	close on exec
//		not set by default
//	opened files remain open after execing
// assign: how to set close-on-exec flag

int main()
{
	int fd;
	fd = open("x.dat", O_RDONLY);
	if(fd < 0)
	{
		perror("open"); exit(2);
	}
	printf("fd : %d\n", fd);
	if(execl("./5_execed", "5_execed", (void*)0 ) < 0)
	{
		perror("exec"); exit(1);
	}
	if(close(fd) < 0)
	{
		perror("close"); exit(3);
	}
	return 0;
}
