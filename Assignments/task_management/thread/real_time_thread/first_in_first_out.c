# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>


pthread_attr_t attr;

void *thread_fun(void*v)
{
   
    struct sched_param p;
	int status;
	int i;

	printf("in threadfunction\n");
	status = pthread_attr_getschedpolicy(&attr,&i);
        if(status == 0) {
                if(i == SCHED_FIFO)
                        printf("FIFO\n");
                else if(i == SCHED_RR)
                        printf("RR\n");
                else
                        printf("SCHED_OTHER");
        }
    pthread_attr_getschedparam(&attr,&p);
    printf("priority = %d\n",p.sched_priority);

      

}

int main()
{
    int status;
    int i;
    pthread_t tid;
    pthread_attr_init(&attr);
    struct sched_param p;
    printf("\n\n************  main thread before setting priority and policy***********\n");
	pthread_attr_getschedparam(&attr,&p);
	printf("priority = %d\n",p.sched_priority);
	pthread_attr_getschedpolicy(&attr,&i);
	if(i == SCHED_FIFO)
                        printf("FIFO\n");
	else if(i == SCHED_RR)
			printf("RR\n");
	else
			printf("SCHED_OTHER\n");
	printf("***********************************************************************\n\n");
	printf("************  main thread after setting priority and policy**************\n");
	
        status = pthread_attr_setschedpolicy(&attr,SCHED_FIFO);
	p.sched_priority = 98;
	pthread_attr_setschedparam(&attr,&p);
	
	pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	
	pthread_attr_getschedparam(&attr,&p);
	printf("priority = %d\n",p.sched_priority);
        status = pthread_attr_getschedpolicy(&attr,&i);
        if(status == 0) {
                if(i == SCHED_FIFO)
                        printf("FIFO\n");
                else if(i == SCHED_RR)
                        printf("RR\n");
                else
                        printf("SCHED_OTHER");
        }
	printf("***********************************************************************\n\n");
	status = pthread_create(&tid,&attr,thread_fun,NULL);

	if(status != 0)
		printf("error in thread fun\n");
	pthread_exit(0);
        return 0;
}
