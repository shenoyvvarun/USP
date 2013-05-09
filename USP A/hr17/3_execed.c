#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	printf("execed: pid %d ppid %d\n",
		getpid(), getppid());
	return 0;
}
