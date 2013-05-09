#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main()
{
	sigset_t block;
	sigemptyset(&block);
	sigaddset(&block,SIGINT);
	if(sigprocmask(SIG_BLOCK,&block,(sigset_t *)0)<0)
	{
		perror("sigprocmask");
		exit(2);
	}
	int pid = fork();
	if(pid<0)
	{
		perror("fork");	exit(1);
	}
	if(pid)
	{
		sleep(1);
		if(kill(pid,SIGINT)<0)
		{
			perror("kill"); exit(3);
		}
	}
	else
	{
		pause(); // If the process still remains => was blocked
	}
}
