#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int pid;
	int status;
	pid = fork();
	if(pid < 0)
	{
		perror("fork");exit(1); 
	}
	else if(pid)
	{
		printf("parent starts\n");
		//wait((int*)0);
		wait(&status);
		printf("status : %x\n", status);
		if(WIFEXITED(status))
			printf("status : %d\n",
				WEXITSTATUS(status));
		if(WIFSIGNALED(status))
			printf("signal : %d\n",
				WTERMSIG(status));

		printf("parent completes\n");
		return 0;
	}
	else
	{
		printf("child enters\n");
		sleep(5);
		printf("child exits\n");
		return 10;
	}
}
// what happens if the child thro?
// what happens if the parent has # of children?
// 
// wait system call:
//		most significant byte :  exit value
//		least significant byte : exit status
//			0 on normal termination of the child
//			signal number if signaled to die

