# include <sys/types.h>
# include <string.h>
# include <stdlib.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netdb.h>
# include <stdio.h>
# include <sys/socket.h>
# define SIZE 100
int main(int argc, char **argv)
{
	int socket_des;
	socklen_t len;
	struct sockaddr_in server;
	char *buffer = malloc(SIZE);
	server.sin_family = AF_INET;/* IPV4 family */
	server.sin_addr.s_addr = INADDR_ANY;/*INADDR_ANY used when you don't need to bind a socket to a specific IP */
	//server.sin_addr.s_addr = inet_addr("172.16.9.136");
	server.sin_port = htons(atoi(argv[1]));/* accepting the port number through command line argument */
	
	socket_des = socket(AF_INET,SOCK_STREAM,0);/* domain is IPV4(AF_INET),type is stream,default protocol */
    
	if(socket_des == -1) {
		printf("error in socket creation\n");
		return;
	}
	//if( (bind(socket_des,(struct sockaddr *)&server,sizeof(server))) == -1)
	//	printf("error in bind\n");
	if(listen(socket_des,SOMAXCONN) == -1)
		printf("error in connection\n");
	len = sizeof(server);
	if((socket_des = accept(socket_des,(struct sockaddr*)&server,&len)) == -1)	
		printf("error in accept\n");
	else
            printf("accept successfully\n");
	printf("client adress = %s\n",inet_ntoa(server.sin_addr.s_addr));
	getchar();
	recv(socket_des, buffer,64 ,0);
	
 	   printf("received data = %s\n",buffer);	
		
	return 0;
}
	
