#include<stdio.h>
#include<stdlib.h>
void main()
{
int n,pid,fd[2];
char buff[50];
pipe(fd);
pid=fork();
if(pid==0)
{
close(fd[0]);
write(fd[1],"hello child",12);
printf("\n data written by child");
}
else{
close(fd[1]);
sleep(1);
n=read(fd[0],buff,sizeof(buff));
printf("\n data read from child:\n%s\n",buff);
}
}
