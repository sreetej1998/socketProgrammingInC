#define HALF_DUPLEX "halfdup"
#define MAX_SIZE 255

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

void main()
{
	int fd,numread;char buf[MAX_SIZE];
	printf("starting server");
    	fd = open(HALF_DUPLEX, O_RDONLY);
    	numread = read(fd, buf, MAX_SIZE);
    	buf[numread] = '0';
    	printf("Half Duplex Server : Read From the  pipe : %s\n", buf);	
}

