# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <stdlib.h>


fd_set read_fds;
int new_soc_fd[10];
int i = 0;
int no_of_connections = 0;
int write_fd = 0;


void thread_write_function(int args)
{

	char * buf = (char *)malloc(30);
	int status;
	int j = 0;
	while(1)
	{
		fgets(buf,5000,stdin);
		__fpurge(stdin);
		*(buf + strlen(buf)-1) = '\0';
#if 0
		if (write_fd == 0)
		{

		}
		else
		{
			printf("message sent to socket : %d\n",write_fd);
			status = send (write_fd,buf,5000,0);
		}
#endif
			for (j = 0; j < no_of_connections ; j++)
			{
				printf("message sent to socket : %d\n",new_soc_fd[j]);
				status = send (new_soc_fd[j],buf,5000,0);
			}
	}

}



int main(int argc , char *argv[])
{
	int soc_fd;
	struct sockaddr_in soc;
	struct in_addr addr;
	struct in_addr in;
	int addr1;
	char buf[5000];
	int status;
	socklen_t len;
	unsigned char buffer[sizeof(struct in_addr)];
	int port_no;
	int pid;
	int i;
	
	soc_fd = socket (AF_INET ,  SOCK_STREAM ,0);
	if (soc_fd == -1 )
	{
		printf("socket error\n");
	}

	if (argv[1] == NULL)
	{
		printf("please enter Port number\n");
		exit(0);
	}


	port_no = atoi(argv[1]);
	soc.sin_family = AF_INET;
	soc.sin_port =  htons(port_no);
	soc.sin_addr.s_addr = INADDR_ANY;


	if((i = bind(soc_fd,(struct sockaddr *)&soc,sizeof(soc))) < 0)
		printf("bind problem\n");
		i = listen(soc_fd,5);
	printf("waiting for connection....\n");
	len = sizeof(soc);

	pthread_t th_id_write;

	FD_ZERO(&read_fds);

	status = pthread_create(&th_id_write,NULL,thread_write_function,NULL);
	if (status < 0)
	{
		perror("Thread Write : ");
	}
	FD_SET (soc_fd , &read_fds);
	i = 0;
	int j = 0;
	int k;
	while (1)
	{

		status = select (FD_SETSIZE , &read_fds , NULL , NULL , NULL);
		if (status < 0)
		{
			perror ("select ");
		}
	
		if (FD_ISSET (soc_fd , &read_fds))
		{
			new_soc_fd[i] = accept (soc_fd,(struct sockaddr *)&soc,&len);
			FD_SET (new_soc_fd[i] , &read_fds);
			no_of_connections++;
			printf("no of connections = %d\n",no_of_connections);
			printf("connected...\n");
			in.s_addr = soc.sin_addr.s_addr;
			char *ptr = inet_ntoa(in);
			printf("%s\n",ptr);
			printf("connection with socket : %d\n",new_soc_fd[i]);
			i++;
		}
		else
		{
			for (j = 0; j < no_of_connections ; j++)
			{
				if (FD_ISSET (new_soc_fd[j] , &read_fds))
				{
					write_fd = new_soc_fd[j];
					status = recv (new_soc_fd[j],buf,5000,0);
				for (k = 0; k < no_of_connections ; k++)
				{
					if(write_fd != new_soc_fd[k]) {
						printf("message sent to socket : %d\n",new_soc_fd[j]);
						status = send (new_soc_fd[k],buf,5000,0);
					}
				}
					if (status > 0)
					{
						printf("Recived : %s\n",buf);
						printf("message recived from : %d\n",new_soc_fd[j]);
					}

				}
			}
		}
		int j = 0;
		FD_SET (soc_fd, &read_fds);
		for (j = 0 ; j < no_of_connections ; j++)
			FD_SET (new_soc_fd[j] , &read_fds);
	}

	pthread_exit(NULL);
	return 0;
}

