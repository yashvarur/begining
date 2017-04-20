# define _GNU_SOURCE
# include <sched.h>
# include <stdlib.h>
# define STACK_SIZE 8195
# include <stdio.h>
# include <sys/wait.h>
# include <sys/utsname.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h> 
# include <sched.h>
#include <sys/syscall.h>
typedef struct mutex_struct
{
	int value;
	pthread_mutex_t mutex;
	struct mutex_struct *next;
}M;	

char * process_function(M *data)
{

	int status;
	//status = pthread_mutex_lock(&data -> mutex);
	printf("ggggg\n");
	data -> value = 13;

	printf("in thread function\n");
	return &data->value;
	
}
	
int main()
{
	
	int status;
	pthread_t tid;
	M *data = malloc(sizeof(M));
	if(data == NULL)
		printf("alloacte strucuture \n");
	status = pthread_mutex_init(&data -> mutex,NULL); 
	if(status != 0)
		printf("init mutex\n");
	status = pthread_mutex_lock(&data -> mutex);
	if(status != 0)
		printf("mutex  lock error\n");
	data -> value = 24;
	status = pthread_create(&tid,NULL,process_function,&data -> value);
	printf("fffffffffffff\n");
	printf("value of a = %d\n",data -> value);
	pthread_exit(0);
	//free(data);
	return 0;
}
	
