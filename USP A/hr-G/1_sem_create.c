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
	struct semid_ds x;
	union semun u;
	id = semget(KEY, 3, IPC_CREAT | 0666);
	if(id == -1)
	{
		perror("semget"); exit(1);
	}
	// semnum : index of array of counting sem
	//          not interested in a particular
	//		semaphore here - use 0
	u.buf = &x;
	if(semctl(id, 0, IPC_STAT, u) < 0)
	{
		perror("semctl ipcstat"); exit(2);
	} 
	printf("operation time : %s\n",
		ctime(&x.sem_otime));
	printf("change time : %s\n",
		ctime(&x.sem_ctime));
	printf("# of sem : %ld\n",
		x.sem_nsems);

	
	
	
}
