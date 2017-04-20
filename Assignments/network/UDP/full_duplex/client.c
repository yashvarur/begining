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
	struct sockaddr_in client;
	socklen_t len;
	/* AF_INET means IPV4 family */
	client.sin_family = AF_INET;

	/* port number through terminal */
	client.sin_port = htons(atoi(argv[1]));

	/* donot bind to specific ip adress */
	client.sin_addr.s_addr = INADDR_ANY;
	
	len = sizeof(client);

	/* create a socket and return descriptor */
	socket_des = socket(AF_INET,SOCK_DGRAM,0);
	if(socket_des == -1)
		printf("error in socket creation\n");
	
	while(1) {
		pid_t pid;
		pid = fork();
		if(pid > 0) {
			printf("in childprocess\n");
			char *buf = malloc(SIZE);
			/* receive the message from socket connection or connectionless*/
			recvfrom(socket_des,(void *) buf, 60, MSG_CONFIRM, (struct sockaddr *)NULL,NULL);
			printf("received message = %s\n",(char*)buf);
		}
		else if(pid == 0) {
			char *buf1 = malloc(SIZE);
			printf("enter the message to send\n");
			fgets(buf1,SIZE,stdin);
			sendto(socket_des, buf1, strlen(buf1), MSG_CONFIRM, (struct sockaddr *)&client, sizeof(client));
		}
	}
	return 0;
}
	
	
	

	
