# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
int t_status;
void *thread_fun(void *p)
{
	printf("PID of thread = %d\n",getpid());
	printf("I am in thread function\n");
	t_status = 245;
	return &t_status;
	//pthread_exit(&t_status);

}
int main()
{	
	int status;
	int *ret;
	int t_id;
//	pthread_t t_id;
//	ret = malloc(sizeof(int));
	printf("t_id ---> %d\n",t_id);
	printf("t_id ---> %d\n",pthread_self());
	status = pthread_create(&t_id,NULL,thread_fun,NULL);
	if(status != 0)
		printf("thrad creation failed\n");
	else
		printf("successful creation of thraed\n");

	printf("ret = %d\n",ret);
	//pthread_detach(t_id);
	status = pthread_join(t_id,(void**)&ret);
	if(status != 0)
		printf("pthread join failed %d\n",strerror(status));
	//else
		printf("ret = %d\n",*ret);
	
	printf("t_id ---> %d\n",t_id);
	//pthread_exit(0);
//	print("coming\n");
	return 0;
}
