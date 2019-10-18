#include	<stdio.h>

#include	<stdlib.h>

#include	<unistd.h>

#include	<errno.h>

#include	<string.h>

#include	<sys/types.h>

#include	<sys/stat.h>

#include	<sys/socket.h>

#include	<netinet/in.h>

#include	<arpa/inet.h>

#include	<fcntl.h>

#define MAXBUFFER 1024

int main(int argc, char * argv[]) {
  char message[1024], c;
  int socketFd, i = 0;
int total_read=0,n_read;
  char *s=(char*) malloc(100 * sizeof(char));;
  struct sockaddr_in servaddr;
  socketFd = socket(AF_INET, SOCK_STREAM, 0);
  memset( & servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  servaddr.sin_addr.s_addr = inet_addr(argv[1]);
  if (connect(socketFd, (struct sockaddr * ) & servaddr, sizeof(servaddr)) < 0) {
    printf("error in connecting to the server\n");
    exit(1);
  }
 n_read = read(socketFd, s + total_read, 100 - total_read) ;
     
	printf("%s",s);
	free(s);
    

  close(socketFd);
}
