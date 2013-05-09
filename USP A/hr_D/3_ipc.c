// __ctl to access the underlying data structure
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>
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
	printf("uid : %d gid : %d mode : %o\n",
		m.msg_perm.uid, m.msg_perm.gid, m.msg_perm.mode);
	printf("send time : %s\n", ctime(&m.msg_stime));
	printf("recv time : %s\n", ctime(&m.msg_rtime));
	printf("change time : %s\n", ctime(&m.msg_ctime));
	printf("# of msg : %d\n", m.msg_qnum);
	printf("qsize : %d\n", m.msg_qbytes);




	
}
