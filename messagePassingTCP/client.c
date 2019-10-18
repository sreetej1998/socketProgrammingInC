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

  printf("enter the string that should be send to the server\n");
  while (1) {
    c = getchar();
    if (c == '#') break;
    message[i++] = c;
  }
  message[i] = '\0';
  write(socketFd, message, strlen(message));
  close(socketFd);
}
