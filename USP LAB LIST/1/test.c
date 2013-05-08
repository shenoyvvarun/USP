#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	umask(0);
	int fd = open("var.dat",O_CREAT|O_WRONLY,0600);
	char s[10];
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
	scanf("%s",s);
	if(write(fd,s,strlen(s))<0)
	{
		perror("write");
		exit(2);
	}
	printf("\nThe Program finished execution\n");
	close(fd);
}

/**
*1) The program was run without the set user bit set
*2) This program has to be placed into tmp folder
*3) Now when someone tries to execute it the open will fail : permission denied
*4) When the set user bit is set, when the program is executed the executer gets the privilages of the owner.
*/
