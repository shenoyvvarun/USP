// shared memory
//	create a linked list
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define KEY 0x1234

struct node
{
	int key;
	struct node *link;
};
typedef struct node node_t;

void disp(node_t *temp)
{
	while(temp)
	{
		printf("%d ", temp->key);
		temp =  temp->link;
	}
	printf("\n");
}
int main()
{
	int id;
	node_t *p; // head for the list
	node_t *q;
	int n = 5;
	int i;
	if( (id =  shmget(KEY, 1000, IPC_CREAT | 0666)) < 0)
	{
		perror("shmget"); exit(1);
	}
	p = (node_t*)shmat(id, 0, 0);
	if(p == (void*)-1)
	{
		perror("shmat"); exit(2);
	}
	printf("p : %p\n", p);
	// populate the list
	p->key = 111;
	p->link = p + 1;
	p->link->key = 222;
	p->link->link = 0;
	disp(p);
	q = (node_t*)shmat(id, 0, 0);
	if(q == (void*)-1)
	{
		perror("shmat"); exit(2);
	}
	printf("q : %p\n", q);
	// populate the list
	disp(q);
	if(shmdt(p) < 0)
	{
		perror("shmdt"); exit(3);
	}
	if(shmdt(q) < 0)
	{
		perror("shmdt"); exit(3);
	}
}

