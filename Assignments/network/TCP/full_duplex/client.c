# include <stdio.h>
# include <stdlib.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# include <string.h>
# define SIZE 100
int main(int argc, char **argv)
{
		int socket_des;
        struct sockaddr_in client;
        int new_socket;
        pid_t pid;
		int i;
        /* AF_INET = IPV4 family */
        client.sin_family = AF_INET;
        /*INADDR_ANY not bind to specific IP */
        client.sin_addr.s_addr = inet_addr("172.16.9.136");
	//printf("%s",inet_ntoa(client.sin_addr.s_addr));
		
		printf("%d",client.sin_addr.s_addr);

		
        //client.sin_addr.s_addr = INADDR_ANY;
        /* assign port number through terminal */
        client.sin_port = htons(atoi(argv[1]));

        /* create the socket and return descriptor of that socket*/
        socket_des = socket(AF_INET,SOCK_STREAM,0);
        if(socket_des == -1)
                printf("error in socket creation\n");

	/* The  connect()  system call connects the socket referred to by the file descriptor socket_des to specified addr*/
	if(connect(socket_des,(struct sockaddr *)&client,sizeof(client)) == -1)
		printf("error in connection\n");
	else
		printf("connected successfully");
	
	pid = fork();
	if(pid >0) {
		while(1) {
			char * buf = malloc(SIZE);
				recv(socket_des,buf,60,0);
					printf("received message = %s\n",buf);
			}
		}
		
		else if(pid == 0) {
			while(1) {
				char * buf = malloc(SIZE);
				printf("Enter the message to send\n");
				fgets(buf,SIZE,stdin);
				printf("%d",send(socket_des,buf,strlen(buf),0));
			}
		}
	
	return 0;
}
			
