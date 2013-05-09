#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <time.h>

union semun 
{
    int val;
    struct semid_ds *buf;
    unsigned short  *array;
};


#define KEY 0x1234
int main()
{
	char ch;
	int pid;
	srand(getpid());
	if((pid = fork()) < 0)
	{
		perror("fork"); exit(1);
	}
	else if(pid) // parent
	{
		for(ch = 'A'; ch <= 'Z'; ++ch)
		{
			sleep(rand() % 3);
			putchar(ch);
			fflush(stdout);
			sleep(rand() % 3);
			putchar(ch);
			fflush(stdout);
			sleep(rand() % 3);
		}
	}
	else
	{
		for(ch = 'a'; ch <= 'z'; ++ch)
		{
			sleep(rand() % 3);
			putchar(ch);
			fflush(stdout);
			sleep(rand() % 3);
			putchar(ch);
			fflush(stdout);
			sleep(rand() % 3);
		}
	}
	
}
