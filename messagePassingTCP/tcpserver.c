#include	<stdio.h>
#include	<stdlib.h>
#include	<errno.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<sys/wait.h>
#include	<fcntl.h>
#include	<unistd.h>

void readstring(int,char *);
int main(int argc, char *argv[])
{
int socketFd,retBind,connectionSocket,pointer=0,n;
char databuf[50];
char s[1024];
struct sockaddr_in servaddr,cliaddr;
socklen_t len;
socketFd=socket(AF_INET,SOCK_STREAM,0);
memset(&servaddr,0,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(3000);
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

retBind=bind(socketFd,(struct sockaddr*)&servaddr,sizeof(servaddr));

listen(socketFd,5);

for(;;)
{
printf("iam waiting for message from client");
len=sizeof(cliaddr);
connectionSocket=accept(socketFd,(struct sockaddr*)&cliaddr,&len);
if (connectionSocket < 0)
{
	continue;
}
n=read(connectionSocket,s ,1024);
s[n]='\0';
printf("%s",s);
close(connectionSocket);
printf("Finished Serving One Client\n");
}

}



