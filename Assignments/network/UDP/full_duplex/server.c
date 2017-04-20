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
	socklen_t len;
	/* AF_INET means IPV4 family */
	server.sin_family = AF_INET;

	/* port number through terminal */
	server.sin_port = htons(atoi(argv[1]));

	/* donot bind to specific ip adress */
	server.sin_addr.s_addr = INADDR_ANY;
	
	len = sizeof(server);
	/* create a socket and return descriptor */
	socket_des = socket(AF_INET,SOCK_DGRAM,0);
	if(socket_des == -1)
		printf("error in socket creation\n");
	
	/* The bind() function shall assign a local socket address  address  to  a socket identified by descriptor */
	if(bind(socket_des, (struct sockaddr *)&server,sizeof(server)) == -1)
		printf("error in binding\n");

	while(1) {
		pid_t pid;
		pid = fork();
		if(pid > 0) {
			char *buf = malloc(SIZE);
			/* received the message from socket connection or connectionless*/
			recvfrom(socket_des,buf, 60, 0, (struct sockaddr *)&server,&len);
			printf("received message = %s\n",buf);
		}
		else if(pid == 0) {
			char *buf1 = malloc(SIZE);
			printf("enter the message to send\n");
			fgets(buf1,SIZE,stdin);
			printf("%d\n",sendto(socket_des, buf1, strlen(buf1), 0, (struct sockaddr *)&server, sizeof(server)));
		}

	}
	return 0;
}
	
	
	

	
