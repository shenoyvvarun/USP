#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main()
{
	sigset_t temp;
	sigemptyset(&temp);
//	sigaddset(&temp, SIGINT);
	sigaddset(&temp, SIGQUIT);
	printf("sigint : %d\n", sigismember(&temp, SIGINT));
	printf("sigquit : %d\n", sigismember(&temp, SIGQUIT));
}
