#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// pid and ppid will not change on exec

int main()
{
	printf("execing : pid %d ppid %d\n",
		getpid(), getppid());
	if(execl("./3_execed", "3_execed", (void*)0 ) < 0)
	{
		perror("exec"); exit(1);
	}
	return 0;
}
