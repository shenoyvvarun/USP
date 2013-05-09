// __ctl to remove the underlying data structure
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

#define KEY 0x1234

int main()
{
	int id;
	if((id = msgget(ftok("/home/kumar/A/hr-C/", 'a'), IPC_CREAT | 0666)) == -1)
	{
		perror("msgget"); exit(1);
	}

	if(msgctl(id, IPC_RMID, (struct msqid_ds*)0) < 0)
	{
		perror("msgctl"); exit(2);
	}
	
}
