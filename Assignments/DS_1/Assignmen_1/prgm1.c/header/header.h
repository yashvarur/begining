#include<stdio.h>
#include<stdlib.h>
#define MAX 6
struct stack
{
	int top;
	int s[MAX];
}st;
void push(int ele);
void pop();
void display();
void pushn(int pos,int ele);
void popn(int po);
