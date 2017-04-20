#ifndef header 
#define header 1

#include<limits.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//#include<malloc.h>
#define LEN 64
#define FREE(s) free(s);\
		s = NULL;
int int_read();
unsigned int rotate_bit(unsigned int num,int bit,int d);
#endif
