#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun
{
	int val;
};

int main()
{
	char ch;
	int pid;
	int id1;
	int id2;
	union semun u;
	struct sembuf p = { 0, -1, SEM_UNDO };
	struct sembuf v = { 0, +1, SEM_UNDO };

	id1 = semget(0x3333, 1, IPC_CREAT | 0666);
	if(id1 < 0)
	{
		perror("semget"); exit(51);
	}

	id2 = semget(0x4444, 1, IPC_CREAT | 0666);
	if(id2 < 0)
	{
		perror("semget"); exit(52);
	}
	u.val = 1;
	if(semctl(id1, 0, SETVAL, u) < 0)
	{
		perror("semctl"); exit(53);
	}
	u.val = 0;
	if(semctl(id2, 0, SETVAL, u) < 0)
	{
		perror("semctl"); exit(54);
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
			if(semop(id1, &p, 1) == -1)
			{
				perror("semop");exit(55);
			}
			putchar(ch);
			fflush(stdout);
			putchar(ch);
			fflush(stdout);
			if(semop(id2, &v, 1) == -1)
			{
				perror("semop");exit(56);
			}
		}
	}
	else
	{
		for(ch = 'a'; ch <= 'z'; ++ch)
		{
			sleep(rand() % 2);
			if(semop(id2, &p, 1) == -1)
			{
				perror("semop");exit(57);
			}
			putchar(ch);
			fflush(stdout);
			putchar(ch);
			fflush(stdout);
			if(semop(id1, &v, 1) == -1)
			{
				perror("semop");exit(58);
			}
		}
	}
	
}
