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
	int id; // sem
	union semun u;
	struct sembuf p = {0, -1, SEM_UNDO };
	struct sembuf v = {0, +1, SEM_UNDO };
	if((id = semget(KEY, 1, IPC_CREAT | 0666)) < 0)
	{
		perror("semget"); exit(2);
	}
	u.val = 1;
	if(semctl(id, 0, SETVAL, u) < 0)
	{
		perror("semctl"); exit(3);
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
			if(semop(id, &p, 1) < 0)
			{
				perror("semop"); exit(11);
			}
			putchar(ch);
			fflush(stdout);
			putchar(ch);
			fflush(stdout);
			if(semop(id, &v, 1) < 0)
			{
				perror("semop"); exit(12);
			}
			sleep(rand() % 2);
		}
	}
	else
	{
		for(ch = 'a'; ch <= 'z'; ++ch)
		{
			sleep(rand() % 2);
			if(semop(id, &p, 1) < 0)
			{
				perror("semop"); exit(13);
			}
			putchar(ch);
			fflush(stdout);
			putchar(ch);
			fflush(stdout);
			if(semop(id, &v, 1) < 0)
			{
				perror("semop"); exit(12);
			}
		}
	}
	
}
