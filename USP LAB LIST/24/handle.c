#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handle(int a)
{
	printf("Handled SIGINT\n\n");
}
int main()
{
	
	if(signal(SIGINT,handle)<0)
	{
		perror("signal");
		exit(2);
	}
	if(signal(SIGQUIT,SIG_IGN)<0)
	{
		perror("signal");
		exit(3);
	}
	printf("C'mon give me a signal\n");
	pause();	
}
