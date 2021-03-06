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
		if(pause()<0)
		{
			perror("pause");
		}
		printf("The environment variable in the parent %s\n",getenv("a"));
	}
	else
	{
		sleep(1);
		setenv("a","varun",1);
		if(kill(pid,SIGUSR1)<0)
		{
			perror("setenv");
			exit(2);
		}
		printf("The environment variable was set in the child");
	}

}
