
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
	mqd_t md;
	char *rece;
    int sec = 0;
    int *p = &sec;
	int status;
	struct mq_attr old_attr;
	struct mq_attr new_attr;
	struct timespec t;

	t.tv_sec = 10;
	rece = malloc(10);

	md = mq_open("/a",O_RDONLY);
    if(md == -1)
	    printf("error in receiving\n");

	printf("printing the new attributes\n");
	new_attr.mq_msgsize = 800;
	new_attr.mq_maxmsg  = 50;

	status = mq_setattr(md, &new_attr, &old_attr);

	printf("msgsize = %d\n",new_attr.mq_msgsize);
    printf("maxmsg = %d\n",new_attr.mq_maxmsg);

	if(md != -1) {
		status = mq_timedreceive(md, rece, 8096,p,&t);
		if(status == -1)
			printf("error in receiving\n");
		else {
			printf("message received is = %s\n",rece);

		}
	}

	mq_close(md);
			mq_unlink("/a");
	return 0;
}
	
