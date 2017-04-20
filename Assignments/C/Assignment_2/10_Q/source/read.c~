#include"header.h"
int int_read()
{
	char *str = NULL;
	int i = 0, f = 0,c=1;
	long long int num;
	if ( NULL == (str = ( char* )malloc( sizeof( char ) ) ) ) {
		perror ("malloc failed for str\n");
		exit (1);
	}
	
	while (c) {
		fgets(str, LEN, stdin);
		fflush(stdout);
		*( str + ( strlen ( str ) ) - 1 ) = '\0';

		num=0,f=0,i=0;
		while( ( * ( str + i ) == ' ' ) || ( * ( str + i) == '\t' ) )  {   
			i++;				/*count the spaces  & tab */
		}
		if( ( * ( str + i ) == '+' ) )     /* check for only one + operator immidiatly fallowed number */
			i++;

		if(*(str+i)=='-')	{         /* check for only one - operator immidiatly fallowed number */
			f=1;
			i++;
		}

		while( (* ( str + i )>='0') && (*(str+i)<='9' )) {	/*converting the character to integer */ 

			num = num * 10 + ( * ( str + i ) -'0' );
			i++;
			c=0;
		} 
		if(num>INT_MAX || num<INT_MIN) {			/* checking for integer overflow */
			printf("buffer over flow out of range\n");
			exit(0);
		}
		while( ( * ( str + i ) == ' ' ) || ( * ( str + i) == '\n' ) || ( * ( str + i) == '\t' ) )  
			i++;				/* checking for spaces and tab after the number */

		if(*(str+i)!='\0')		/* if any invalid character other than NULL repeate the loop */
			c=1;

		if(f==1)
			num = 0 - num;			/* 2's compliment for -ve number */
		if(c==1) {
			printf("invalid character enter again\n");

		}

	}
	FREE(str);
	

	return num;
}
