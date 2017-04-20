#include"header.h"	/*function to find length of string*/
void fun(char *p)
{	
	int l=0; 
	 while(*p++!='\0')
        {
         l++;
        }
         printf("length of string=%d\n",l);
}
