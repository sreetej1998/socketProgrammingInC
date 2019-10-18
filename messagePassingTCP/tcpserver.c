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

int main(int argc,char *argv[]){
int n,bindFd,socketFd,connectFd;
char s[1024];
socklen_t len;
struct sockaddr_in servaddr,cliaddr;
//creating the socket
socketFd=socket(AF_INET,SOCK_STREAM,0);

//clearing the memory
memset(&servaddr,0,sizeof(servaddr));

//initializing the server
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(3000);
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

//binding the server with port
bindFd=bind(socketFd,(struct sockaddr*)&servaddr,sizeof(servaddr));

//listening plus setting the backlog
listen(socketFd,5);

for(;;){
printf("waiting ...");
len=sizeof(cliaddr);
connectFd=accept(socketFd,(struct sockaddr*)&cliaddr,&len);
if(connectFd<0) continue;
n=read(connectFd,s,1024);
s[n]='\0';
printf("connected the word is %s\n",s);
close(connectFd);
printf("finished serving first client\n");
}
}
