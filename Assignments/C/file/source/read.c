#include "header.h"
int int_read()
{
        int valid = 0, out_range = 0;  /* valid to check validity of num 
					out_range to check range of a num */
 
        int f = 0;			/* f is to check sign appearance*/
        long long int temp = 0;		/* to store converted num*/
        char *stream = NULL, *copy = NULL;			/* to store string frm stdin*/
	
        do {
//                __fpurge( stdin );		//clear buffer

		if ( NULL == ( stream = ( char * ) malloc( sizeof(char) * 64 ) ) ) { 
			perror ("malloc failed for stream\n");
			exit (1);
		}
	
		copy = stream;			//for freeying
                fgets( stream, 16, stdin );	//read string frm stdin
                * ( stream + strlen( stream ) -1 ) = '\0'; //replace \n by \o

		 //check for space tab and new line and skip
               
		 while((*(stream) == ' ') || *(stream) == '\n' || *(stream) == '\t') 
                        stream++;

                if( *stream == '-' )	//if sign set f and move next
                {
                        f = 1;
                        stream++;
                }else if(*stream == '+')
                        stream++;

                while ( (*stream) >= '0' && (*stream) <= '9') {  /*check only for string 0-9 */


                        temp = temp * 10 + ( *( stream) - '0' );/* convert string to int */
                        stream++;

                        if(temp< INT_MIN || temp>INT_MAX)//check range
                        {
                                printf("out of range\n");
                                valid=0;
                                out_range=1;
                                break;
                        }
                        valid=1;
                }

                if(!out_range)	//if within range 
                {	/*after dig may be space or tab */
                        while(*(stream)== ' ' || (*stream)=='\t' || (*stream)=='\n')
                                stream++;

                        if((*stream)!='\0')	//after space there should not be anything*/
                                valid=0;

                        if(f)		//convert +ves to -ves
                                temp = 0 - temp;

                       // if( valid==1 )
                         //       return((int)temp);

                }
                if(valid==0)		//ask for re enter
                {

                        printf("please enter valid integer\n");
                        //for(i=0;i<l;i++)	//reset stream,temp,f
                          //      stream--;
                        f=0;
                     
                        temp=0;
                }
	free(copy);
	copy = NULL;
        } while(!valid);  //do until digit is valid
	return temp;	//return valid digit
}
