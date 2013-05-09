#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct msg
{
	long t; // type
	int m;
};
typedef struct msg msg_t;
#define KEY 0x1234
int main()
{
	int id;
	msg_t mymsg;
	long type;
	if( (id = msgget(KEY, IPC_CREAT | 0666)) < 0)
	{
		perror("msgget"); exit(1);
	}
	printf("enter the message type : ");
	scanf("%ld", &type);
	if(msgrcv(id, &mymsg, sizeof(mymsg) - sizeof(long), type, 0) < 0)
	{
		perror("msgrcv"); exit(2);
	}
	printf("message recd : %d\n", mymsg.m);
	return 0;
}


