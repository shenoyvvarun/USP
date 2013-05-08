#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
	if (argc <3)
	{
		perror("Not enough arguments");
		exit(1);
	}
	if(symlink(argv[1],argv[2])<0)
	{
		perror("symlink");
		exit(1);
	}
}
