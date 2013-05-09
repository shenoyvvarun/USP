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

  fd_set input_set;
  fd_set test_set;

  int i;
  int res_len;

  FD_ZERO(&input_set);
  
  sd = socket(AF_INET, SOCK_STREAM, 0);
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
  if(listen(sd, 5) == -1)
  {
     perror("listen"); exit(3);
  }
  srand(getpid());
  
  FD_SET(sd, &input_set);
  while(1)
  {
     test_set = input_set;
     if(select(1024, &test_set, (fd_set*)0,(fd_set*)0, 
		(struct timeval*)0) == -1)
     {
	perror("select"); exit(11);
     }
     for(i = 0; i < 1024; ++i)
     {
	if(FD_ISSET(i, &test_set))
	{
	    if(i == sd) // new client
	    {
                if((cd = accept(sd, (struct sockaddr*)&c, &cl)) == -1)
                {
                    perror("accept"); exit(4);
                }
		FD_SET(cd, &input_set);
	    }
	    else
	    {
                if((res_len = recv(i, (void *)&m, sizeof(int), 0)) < 0)
                {
                    perror("recv"); exit(5);
                }
		if(res_len == 0)
	        {
			close(i);
			FD_CLR(i, &input_set);
                }
                else
                {
     			printf("recd : %d\n", m);
     			sleep(rand() % 5);
     			sqm = m * m;
     			if(send(i, (void *)&sqm, sizeof(int), 0) < 0)
     			{
        			perror("send"); exit(6);
     			}
                }
            }
	} // end of if of fd_isset
     } // end of for
  }
}

