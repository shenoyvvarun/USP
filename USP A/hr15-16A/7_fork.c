#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
// try
#if 0
	fork();
	fork();
	printf("ondu\n");
#endif
#if 0
	fork() && fork();
	printf("eradu\n");
#endif
	fd = open("...", O_RDONLY);
	fork();
	read(fd, &ch, 1);
	// which char ?

}
