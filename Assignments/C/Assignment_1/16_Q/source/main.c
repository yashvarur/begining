// program to find length of string
#include"header.h"
int main()
{
	 char str[100];
	 char *p;
	 printf("enter the string\n");
         scanf("%s",str);
         p=&str[0];	/*pointer points to starring address of string */
	fun(p);
return 0;
}
	

