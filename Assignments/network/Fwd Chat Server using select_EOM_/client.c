# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <stdlib.h>



void thread_read_function(int  args)
{
	int new_soc_fd = args;
	char * buf = (char *) malloc (30);
	int status;
	while(1){
		status = recv (new_soc_fd,buf,5000,0);
		      if (status > 0)
		printf("Recived : %s\n",buf);
		memset(buf,'\0',5000);

	}

}

void thread_write_function(int args)
{
	int new_soc_fd = args;
	char * buf = (char *)malloc(30);

	int status;


	while(1){
		fgets(buf,5000,stdin);
		__fpurge(stdin);
		*(buf + strlen(buf)-1) = '\0';
		status = send (new_soc_fd,buf,5000,0);
		memset(buf,'\0',5000);

	}

}



int main(int argc, char *argv[])
{

	int soc_fd;
	int port_no;
	int new_soc_fd1;
	struct sockaddr_in soc;
	struct sockaddr_in soc1;
	struct in_addr in;
	int i,len;
	int status;
	int pid;
	int new_soc_fd;
	char buff[5000];
	soc_fd = socket (AF_INET , SOCK_STREAM , 0);
	if (soc_fd == -1)
	{
		printf("socket adress error\n");
	}

	if (argv[1] == NULL||argv[2]==NULL)
	{
		printf("Please enter IP adress and Port number\n");
		exit(0);
	}

	status = inet_aton (argv[1],&in);
	
	port_no = atoi(argv[2]);

	soc.sin_family = AF_INET;
	soc.sin_port = htons(port_no);
	soc.sin_addr.s_addr = in.s_addr;

	status = connect (soc_fd ,(struct sockaddr *)&soc,sizeof(soc));
	perror("connect");


	pthread_t th_id_write;
	pthread_t th_id_read;
	status = pthread_create(&th_id_read,NULL,thread_read_function,soc_fd);
	if (status < 0)
	{
		perror("thread read : ");
	}
	status = pthread_create(&th_id_write,NULL,thread_write_function,soc_fd);
	if (status < 0)
	{
		perror("Thread Write : ");
	}



	pthread_exit(NULL);


	return 0;
}

