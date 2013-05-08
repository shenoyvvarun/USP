#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int itoa(int a, char *s)
{
	int j,i =0;
	if(a==0){s[i++] ='0';}
	while(a!=0)
	{
		s[i++] = a%10 +'0';
		a = a/10;
	}
	char ch;
	for(j=0;j<i/2;j++)
	{
		ch = s[j];
		s[j] = s[i-j-1];
		s[i-j-1] = ch;
	}
	s[i] = '\0';
	return i;
}

int main()
{
	int n,i,fd,pt;
	printf("\nEnter the value of n ");
	scanf("%d",&n);
	umask(0);
	char s[256];
	for(i=0;i<n;++i)
	{
		pt =itoa(i,s);
		mkdir(s,0777);
		s[pt++] = '/';
		s[pt++] ='f';
		s[pt] ='\0';
		umask(0);
		fd = creat(s,0666);
		if(fd<0)
		{
			perror("creat");
			printf("%s",s);
			exit(2);
		}
		if(close(fd)<0)
		{
			perror("close");
			exit(3);
		}
	}
}
