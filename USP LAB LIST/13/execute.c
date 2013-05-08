#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	if(argc<2)
	{
		printf("too few args");
	}
	if(execvp(argv[1],argv+1)<0)
	{
		perror("excec");
		exit(1);
	}
}
