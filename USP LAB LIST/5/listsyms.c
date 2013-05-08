/* ./a followed by the directory
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <assert.h>


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
	assert(dir>0);
	char buf[256]; // max file name 
	char actualFileName[256];
	int len = strlen(argv[1]),j,i;
	strncpy(buf,argv[1],len);
	int k;
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
		if(S_ISLNK(s.st_mode))
		{
			//Now its a symbolic link
			if((k=readlink(buf,actualFileName,256))<0)
			{
				perror("readlink");
				exit(1);
			}
			actualFileName[k] = '\0';
			printf("\n%s is linked to the name %s\n ",buf,actualFileName );
			printf("\n");
		}
		
	}
	
}
