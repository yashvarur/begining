#include"header.h"
void deque()
{
	int item;
	if(q.front == -1)
		printf("queue underflow\n");
	else if(q.front > q.rear)
		printf("queue underflow\n"); 
	else {
		item = q.a[q.front++];
		printf("item removed is = %d\n",item);
	}
}
