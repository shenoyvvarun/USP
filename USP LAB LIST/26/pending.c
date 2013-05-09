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
	sleep(11);
	if(sigpending(&block))
	{
		perror("sigpending");
		exit(2);
	}
	if(sigismember(&block,SIGINT)) printf("\n SIGINT PENDING\n");
	if(sigismember(&block,SIGQUIT)) printf("\n SIGQUIT PENDING\n");
	if(sigprocmask(SIG_SETMASK,&old,(sigset_t *)0))
	{
		perror("sigprocmask");
		exit(1);
	}
	sleep(12);
}
