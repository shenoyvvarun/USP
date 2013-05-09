// shared memory
//	create and test attach
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define KEY 0x1234
int main()
{
	int id;
	int *p;
	struct shmid_ds m;
	if( (id =  shmget(KEY, 1000, IPC_CREAT | 0666)) < 0)
	{
		perror("shmget"); exit(1);
	}
	p = (int*)shmat(id, 0, 0);
	if(p == (void*)-1)
	{
		perror("shmat"); exit(2);
	}

//	sleep(1000);
	if(shmdt(p) == -1)
	{
		perror("shmdt"); exit(3);
	}
}

