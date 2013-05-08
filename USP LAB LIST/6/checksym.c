#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[])
{
	struct stat s;
	if(argc<2)
	{
		printf("Not enough arguements\n");
		exit(1);
	}
	if(lstat(argv[1],&s)<0)
	{
		perror("lstat");	
		exit(2);
	}
	if(S_ISLNK(s.st_mode))
	{
		printf("Its a symbolic link");
	}
	else
	{	
		printf("Its not a symbolic link");
	}
	printf("\n");
	return 0; // I will be killed for not doing this in other programs
}
