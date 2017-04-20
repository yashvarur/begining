# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# define SIZE 100
int main(int argc, char ** argv)
{
	int socket_des;
	struct sockaddr_in server;
	char *buf = malloc(SIZE);
	/* AF_INET means IPV4 family */
	server.sin_family = AF_INET;

	/* port number through terminal */
	server.sin_port = htons(atoi(argv[1]));

	/* donot bind to specific ip adress */
	server.sin_addr.s_addr = INADDR_ANY;
	
	/* create a socket and return descriptor */
	socket_des = socket(AF_INET,SOCK_DGRAM,0);
	if(socket_des == -1)
		printf("error in socket creation\n");
	
	/* The bind() function shall assign a local socket address  address  to  a socket identified by descriptor */
	if(bind(socket_des, (struct sockaddr *)&server,sizeof(server)) == -1)
		printf("error in binding\n");

	/* received the message from socket connection or connectionless*/
	recvfrom(socket_des,(void *) buf, 60, 0, (struct sockaddr *)NULL,NULL);
	printf("received message = %s\n",(char*)buf);
	return 0;
}
	
	
	

	
