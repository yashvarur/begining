#include"header.h"	
void fun(int a)
{
	if(a==65 || a==69 || a==73 || a==79 || a==85 || a==97 || a==101 || a==105 || a==111 || a==117)//ASCII value comparison
        printf("given character is vowel \n");
        else
        printf("given character is consonant\n");
}
