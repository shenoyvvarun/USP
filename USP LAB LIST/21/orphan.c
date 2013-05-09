#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
int main()
{
	int pid = fork();
	if(pid<0)
	{
		perror("fork");
		exit(1);
	}
	if(pid)
	{
		sleep(4);
	}
	else
	{
		if(kill(getppid(),SIGKILL)<0)
		{
			perror("kill");
			exit(2);
		}
		sleep(111);
	}
}
