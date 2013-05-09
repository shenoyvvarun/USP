// shared memory
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
	struct shmid_ds m;
	if( (id =  shmget(KEY, 1000, IPC_CREAT | 0666)) < 0)
	{
		perror("shmget"); exit(1);
	}
	if(shmctl(id, IPC_STAT, &m) < 0)
	{
		perror("shmctl"); exit(2);
	}
	printf("size : %d\n", m.shm_segsz);
	printf("attach time : %s\n",
				ctime(&m.shm_atime));
	printf("detach time : %s\n",
				ctime(&m.shm_dtime));
	printf("change time : %s\n",
				ctime(&m.shm_ctime));
	printf("# of attach: %d\n",
				m.shm_nattch);
}

