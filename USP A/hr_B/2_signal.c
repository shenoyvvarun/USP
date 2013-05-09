// signal
//	low level commn mechanism
//	a process sends a number to another
//	like an interrupt
//	generate a signal
//	a) thro the keyboard : SIGINT SIGQUIT
//	b) hardware generated : division by zero
//		SIGFPE
//	c) send a signal using system call kill
//	d) send a signal thro cmd kill
//	e) software generated
//		SIGSEGV

//	process can react in 3 ways
//	a) default action
//	b) ingore 
//	c) call to the signal handler
//	SIGKILL and SIGSTOP cannot be handled or ingored


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
typedef void (*sighandler_t)(int);

// signal : system call to establish the handler
void my_handler(int signo)
{
	printf("recd the signal : %d\n", signo);
	getchar();
	// want to ignore : SIG_IGN
	// reset to the default
	if( signal(SIGINT, SIG_DFL)  == (sighandler_t)-1)
	{
		perror("signal"); exit(1);
	}
	
}
int main()
{
	if( signal(SIGINT, my_handler)  == (sighandler_t)-1)
	{
		perror("signal"); exit(1);
	}
	
	while(1)
	{
		printf("waiting ... \n");
	}
}

