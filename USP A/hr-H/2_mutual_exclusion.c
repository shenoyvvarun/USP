#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

// named semaphore

int main()
{
	char ch;
	int pid;
	sem_t *p;
	p = sem_open("/my_sem1", O_CREAT, 0666, 1);

	if(p == SEM_FAILED)
	{
		perror("sem_open"); exit(20);
	}
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
			if(sem_wait(p) < 0)
			{
				perror("semwait"); exit(22);
			}
			putchar(ch);
			fflush(stdout);
			putchar(ch);
			fflush(stdout);
			if(sem_post(p) < 0)
			{
				perror("sempost"); exit(22);
			}
		}
	}
	else
	{
		for(ch = 'a'; ch <= 'z'; ++ch)
		{
			sleep(rand() % 2);
			if(sem_wait(p) < 0)
			{
				perror("semwait"); exit(22);
			}
			putchar(ch);
			fflush(stdout);
			putchar(ch);
			fflush(stdout);
			if(sem_post(p) < 0)
			{
				perror("sempost"); exit(22);
			}
		}
	}
	if(sem_destroy(p) < 0)
	{
		perror("sem destroy"); exit(21);
	}
	
}
