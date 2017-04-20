/* server side program */
# include <stdio.h>
# include <stdlib.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# include <string.h>
# include <sys/socket.h>
# define SIZE 100
int main(int argc, char **argv)
{
	int socket_des;
	struct sockaddr_in server;
	int new_socket;
	pid_t pid;

	/* AF_INET = IPV4 family */
	server.sin_family = AF_INET;

	/*INADDR_ANY not bind to specific IP */
	server.sin_addr.s_addr = INADDR_ANY;
    //server.sin_addr.s_addr = inet_addr("172.16.6.136");
	/* assign port number through terminal */
	server.sin_port = htons(atoi(argv[1]));

	/* create the socket and return descriptor of that socket*/
	socket_des = socket(AF_INET,SOCK_STREAM,0);
	if(socket_des == -1)
		printf("error in socket creation\n");

	/* The  bind() function shall assign a local socket address to a socket */	
	if( bind( socket_des,(struct sockaddr *)&server,sizeof(server)) == -1)
		printf("error in binding\n");
	
	/* listen for socket connections and limit the queue of  incoming connections */
	if(listen(socket_des,SOMAXCONN) == -1)
                printf("error in connection\n");
	
	printf("waiting for connection\n");
	/* accept a connection on socket and create new socket without affecting origional socket*/
	if( (new_socket = accept(socket_des,(struct sockaddr *)NULL,NULL)) == -1)
		printf("error in accept\n");

	
	while(1) {
		pid = fork();
		if(pid > 0) {		
			/* Parent process to send a message */
			char *buf = malloc(SIZE);
			printf("Enter the message to send\n");
			fgets(buf,60,stdin);
			send(new_socket, buf, strlen(buf), 0);
		}
		else if(pid == 0) {
			/* child process to receive message */
			char * buf = malloc(SIZE);
			recv(new_socket, buf, 60, 0);
			printf("received message = %s\n",buf);
		}
	}
	
	return 0;
}
