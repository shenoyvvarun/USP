#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[])
{
	DIR *dir;
	struct dirent *dp;
	struct stat s;
	if(argc<2)
	{
		perror("not enough arguements");
		exit(1);
	}
	dir = opendir(argv[1]);
	char buf[200];
	int len = strlen(argv[1]),j,i;
	strncpy(buf,argv[1],len);
	while((dp = readdir(dir))!= NULL)
	{
		i= len;
		buf[i++] = '/';
		for(j =0;dp->d_name[j]!='\0';++j)
		{
			buf[i++] = dp->d_name[j];
		}
		buf[i] = '\0';
		if(lstat(buf,&s)<0)
		{
			perror("stat");
			printf("%s  %s\n",dp->d_name,buf );
		}
		else
		{
			if(S_ISDIR(s.st_mode)){ printf("%s is directory",dp->d_name);}
			else
			if(S_ISREG(s.st_mode)){ printf("%s is regular file",dp->d_name);}
			else
			if(S_ISCHR(s.st_mode)){ printf("%s is character device",dp->d_name);}
			else
			if(S_ISBLK(s.st_mode)){ printf("%s is block device",dp->d_name);}
			else
			if(S_ISFIFO(s.st_mode)){ printf("%s is fifo",dp->d_name);}
			else
			if(S_ISLNK(s.st_mode)){ printf("%s is symbolink link",dp->d_name);}
			else
			if(S_ISSOCK(s.st_mode)){ printf("%s is socket file",dp->d_name);}
			else {printf("Unkown device");}
		}
		printf("\n");
	}
	
}
