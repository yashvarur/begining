#include "header.h"       

/* function to copy a single bit from one number to another number */

void bit_cp(int s, int d, int src, int dest ) 
{
        src  = src & ( 1 << s );
        src  = src >> s;
        dest = dest & ( ~( 1 << d ) );
        dest = dest | ( src << d );
        printf("result of bit copying\n");
        binary(dest);

}                                                                                                          
