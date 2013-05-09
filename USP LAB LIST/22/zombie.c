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
		sleep(100);
	}
	else
	{
		exit(0);
	}
}
