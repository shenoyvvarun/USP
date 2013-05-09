// create a new process
//	fork
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// fork:
//	returns pid of the child in parent
//		0 in the child
int main()
{
	int pid;
	pid = fork();
	if(pid < 0)
	{
		perror("fork"); exit(1);
	}
	else if(pid) // parent
	{
		sleep(2);
		printf("parent pid %d ppid %d\n",
			getpid(), getppid());
	}
	else // child
	{
		printf("child pid %d ppid %d\n",
			getpid(), getppid());
	}
	return 0;
}




