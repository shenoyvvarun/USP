#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int fd[2];
	int pid;
	if(pipe(fd) < 0)
	{
		perror("pipe"); exit(1);
	}
	pid = fork();
	if(pid < 0)
	{
		perror("fork"); exit(2);
	}
	else if(pid) // parent
	{
		// let parent be the writer
		close(fd[0]);
		sleep(5);
		if(write(fd[1], "we love unix", 13) < 0)
		{
			perror("write"); exit(3);
		}
	}
	else // child
	{
		char msg[20];
		// let child be the reader
		close(fd[1]);
		if(read(fd[0], msg, 20)  < 0)
		{
			perror("read"); exit(4);
		}
		printf("msg : %s\n", msg);
	}
}



