#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main()
{
	sigset_t block;
	sigemptyset(&block);
	sigaddset(&block,SIGINT);
	if(sigprocmask(SIG_BLOCK,&block,(sigset_t *)0)<0)
	{
		perror("sigprocmask");
		exit(2);
	}
	if(execl("./b","b",(char*)0)<0)
	{
		perror("execl"); exit(4);
	}
}
