#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <pthread.h>


int main()
{
	char ch;
	int pid;
	pthread_mutex_t m;
	pthread_mutex_init(&m, 0);

	srand(getpid());
	if((pid = fork()) < 0)
	{
		perror("fork"); exit(1);
	}
	else if(pid) // parent
	{
		for(ch = 'A'; ch <= 'Z'; ++ch)
		{
			sleep(rand() % 2);
			// p op
			pthread_mutex_lock(&m);
			putchar(ch);
			fflush(stdout);
			putchar(ch);
			fflush(stdout);
			pthread_mutex_unlock(&m);
		}
	}
	else
	{
		for(ch = 'a'; ch <= 'z'; ++ch)
		{
			sleep(rand() % 2);
			pthread_mutex_lock(&m);
			putchar(ch);
			fflush(stdout);
			putchar(ch);
			fflush(stdout);
			pthread_mutex_unlock(&m);
		}
	}
	
}
