#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	char ch;
	if(read(3, &ch, 1) < 0)
	{
		perror("read"); exit(1);
	}
	printf("read : %c\n", ch);
		
	return 0;
}
