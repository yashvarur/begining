# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
void *thread_fun()
{
	int i;	
	int status;
	pthread_attr_t attr;
	struct sched_param p;
	printf("\n\n********************thread function before modification*************************\n");
    status = pthread_attr_getschedpolicy(&attr,&i);
    if(i == SCHED_FIFO) 
          printf("FIFO\n");
    else if(i == SCHED_RR)
          printf("RR\n");
    else
          printf("SCHED_OTHER\n");
    pthread_attr_getschedparam(&attr,&p);
    printf("priority = %d\n",p.sched_priority);
    printf("***********************************************************************************\n\n");
    printf("USING PTHREAD_GETSCHEDPARAM\n");
    pthread_getschedparam(pthread_self(),&i,&p);
    if(i == SCHED_FIFO)
          printf("FIFO\n");
    else if(i == SCHED_RR)
          printf("RR\n");
    else
          printf("SCHED_OTHER\n");
    printf("priority = %d\n",p.sched_priority);
    printf("MAX priority = %d\n",sched_get_priority_max(i));
    printf("MIN priority = %d\n",sched_get_priority_min(i));
    printf("************************thread function after modification****************************\n\n");
	p.sched_priority = 98;
	pthread_setschedparam(pthread_self(),SCHED_RR,&p);
	pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    pthread_getschedparam(pthread_self(),&i,&p);
    if(i == SCHED_FIFO)
          printf("FIFO\n");
    else if(i == SCHED_RR)
          printf("RR\n");
    else
          printf("SCHED_OTHER\n");
    printf("priority = %d\n",p.sched_priority);
    printf("MAX priority = %d\n",sched_get_priority_max(i));
    printf("MIN priority = %d\n",sched_get_priority_min(i));
    printf("******************************************************************************\n"); 
}	
int main()
{
	int status;
	int i;
	pthread_t tid;
	#if 0
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	status = pthread_attr_setschedpolicy(&attr,SCHED_FIFO);
	pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	status = pthread_attr_getschedpolicy(&attr,&i);
	if(status == 0) {
		if(i == SCHED_FIFO)
			printf("FIFO\n");
		else if (i == SCHED_RR)
			printf("RR\n");
		else
			printf("main - SCHED_OTHER\n");
	}
	#endif
	status = pthread_create(&tid,NULL,thread_fun,NULL);
	pthread_exit(0);
	return 0;
}
