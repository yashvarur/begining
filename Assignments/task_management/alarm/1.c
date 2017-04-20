# include <error.h>
# include <sys/syscall.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
int main()
{
	int sec;
	int status;
	int pid;
	char line[128];
	char msg[64];
	while(1) {
	  printf("Alarm> ");
	  if(fgets(line,sizeof(line),stdin) == NULL)
		exit(0);
	  if(strlen(line) <= 1)
		continue;
	  if(sscanf(line,"%d %s64[\n]",&sec,msg) < 2) {
		fprintf(stderr,"Bad command\n");
		continue;
	  }
	  pid = fork();
 	  if(pid > 0) {
		
			
			//do {
				if(-1 == (status = waitpid(0,NULL,WNOHANG)))
					  printf("error\n");
					break;
			
			}while(status);
			
	   }
	  else if(pid == 0){

		sleep(sec);
		printf("(%d)  %s\n",sec,msg);
		exit(0);
	    }    
	}
}
