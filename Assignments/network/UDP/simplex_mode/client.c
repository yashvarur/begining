# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/socket.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# define SIZE 100
int main(int argc, char ** argv)
{
	int socket_des;
        struct sockaddr_in client;
        char *buf = malloc(SIZE);
        /* AF_INET means IPV4 family */
        client.sin_family = AF_INET;

        /* port number through terminal */
        client.sin_port = htons(atoi(argv[1]));

        /* donot bind to specific ip adress */
        client.sin_addr.s_addr = INADDR_ANY;

        /* create a socket and return descriptor */
        socket_des = socket(AF_INET,SOCK_DGRAM,0);
        if(socket_des == -1)
                printf("error in socket creation\n");
	
	/* read the message through terminal */
	printf("Enter the message to send\n");
	fgets(buf, SIZE,stdin);
	
	/* sendto() send the messages through connectionless or connection mode */	
	sendto(socket_des, buf, strlen(buf), 0, (struct sockaddr *)&client, sizeof(client) );
	return 0;
}
