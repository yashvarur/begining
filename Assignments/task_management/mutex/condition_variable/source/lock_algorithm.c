# include "header.h"
void insert(NODE* new_node)
{
	NODE *temp;
	NODE *prev;	
	temp = head;
	
	if(head == NULL) { 
		head = new_node;
		data -> head = head;		
		pthread_cond_signal(&data -> c);

		
	}
	else {


		if(new_node -> seconds < head -> seconds) {
			new_node -> next = head;
			head = new_node;
			pthread_cond_signal(&data -> c);
			return;	
		}
		

		while(temp ){
                    if(temp -> seconds > new_node -> seconds) {
                             prev -> next = new_node;
                             new_node -> next = temp;
                             return;
                    }
                    prev = temp;
                    temp = temp -> next;
                }
                if((temp ==  NULL ) ) {
                      prev -> next  = new_node;

                }

	}
	
	
}
void  thread_fun(void *p)
{
	
	int status;
	int sec;
	int s;
	char msg[100];
	NODE *temp;
	struct timespec ts = {0};

	while(1) {
			

			while(head == NULL) { 
			 	status = pthread_cond_wait(&data -> c,&data -> mutex);
				continue;
			 }
			
			temp = head;
			sec = temp -> sec;
			s = temp -> seconds;
		 	strcpy(msg,temp -> msg);
			ts.tv_sec = sec - time(NULL);
		 	pthread_mutex_unlock(&data -> mutex);	
			pthread_cond_timedwait(&data -> c,&data -> mutex,&ts);				
			if(head -> sec == time(NULL)) {
				printf("head == time\n");
				printf("(%d) %s\n",head -> seconds,head -> msg);
				printf("(%d) %s\n",head -> sec,head -> msg);
				head = head -> next;
				//data -> head = head;
			}
				
			if(temp -> sec <= time(NULL)) {
				 pthread_mutex_unlock(&data -> mutex);
				 continue;
			}
						
			status = pthread_mutex_unlock(&data -> mutex);	 
	}
    
				
	

	
}
 
NODE *create_node(int s, char *m)
{
	NODE *new_node = malloc(sizeof(NODE));
	new_node -> sec = (s + time(NULL));
	new_node -> seconds = s;
	new_node -> msg = m;
	new_node -> next = NULL;
	return new_node;
}

int main()
{
        
        int status;
	NODE *node = NULL;
	NODE *t;
	int sec;	
	char msg[100];
	data = malloc(sizeof(MUTEX));
        pthread_t tid;
	status = pthread_create(&tid,NULL,thread_fun,NULL);
        status = pthread_mutex_init(&data -> mutex,NULL);
	status = pthread_cond_init(&data -> c,NULL);
	if(status != 0)
		printf("init error\n");
	while(1) {
		printf("Alarm>  ");	
		fgets(line,sizeof(line),stdin);
		if(strlen(line) <= 1)
                	continue;
		if(sscanf(line,"%d %s64[\n]",&sec,msg) < 2) 
              		fprintf(stderr,"Bad command\n");

		node = create_node(sec,msg);
	    	status = pthread_mutex_lock(&data -> mutex);
        	if(status != 0)
                	printf("mutex  lock error\n");

	        insert(node);
		

	//	#if 0
			t = head;
		while(t -> next != NULL){
                                printf("%d\n",t -> seconds);
                                t = t -> next;
                        }
                        printf("%d\n",t -> seconds);
	//	#endif
	    	status = pthread_mutex_unlock(&data -> mutex);
     	
	}	
     		pthread_mutex_destroy(&data -> mutex);
		//free(data);
        return 0;
}

