#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handler(int a)
{
	//do nothing
}

int main()
{
	int pid;
	if(signal(SIGUSR1,handler)<0)
	{
		perror("signal");
		exit(2);
	}
	pid = fork();
	if(pid<0)
	{
		perror("fork");
		exit(1);
	}
	if(pid)
	{
		sleep(1);
		setenv("a","varun",1);
		kill(pid,SIGUSR1);
	}
	else
	{
		pause();
		printf("The environment variable in the child %s",getenv("a"));
	}

}
