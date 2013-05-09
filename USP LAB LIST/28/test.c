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
	if(pause()<0)
	{
		perror("pause");
	}
}
