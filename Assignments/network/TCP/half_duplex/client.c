# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <netinet/in.h>
# include <netinet/ip.h> 
# include <sys/socket.h>
# define SIZE 1000
int main(int argc,char **argv)
{
    int socket_des;
    int a;
    struct sockaddr_in client;
    client.sin_family = AF_INET;
    client.sin_addr.s_addr = inet_addr("172.16.9.136");
  //  client.sin_addr.s_addr = INADDR_ANY;
    client.sin_port = htons(atoi(argv[1]));
    socket_des = socket(AF_INET,SOCK_STREAM,0);
    if(socket_des == -1)
       printf("error in socket creation\n");
    if(connect(socket_des,(struct sockaddr *)&client,sizeof(client)) == -1)
       printf("error in connect\n");
    while(1) {
            char *buf = malloc(SIZE);
	     printf("enter the message to send\n");
            fgets(buf,64,stdin);
            send(socket_des,buf,strlen(buf),0);
            char * buf1 = malloc(SIZE);
	        printf("received message\n");
            recv(socket_des,buf1,60,0);
            printf("%s",buf1);
    }
}	
