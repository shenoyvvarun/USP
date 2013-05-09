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
	if(alarm(2))
	{
		perror("alarm");
		exit(3);
	}
	if(execl("./b","b",(char*)0)<0)
	{
		perror("exec");
		exit(4);
	}
}
