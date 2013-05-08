#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char * argv[])
{
	if(argc<2)
	{
		printf("No files to delete");
		exit(1);
	}
	struct stat s;
	if(stat(argv[1],&s)<0)
	{
		perror("stat");
		exit(2);
	}
	if(s.st_uid == getuid())
	{
		if(unlink(argv[1])<0)
		{
			perror("unlink");
			exit(3);
		}
	}
	else
	{
		printf("Cannot delete");
	}
	return 0;
}
