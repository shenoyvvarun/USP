// signal
//	SIGALRM : make a timer

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
typedef void (*sighandler_t)(int);

// signal : system call to establish the handler
void my_handler(int signo)
{
	printf("time out\n");
	exit(1);
}
int main()
{
	if( signal(SIGALRM, my_handler)  == (sighandler_t)-1)
	{
		perror("signal"); exit(1);
	}
	if(alarm(10) < 0)
	{
		perror("alarm"); exit(2);
	}
	while(1)
	{
		printf("waiting ... \n");
	}
}

