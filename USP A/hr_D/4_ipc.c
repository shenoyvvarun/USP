// __ctl to modify the underlying data structure
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
	struct msqid_ds m;
	int id;
	if((id = msgget(ftok("/home/kumar/A/hr-C/", 'a'), IPC_CREAT | 0666)) == -1)
	{
		perror("msgget"); exit(1);
	}

	if(msgctl(id, IPC_STAT, &m) < 0)
	{
		perror("msgctl"); exit(2);
	}
	m.msg_perm.mode = 0600;
	if(msgctl(id, IPC_SET, &m) < 0)
	{
		perror("msgctl"); exit(3);
	}





	
}
