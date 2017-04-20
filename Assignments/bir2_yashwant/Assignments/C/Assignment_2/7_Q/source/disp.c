#include"header.h"
void binary(int num) /* display in binary format */
{
        int i;
        for(i = 31 ; i >= 0 ;i--)
        {
                printf("%d",( num & ( 1 << i ) ? 1 : 0) );
        }
}

