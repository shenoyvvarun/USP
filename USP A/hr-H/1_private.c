#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
	

int main()
{
	int id;
	if((id = msgget(IPC_PRIVATE, IPC_CREAT | 0666)) == -1)
	{
		perror("msgget"); exit(1);		
	}
	printf("key : %d id : %d\n",
		IPC_PRIVATE, id);
}
