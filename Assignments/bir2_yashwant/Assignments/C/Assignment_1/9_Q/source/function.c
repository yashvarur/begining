#include"header.h"
void fun()		/* function to print the prime number between 1 to 100 */ 
{
	int num,i,c;
 for(num=2;num<100;num++) {
                c=0;
          for(i=2;i<=num/2;i++) {
                if(num%i==0) {		
                        c=1;
                        break;
                }
           }
         if(c==0)
        printf("%d\t\t",num);
        }
}

