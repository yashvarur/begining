# include <time.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <unistd.h>
# include <mqueue.h>
int main()
{
    int status;
    struct mq_attr mq;
    struct timespec t;
    mqd_t md;
    char *ptr;
    ptr = malloc(10);
    mq.mq_maxmsg = 10;
    mq.mq_msgsize = 8096;
    t.tv_sec = 10; 
    md = mq_open("/sagar",O_RDWR|O_CREAT,0666,&mq);
    printf("enter the  message\n");
    scanf("%s",ptr);
   __fpurge(stdin); 
    getchar();
    status = mq_getattr(md,&mq);
    printf("message queue attributes\n");
    printf("msgsize = %d\n",mq.mq_msgsize);
    printf("maxmsg = %d\n",mq.mq_maxmsg);
	printf("md = %d \n",md);

    status = mq_timedsend(md,ptr,mq.mq_msgsize,1,&t);
    
	if(status == -1)
            printf("error in sending\n");
    else
	   printf("message successfully sent\n");
    mq_close(md);
}
