#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
// msg should have a type field of type long
// should be the first field
struct msg
{
	long type;
	int n;
};
typedef struct msg msg_t;
#define KEY 0x1234
int main()
{
	int id;
	msg_t mymsg;
	if( (id = msgget(KEY, IPC_CREAT | 0666)) < 0)
	{
		perror("msgget"); exit(1);
	}
	printf("enter type and a number to square : ");
	scanf("%ld %d", &mymsg.type, &mymsg.n);
	if(msgsnd(id, &mymsg, sizeof(mymsg) - sizeof(long), 0) < 0)
	{
		perror("msgsnd"); exit(2);
	}
	printf("msg sent\n");
	return 0;
}

// user gives a request for a msg of a particular type
// if there is a msg of that type, it is delivered
// if there are more than one msg of that type, the first msg based on time
//	stamp is delivered
// if there is no such msg and IPC_NOWAIT is not specified, the call blocks 
//	until a msg of that kind is delivered

// if type is specified as 0, the call returns the first msg
// 
// experiment:
//	client server model with two msg queues
//			    with single msg queue
//			    with two different languages
//			
