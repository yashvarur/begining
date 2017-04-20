# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
char line[100];
void *thread_fun()
{
	int sec;
	char msg[50];
	
        if(sscanf(line,"%d %s64[\n]",&sec,msg) < 2) {
              fprintf(stderr,"Bad command\n");
       
        }
	sleep(sec);
	printf("(%d) %s",sec,msg);
	fflush(stdout);
	
	
}
int main()
{
	
        int status;
        int pid;
	pthread_t t_id;
	int *ret;
        int st = 0;
        while(1) {
          printf("Alarm> ");
	  
          if(fgets(line,sizeof(line),stdin) == NULL)
                exit(0);
	
          if(strlen(line) <= 1)
                continue;

	  status = pthread_create(&t_id,NULL,thread_fun,NULL);
	  waitpid(-1,NULL,WNOHANG);
	  
	}
	return 0;
}

	
