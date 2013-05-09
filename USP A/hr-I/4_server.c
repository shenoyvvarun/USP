#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

int main()
{
	int sd;
	struct sockaddr_un s; 
	int sl;

	int cd; // client socket on the server side
	struct sockaddr_un c;
	int cl;
	int m;
	int sqm;

	sd = socket(AF_UNIX, SOCK_STREAM, 0);
	if(sd == -1)
	{
		perror("socket"); exit(1);
	}
//	printf("sd : %d\n", sd);
	s.sun_family = AF_UNIX;
	strcpy(s.sun_path, "socketfile");
	sl = sizeof(s);
	if( unlink("socketfile") == -1)
	{
		perror("unlink"); exit(11);
	}
	if(bind(sd, (struct sockaddr*)&s, sl) == -1)
	{
		perror("bind"); exit(2);
	}
	printf("socket bound\n");
	if(listen(sd, 5) == -1)
	{
		perror("listen"); exit(3);
	}
	srand(getpid());
	while(1)
	{
		if((cd = accept(sd, (struct sockaddr*)&c, &cl)) == -1)
		{
			perror("accept"); exit(4);
		}
		if(recv(cd, (void *)&m, sizeof(int), 0) < 0)
		{
			perror("recv"); exit(5);
		}
		printf("recd : %d\n", m);
		sleep(rand() % 5);
		sqm = m * m;
		if(send(cd, (void *)&sqm, sizeof(int), 0) < 0)
		{
			perror("send"); exit(6);
		}
	}

}
