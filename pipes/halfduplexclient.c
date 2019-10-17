#define HALF_DUPLEX "halfdup"
#define MAX_SIZE 255

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
void main(int argc,char *argv[])
{
	int fd;
	fd=open(HALF_DUPLEX,O_WRONLY);
	write(fd,"hello server",13);
}

