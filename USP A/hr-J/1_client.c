#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
	int cd;
	struct sockaddr_in c; 
	int cl;
	int n;
	int sqn;
	cd = socket(AF_INET, SOCK_DGRAM, 0);
	if(cd == -1)
	{
		perror("socket"); exit(1);
	}
//	printf("cd : %d\n", cd);
	c.sin_family = AF_INET;
	c.sin_port = htons(3456);
	c.sin_addr.s_addr = htonl(INADDR_ANY);
	
	cl =  sizeof(c);
	srand(getpid());
	n = rand() % 100;
	printf("sending %d\n", n);
	if(sendto(cd, (void*)&n, sizeof(n), 0,
			(struct sockaddr*)&c, cl ) < 0)
	{
		perror("send"); exit(3);
	}
	if(recvfrom(cd, (void*)&sqn, sizeof(int), 0,
		(struct sockaddr*)0, 0) < 0)
	{
		perror("recv"); exit(4);
	}
	printf("square of %d is %d\n", n, sqn);
}
