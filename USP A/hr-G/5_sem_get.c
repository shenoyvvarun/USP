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
	int id;
	unsigned short int val[3];
	union semun u;
	int i;
	id = semget(KEY, 3, IPC_CREAT | 0666);
	if(id == -1)
	{
		perror("semget"); exit(1);
	}
	u.array = val;
	if(semctl(id, 0, GETALL, u) < 0)
	{
			perror("semctl ipcstat"); exit(2);
	}
	for(i = 0; i < 3; ++i)
	{
		printf("sem %d : %d\n", i, val[i]);
	}
}

