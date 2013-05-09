#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	int pid1;
	int pid2;
	int fd[2];
	if(pipe(fd) < 0)
	{
		perror("pipe"); exit(1);
	}
	pid1 = fork();
	if(pid1 < 0) 
	{
		perror("fork"); exit(1);
	}
	else if(pid1) // parent
	{
		pid2 = fork();
		if(pid2 < 0) 
		{
			perror("fork"); exit(1);
		}
		else if(pid2) // parent
		{
			close(fd[0]); close(fd[1]);
			wait((int*)0); wait((int*)0);
			
		}
		else // second child
		{
			close(0); dup(fd[0]);
			close(fd[0]); close(fd[1]);
			execl("/usr/bin/wc", "wc", "-l", (void*)0);
		}
	}
	else // first child
	{
		close(1); dup(fd[1]);
		close(fd[1]); close(fd[0]);
		execl("/bin/ls", "ls", (void*)0);
	}
}
