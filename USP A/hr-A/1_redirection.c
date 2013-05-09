#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
void copy();
int main()
{
#if 0
	copy();
#endif
#if 0
	int fd = open("t.txt", O_RDONLY); // check for errors always
	close(0);
	dup(fd);
	close(fd);
	copy();
#endif
	int fd = open("t.txt", O_RDONLY); // check for errors always
	int fd1 = creat("q.txt", 0644);
	close(0);
	dup(fd);
	close(fd);

	close(1);
	dup(fd1);
	close(fd1);
	copy();
}
void copy()
{
	char ch;
	while((ch = getchar()) != EOF)
	{
		putchar(ch);
	}
}

