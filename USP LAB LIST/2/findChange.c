#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc,char *argv[])
{
	struct stat s;
	time_t t;
	if(time(&t)<0)
	{
		perror("time");
		exit(2);
	}
	if(stat(argv[1],&s)<0)
	{
		perror("stat");
		exit(1);
	}
	printf("The file has not been changed since %ld seconds",(t - s.st_mtime));
}
