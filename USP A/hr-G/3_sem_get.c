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
	int i;
	int val;
	id = semget(KEY, 3, IPC_CREAT | 0666);
	if(id == -1)
	{
		perror("semget"); exit(1);
	}
	for(i = 0; i < 3; ++i)
	{
		
		if((val = semctl(id, i, GETVAL, 0)) < 0)
		{
			perror("semctl ipcstat"); exit(2);
		}
		printf("sem %d : %d\n", i, val);
	} 
}
