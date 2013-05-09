// shared memory
//	read from shared memory
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
	int n = 5;
	int i;
	if( (id =  shmget(KEY, 1000, IPC_CREAT | 0666)) < 0)
	{
		perror("shmget"); exit(1);
	}
	p = (int*)shmat(id, 0, 0);
	if(p == (void*)-1)
	{
		perror("shmat"); exit(2);
	}
	printf("p : %p\n", p);
	for(i = 0; i < n; ++i)
	{
		printf("%d\t", p[i]);
	}
	printf("\n");
	if(shmdt(p) == -1)
	{
		perror("shmdt"); exit(3);
	}
}

