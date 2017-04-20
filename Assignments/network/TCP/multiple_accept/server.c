# include <stdlib.h>
# include <stdio.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# include <string.h>
# include <sys/socket.h>
# define SIZE 1000
void *thread_fun(int *p)
{
	int i;
	if(*p != -1)
		printf("connection established\n");
	char * buf = malloc(SIZE);
	//int a[10];
	//for(i=0; i < 2 ; i++)
	//	a[i] = *p;
	//for(i = 0 ; i < 2 ; i++)
		recv(*p, buf, 65, 0);
	printf("%s",buf);	
}
int main(int argc, char **argv)
{
	int socket_des;
	struct sockaddr_in server;
	int new_socket;
	pthread_t tid;
	int status;
	/* AF_INET IPV4 famiy */
	server.sin_family = AF_INET;

	/* port number through terminal */
	server.sin_port = htons(atoi(argv[1]));

	/* do not bind to an specific ip*/
	server.sin_addr.s_addr = INADDR_ANY;
	
	/* create a socket and return socket descriptor */
	socket_des = socket(AF_INET, SOCK_STREAM,0);
	if(socket_des == -1)
		printf("error in socket of creation\n");
	
	/* bind associates the local adress to socket */
	if(bind(socket_des, (struct sockaddr *)&server, sizeof(server)) == -1)
		printf("error in binding\n");

	if(listen(socket_des, 10))
		printf("error in listen\n");
	
	while(5) {
		/* create new socket and return new descriptor */
		if( (new_socket = accept(socket_des, (struct sockaddr*)NULL,NULL)) == -1 )
			printf("error in accept\n");
			
		/* creating thread */
		status = pthread_create(&tid, NULL, thread_fun, &new_socket);
		if(status != 0)
			printf("thread creation failed\n");
	
	}
	return 0;
}
