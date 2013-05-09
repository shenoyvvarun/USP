#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>



int main()
{
	char ch;
	int pid;
	sem_t s;
	if(sem_init(&s, 0, 1) < 0)
	{
		perror("sem_init"); exit(20);
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
			// p op
			if(sem_wait(&s) < 0)
			{
				perror("semwait"); exit(22);
			}
			sleep(rand() % 2);
			putchar(ch);
			fflush(stdout);
			putchar(ch);
			fflush(stdout);
			if(sem_post(&s) < 0)
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
			if(sem_wait(&s) < 0)
			{
				perror("semwait"); exit(22);
			}
			putchar(ch);
			fflush(stdout);
			putchar(ch);
			fflush(stdout);
			if(sem_post(&s) < 0)
			{
				perror("sempost"); exit(22);
			}
		}
	}
	if(sem_destroy(&s) < 0)
	{
		perror("sem destroy"); exit(21);
	}
	
}
