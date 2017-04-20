# include <sys/types.h>
# include <sys/socket.h>
# include <stdlib.h>
# include <netinet/in.h>
# include <netdb.h>
# include <stdio.h>
# include <sys/socket.h>
# include <stdio.h>
# include <string.h>
# define SIZE 100
int main(int argc, char **argv)
{
        char *buff = malloc(SIZE);
	int socket_des;
	struct sockaddr_in client;

	client.sin_family = AF_INET;
	client.sin_addr.s_addr = inet_addr("172.16.9.136");
	client.sin_port = htons(atoi(argv[1]));
	socket_des = socket(AF_INET,SOCK_STREAM,0);
	if(socket_des == -1)
		printf("error in socket creation\n");
//	if( bind(socket_des,(struct sockaddr *)&client,sizeof(client)) == -1)
  //              printf("error in bind\n");

	if(connect(socket_des,(struct sockaddr *)&client,sizeof(client)) == -1)
		printf("error in connect\n");
     
    	printf("enter the message to send\n");
    	fgets(buff,64,stdin);
   	// recv(socket_des, buff, 60, 0);
   	//printf("received message = %s\n",buff);
   	printf("%d\n", send(socket_des,buff,strlen(buff),100));
	
    
}
	
	
