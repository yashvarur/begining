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
    mqd_t md;
    char *ptr;
    ptr = malloc(10);
    char *ptr1 = malloc(10);
    mq.mq_maxmsg = 10;
    mq.mq_msgsize = 8096;
    md = mq_open("/a",O_RDWR|O_CREAT,0666,&mq);
   // printf("descriptor = %d\n");
    printf("enter the  message\n");
    fgets(ptr,20,stdin);
    __fpurge(stdin);
    //getchar();
    status = mq_getattr(md,&mq);
    printf("message queue attributes\n");
    printf("msgsize = %d\n",mq.mq_msgsize);
    printf("maxmsg = %d\n",mq.mq_maxmsg);

    status = mq_send(md,ptr,mq.mq_msgsize,1);
    if(status == -1)
            printf("error in sending\n");
    else {
	   printf("message successfully sent\n");
           sleep(100);
	}
    mq_close(md);
}
