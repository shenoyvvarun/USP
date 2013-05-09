#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void handle(int a)
{
	printf("Alarm recieved by %d\n",getpid());
}
int main()
{
	if(signal(SIGALRM,handle)<0)
	{
		perror("signal");
		exit(2);
	}
	if(alarm(2))
	{
		perror("alarm");
		exit(3);
	}
	int pid = fork();
	if(pid<0)
	{
		perror("fork");
		exit(4);
	}
	pause();
}
