#include <fcntl.h>
#include <mqueue.h>

# include <stdio.h>
# include <mqueue.h>
# include <fcntl.h>           
# include <sys/stat.h> 
int main(int argc, char *argv[])
{
    mqd_t mq;           
    struct mq_attr ma;   
    int status = 0;
    int a = 5;
    int b = 0;

    printf("a = %d, b = %d\n", a, b);

    
    ma.mq_flags = 0;                
    ma.mq_maxmsg = 16;              
    ma.mq_msgsize = sizeof(int);    
    ma.mq_curmsgs = 0;              

    
    mq = mq_open("/test_queue", O_RDWR | O_CREAT, 066, NULL);

    
    if (mq == -1)
    {
        printf("Failed to create queue.\n");
        status = 1;
    }

    if (status == 0)
    {
        status = mq_send(mq, (char *)(&a), sizeof(int), 1);
    }

    if (status == 0)
    {
        status = mq_receive(mq, (char *)(&b), sizeof(int), NULL);
    }

    if ((status == 0) && (mq_close(mq) == -1))
    {
        printf("Error closing message queue.\n");
        status = 1;
    }

    if ((status == 0) && (mq_unlink("test_queue") == -1))
    {
        printf("Error deleting message queue.\n");
        status = 1;
    }

    printf("a = %d, b = %d\n", a, b);

    return status;
} 
