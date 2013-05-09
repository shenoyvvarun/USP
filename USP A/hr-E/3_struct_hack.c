#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct What
{
	int n;
	char s[1];
};
typedef struct What what_t;
int main()
{
	what_t *p;
	char str[] = "testing struct hack";
	p = (what_t*)malloc(sizeof(what_t) + strlen(str) + 1 - 1);
	p->n = 111;
	strcpy(p->s, str);
	printf("%d %s\n", p->n, p->s);
	free(p);
	return 0;
}

