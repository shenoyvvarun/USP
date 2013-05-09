#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
// send a signal to the child
int main()
{
	int pid;
	if((pid = fork()) < 0)
	{
		perror("fork"); exit(1);
	}
	else if(pid)
	{
		sleep(5);
		printf("send a singal to the child\n");
		if(kill(pid, SIGINT) < 0)
		{
			perror("kill"); exit(2);
		}
	}
	else
	{
		while(1)
		{
			printf("I do not want to die\n");
		}
	}
}
