# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <unistd.h> 
# include <mqueue.h>
int main()
{
	struct mq_attr mq;
	mq.mq_msgsize = 20;
    mqd_t md;
    size_t len;
    int n;
    int status;
    int i;
    char *rece;
    char *ptr;
    printf("enter the number of message\n");
    scanf("%d",&n);
    printf("enter the %d message\n",);
    ptr = malloc(10);
    scanf("%s",ptr[i]);
    len = len + strlen(ptr[i]);
    for( i = 0 ; i < n ;i++ )
        printf("%s\n",ptr[i]);
    printf("len = %d\n",len);
	mq.mq_maxmsg = 100;
	md = mq_open("/yash",O_RDWR|O_CREAT,0600,&mq);
	if(md == -1)
		printf("error in opening\n"); 
    else {
         status = mq_send(md,ptr,len,0);
         if(status == -1) {
             printf("error in sending\n");
         }
        
            rece = malloc(10);
         status = mq_receive(md,rece,len,NULL);
         if(status == -1)
              printf("error in receiving\n");
        
            printf("%s\n",rece);

    }
	return 0;
}
