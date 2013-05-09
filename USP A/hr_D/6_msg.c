#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


#define KEY 0x1234

int main()
{
	if(msgget(KEY, IPC_CREAT | 0666 ) == -1)
	{
		perror("msgget"); exit(1);
	}
	

}
