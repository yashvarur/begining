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
   char *rece;
   mq.mq_maxmsg = 10;
   mq.mq_msgsize = 8096;
   rece = malloc(10);
   ptr = malloc(10);
   md = mq_open("/sagar",O_RDWR|O_CREAT,0666,&mq);
   pid_t  pid = fork();
   if(pid > 0) {
        wait(NULL);
        printf("md = %d\n",md);
 //       status = mq_receive(md,rece,mq.mq_msgsize,NULL);
        printf("coming\n");
   //     printf("%s\n",rece);
	    mq_close(md);
    }
    else {
         size_t len;
         int n;
         int status;
         int i;
         printf("enter the  message\n");
         scanf("%s",ptr);
         printf("send = %s\n",ptr);
         mq.mq_msgsize = strlen(ptr);
         status = mq_send(md,ptr,mq.mq_msgsize,1);
        // if(status == -1) 
          //   printf("error in sending\n");
                
     } 
     //mq_unlink("/sagar");
}
