#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


int main()
{
	sigset_t block,old;
	sigemptyset(&block);
	sigaddset(&block,SIGINT);
	sigaddset(&block,SIGQUIT);
	if(sigprocmask(SIG_BLOCK,&block,&old))
	{
		perror("sigprocmask");
		exit(1);
	}
	printf("\nENTER CRITICAL SECTION\n");
	printf("\nDOING SOME EXECUTION\n");
	sleep(11);
	printf("leaving critical section\n");
	if(sigprocmask(SIG_SETMASK,&old,(sigset_t *)0))
	{
		perror("sigprocmask");
		exit(1);
	}
	sleep(12);
}
