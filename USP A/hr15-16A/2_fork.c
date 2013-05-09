// create a new process
//	fork
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("hattu\n");
	fork();
	printf("savira\n");
	return 0;
}
