// shared memory
//	access from another process
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
	int n = 5;
	int pointer;
	int i;
	printf("enter pointer : ");
	scanf("%x", &pointer);
	if( (id =  shmget(KEY, 1000, IPC_CREAT | 0666)) < 0)
	{
		perror("shmget"); exit(1);
	}
	p = (node_t*)shmat(id, (void*)pointer, 0);
	if(p == (void*)-1)
	{
		perror("shmat"); exit(2);
	}
	printf("p : %p\n", p);
	// populate the list
	disp(p);
	if(shmdt(p) < 0)
	{
		perror("shmdt"); exit(3);
	}
}

