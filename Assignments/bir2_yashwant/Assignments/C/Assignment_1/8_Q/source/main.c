// program to reverse a given number
#include"header.h"
int main()
{

        int a=0,rev,n;
        printf("enter the number you want to reverse\n");
        scanf("%d",&a);
        n=a;
        rev=fun(n);//function call
        printf("origional number =%d\n",a);
        printf("reverse number =%d\n",rev);
return 0;
}
