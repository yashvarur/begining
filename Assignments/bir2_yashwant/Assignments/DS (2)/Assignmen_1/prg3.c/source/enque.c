#include"header.h"
void enque()
{
	int ele;
	if(cq.front == (cq.rear + 1) % MAX)
		printf("queue overflow\n");
	else {
		printf("enter the element to insert\n");
		scanf("%d",&ele);
		cq.rear = ( cq.rear + 1 ) % MAX;
		cq.s[cq.rear] = ele;
		if(cq.front == -1)
			cq.front = 0;
	}
}
