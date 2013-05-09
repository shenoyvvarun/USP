#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
// how to share files?
//	- share the name
//	- share the underlying data structure (using fork)
// how to share an IPC mechanism?
//	a) share the id
//	b) share the key
//	c) share a mechanism to make a key
//		ftok(path, char)

#define KEY 0x1234

int main()
{
	if(msgget(ftok("/home/kumar/A/hr-C/", 'a'), IPC_CREAT | IPC_EXCL | 0666) == -1)
	{
		perror("msgget"); exit(1);
	}
}
