#include <stdio.h>
#include <stdlib.h>
// getenv setenv
int main()
{
	char *s;
	s = getenv("c");
	printf("%s\n", s);
	setenv("c", "ccccccc", 1);
	s = getenv("c");
	printf("%s\n", s);
	return 0;
}
