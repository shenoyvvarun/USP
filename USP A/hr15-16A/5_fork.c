// create a new process
//	fork
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// fork:
//	returns pid of the child in parent
//		0 in the child
// 	global variable will have the same virtual addr in both the
//		parent and the child
//	will normally share the same physical location
//		until one of the processes changes the variable
//	at the point, a new physical location is created
//		calld copy-on-write

int g = 10;
int main()
{
	int l = 20;
	printf("addr of l : %p\n", &l);
#if 0
	int pid;
	pid = fork();
	if(pid < 0)
	{
		perror("fork"); exit(1);
	}
	else if(pid) // parent
	{
		printf("parent: pointer to g : %p\n", &g);
		g = 20;
	}
	else // child
	{
		printf("child: pointer to g : %p\n", &g);
		g = 30;
	}
	printf("end: pointer to g : %p\n", &g);
	printf("end: val : %d\n", g);

#endif
	return 0;
}




