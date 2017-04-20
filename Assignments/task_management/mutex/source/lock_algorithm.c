# include "header.h"
void insert(NODE* new_node)
{
	NODE *temp;
	NODE *prev;
	NODE *t;
	NODE *ahead;
	t = head;
	temp = head;
	if(head == NULL) { 
		head = new_node;
		data -> head = head;

	}
	else {
		prev = head;

		if((head -> seconds) > (new_node -> seconds))
			printf("not possible to insert\n");
		else {
			if( head -> next == NULL ) {
				head -> next = new_node;
				return;
			}
			#if 0
			 while(t -> next != NULL){
                                printf("%d\n",t -> seconds);
                                t = t -> next;
                        }
                        printf("%d\n",t -> seconds);
			#endif

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
	
}
void  thread_fun(void *p)
{
	
	int status;
	int sec;
	char msg[100];
	NODE *temp;
	while(1) {
		if(head == NULL) {
			sleep(1);
			continue;
	
		}
		else {
		
			status = pthread_mutex_lock(&data -> mutex);	 
			 if(status != 0)
                        	printf("mutex  lock error\n");
			temp = head;
			head = head -> next;
			data -> head = head;
		 	strcpy(msg,temp -> msg);
		 	pthread_mutex_unlock(&data -> mutex);
			if(((int)(temp->sec - time(NULL))) < 0) {
				sec =(int)-(temp -> sec - time(NULL));
				sleep(sec);
			}
			else	
		 	sleep(temp -> sec - time(NULL) );
		 	printf(" (%d) %s\n",temp -> seconds ,msg);

		}
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
	if(status != 0)
		printf("init error\n");
	while(1) {
		printf("Alarm> ");	
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
		t = head;
		while(t -> next != NULL){
                                printf("%d\n",t -> seconds);
                                t = t -> next;
                        }
                        printf("%d\n",t -> seconds);

	    	status = pthread_mutex_unlock(&data -> mutex);
     	
	}	
     		pthread_mutex_destroy(&data -> mutex);
		free(data);
        return 0;
}

