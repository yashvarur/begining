#include"header.h"
int prime(int num ,int i)
{
       
       // if((num == 0) || (num == 1))
         //       return 0;
        if(num == 2)
                return 2;
        if((num % i) == 0)
		return 0;
	if(i==num/2)
		return num;
	return prime(num,++i);
}

