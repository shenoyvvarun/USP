#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int pid = fork();
	if(pid<0)
	{
		perror("fork");
		exit(1);
	}
	if(pid)
	{	int status;
		wait(&status);
		if(WIFEXITED(status))
			printf("status : %d\n",
				WEXITSTATUS(status));
		if(WIFSIGNALED(status))
			printf("signal : %d\n",
				WTERMSIG(status));
		printf("Exit Status %d\n",(status<<24)>>24);
		printf("Exit value %d\n",status>>8);

	}
	else
	{
		sleep(2);
		exit(251);
	}
	
}
