
#ifndef header 
#define header 1
#define SIZE 500
#include<stdio_ext.h>
#include<limits.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//#include<malloc.h>
#define LEN 500
#define FREE(s) free(s);\
		s = NULL;
int int_read();
void binary(int n);
void bit_cp(int s,int d,int src,int dest);

#endif
