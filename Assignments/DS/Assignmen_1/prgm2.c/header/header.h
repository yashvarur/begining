#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct queue
{
	int front;
	int rear;
	int a[MAX];
}q;
void enque();
void deque();
void display();

