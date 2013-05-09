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
	union semun u;
	int val[] = {4, 5, 6};
	int i;
	id = semget(KEY, 3, IPC_CREAT | 0666);
	if(id == -1)
	{
		perror("semget"); exit(1);
	}
	for(i = 0; i < 3; ++i)
	{
		u.val = val[i];
		if(semctl(id, i, SETVAL, u) < 0)
		{
			perror("semctl ipcstat"); exit(2);
		}
	} 
}
