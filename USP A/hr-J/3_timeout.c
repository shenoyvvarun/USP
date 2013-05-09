#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>


int main()
{
	struct timeval t = {2, 500000 } ;
	printf("sleeping\n");	
	if(select(1024, (fd_set*)0, (fd_set*)0, (fd_set*)0, &t ) == -1)
	{
		perror("select"); exit(1);
	}
	printf("woke up\n");
}
