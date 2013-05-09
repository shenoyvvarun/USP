#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int sd;
	struct sockaddr_in s; 
	int sl;

	int cd; // client socket on the server side
	struct sockaddr_in c;
	int cl;
	int m;
	int sqm;

	sd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sd == -1)
	{
		perror("socket"); exit(1);
	}
//	printf("sd : %d\n", sd);
	s.sin_family = AF_INET;
	s.sin_port = htons(3456);
	s.sin_addr.s_addr = htonl(INADDR_ANY);
	sl = sizeof(s);
	if(bind(sd, (struct sockaddr*)&s, sl) == -1)
	{
		perror("bind"); exit(2);
	}
	printf("socket bound\n");
	srand(getpid());
	while(1)
	{
		if(recvfrom(sd, (void *)&m, sizeof(int), 0,
			(struct sockaddr*)&s, &sl) < 0)
		{
			perror("recv"); exit(5);
		}
		printf("recd : %d\n", m);
		sleep(rand() % 5);
		sqm = m * m;
		if(sendto(sd, (void *)&sqm, sizeof(int), 0,
			(struct sockaddr*)&s, sl) < 0)
		{
			perror("send"); exit(6);
		}
	}

}
