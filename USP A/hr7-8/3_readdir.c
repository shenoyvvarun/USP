#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main()
{
	char name[20];
	DIR *pdir;
	struct dirent *pentry;
	printf("enter the name : ");
	scanf("%s", name);
	if((pdir = opendir(name)) == 0)
	{
		perror("opendir"); exit(1);
	}
	while(pentry = readdir(pdir))
	{
		printf("%ld %s\n", pentry->d_ino, pentry->d_name);
	}
	if(closedir(pdir) < 0)
	{
		perror("closedir"); exit(2);
	}
	return 0;
}
