#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handle(int a)
{
	printf("Where is the snooze for this alarm??\n\n");
}
int main()
{
	
	if(signal(SIGALRM,handle)<0)
	{
		perror("alarm");
		exit(2);
	}
	if(alarm(1)<0)
	{
		perror("alarm");
		exit(2);
	}
	pause();	
}
