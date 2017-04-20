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
	socklen_t len;
	struct sockaddr_in client;

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
		
				char *buf1 = malloc(SIZE);
                printf("Enter the meaasge to send\n");
                fgets(buf1, SIZE, stdin);
                sendto(socket_des, buf1, strlen(buf1), 0, (struct sockaddr *)&client, sizeof(client));

		char *buf = malloc(SIZE);
		/* received the message from socket ---connection oriented or connectionless*/
		recvfrom(socket_des,buf, 60, 0, (struct sockaddr *)&client,&len);
		printf("received message = %s\n",buf);
	}
		return 0;
}
	
	
	

	
