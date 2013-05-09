#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handler_INT(int signo)
{
	printf("sigint received\n");
}

void handler_QUIT(int signo)
{
	printf("sigquit received\n");
}

int main()
{
	sigset_t block;
	sigset_t old;
	sigset_t pend;
	sigemptyset(&block);
	sigaddset(&block, SIGINT);
	sigaddset(&block, SIGQUIT);
	signal(SIGINT, handler_INT);
	signal(SIGQUIT, handler_QUIT);
	printf("starts\n");
	sleep(10);
	if(sigprocmask(SIG_BLOCK, &block, &old) < 0)
	{
		perror("sigprocmask"); exit(1);
	} 
	printf("enter critical section\n");
	raise(SIGINT);
	raise(SIGQUIT);
	sleep(10);
	// check for pending signals
	if(sigpending(&pend) < 0)
	{
		perror("pending"); exit(3);
	}
	printf("pend : sIGINT : %d\n", sigismember(&pend, SIGINT));
	printf("pend : sIGquit: %d\n", sigismember(&pend, SIGQUIT));
	sleep(10);
	printf("exit critical section\n");
	if(sigprocmask(SIG_SETMASK, &old, (sigset_t*)0) < 0)
	{
		perror("sigprocmask"); exit(2);
	} 
	
	sleep(10);
	printf("ends\n");
}
