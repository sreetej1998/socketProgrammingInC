#include<stdio.h>
#include<stdlib.h>
void main()
{
int n,fd[2];
char buff[100];
pipe(fd);
printf("\n read fd:%d",fd[0]);
printf("\n write fd:%d",fd[1]);
write(fd[1],"hello",6);
n=read(fd[0],buff,sizeof(buff));
printf("\n read data:%s",buff);
}
