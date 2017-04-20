# include "header.h"
int prime_check(int num,int i)   /*recurssion function to find fibonacci number*/ 
{

	if( num == 0 )
                return 0;
        else if( num == 1 )
                return 0;
	else if( num == 2 ) 
		return 1;
        else {
                if( num % i == 0 ) 
                        return 0;
                else{
                        if( i < num/2 )
                        {
                                i++;
                        return prime_check(num,i);
                        }
                        else
                                return 1;
                    }
             }
}
