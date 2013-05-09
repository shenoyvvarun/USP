#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// interprocess commn
//	files
//	pipes
//	named pipe
//	pipe open
//	signals

// sys V IPC 
//	message queue
//	shared memory
//	semaphore

// create an ipc structure
// 	___get()
// what finename is for file open,
//	key is for ___get

// no unget
//	cannot close an IPC
// has no name (compared to files)
// persistence:
//	until a reboot
// IPC may be removed when still in use

// no hierarchy


// commands:
//	ipcs : icp status
//	ipcrm : remove ipc

#define KEY 0x1234

int main()
{
	if(msgget(KEY, IPC_CREAT | IPC_EXCL | 0666) == -1)
	{
		perror("msgget"); exit(1);
	}
}
