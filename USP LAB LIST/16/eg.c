#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf buf;
void root(int a)
{
	if(a<0)
	{
		longjmp(buf,3);
	}
	printf("The root of the number approximately is %d\n",a/2);
}
void bar(int a)
{
	root(a);
}
void foo( int a)
{
	if(setjmp(buf)==0)
	{
		bar(a);
	}
	else
	{
		printf("There was an error computing your result\n");
	}
}

int main(int argc, char * argv[])
{
	foo(argv[1][0] - '0');
	return 0;
}
