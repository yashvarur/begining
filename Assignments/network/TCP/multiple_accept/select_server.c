# include <stdlib.h>
# include <stdio.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# include <string.h>
# include <sys/socket.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>
# define SIZE 1000

void handle_client(int new_socket, fd_set *set)
{
	char * buf = malloc(SIZE);
	//fgets(buf, 60, stdin);
	recv(new_socket,buf,60,0);
	printf("%s",buf);
}
int main(int argc, char **argv)
{
	int socket_des;
	struct sockaddr_in server;
	fd_set fd;
	fd_set readfd;
	int maxsocket;
	
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

	/* enble the socket to reuse the adress */
	if(setsockopt(socket_des, SOL_SOCKET, SO_REUSEADDR, &readfd, sizeof(int) ) == -1)
		printf("error in setsocket\n");

	/* bind associates the local adress to socket */
	if(bind(socket_des, (struct sockaddr *)&server, sizeof(server)) == -1)
		printf("error in binding\n");
	
	
	if(listen(socket_des, 10))
	
	printf("--->%d\n",socket_des);
	FD_ZERO(&fd);
	FD_SET(socket_des, &fd);
	maxsocket = socket_des;
	
	char temp;
	while(1) {
		readfd = fd;
		if(select(maxsocket + 1, &readfd, NULL, NULL, NULL) == -1)
			printf("error in select\n");
		//for(i = 0; i <= maxsocket; i++) {
			FD_SET(socket_des,&readfd);
				int new_socket;
				/* create new socket and return new descriptor */
				if( (new_socket = accept(socket_des, (struct sockaddr*)NULL,NULL)) == -1 )
					printf("error in accept\n");
				FD_SET(new_socket,&fd);
				if(new_socket > maxsocket)
					maxsocket = new_socket;
				handle_client(new_socket, &fd);
			
		//}
		

	}
	return 0;
}
