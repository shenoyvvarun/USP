#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// exec:
//	replaces the text segment and data segment
//		of the execing process

int main()
{
	printf("before\n");
	if(execl("/bin/ls", "ls", "-l", "-i", (void*)0 ) < 0)
	{
		perror("exec"); exit(1);
	}
	// never executed
	printf("after\n");
	return 0;
}
