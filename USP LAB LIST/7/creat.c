#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int getProperPermission(char * s)
{
	if(strlen(s)<3)
	{
		printf("Specify proper perm"); exit(3);
	}
	int usr = s[0] - '0';
	int grp = s[1] - '0';
	int oth = s[2] - '0';
	int ret =0;
	if(usr%2 ==1)
	{
		ret = ret|S_IXUSR;
		
	}
	usr = usr>>1;
	if(usr%2 ==1)
	{
		ret = ret|S_IWUSR;
	}
	usr = usr>>1;
	if(usr%2 ==1)
	{
		ret = ret|S_IRUSR;
	}

	if(grp%2 ==1)
	{
		ret = ret|S_IXGRP;
	}
	grp = grp>>1;
	if(grp%2 ==1)
	{
		ret = ret|S_IWGRP;
	}
	grp = grp>>1;
	if(grp%2 ==1)
	{
		ret = ret|S_IRGRP;
	}

	if(oth%2 ==1)
	{
		ret = ret|S_IXOTH;
	}
	oth = oth>>1;
	if(oth%2 ==1)
	{
		ret = ret|S_IWOTH;
	}
	oth = oth>>1;
	if(oth%2 ==1)
	{
		ret = ret|S_IROTH;
	}
	return ret;
}
int main (int argc, char * argv[])
{
	umask(0);
	if(argc<3)
	{
		printf("\nUsage: permission filename");
		exit(1);
	}
	int perm = getProperPermission(argv[1]);
	int fd = creat(argv[2],perm);
	if(fd<0)
	{
		perror("creat");
		exit(1);
	}
	return 0;
}
