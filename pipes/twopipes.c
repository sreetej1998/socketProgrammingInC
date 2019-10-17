#include<stdio.h>
#include<stdlib.h>
void main()
{
int pid,n,fd1[2],fd2[2];
char buff1[50],buff2[50];
pipe(fd1);
pipe(fd2);
pid=fork();

if(pid==0)
{
close(fd1[0]);
write(fd1[1],"hello from child",17);
close(fd2[1]);
n=read(fd2[0],buff2,sizeof(buff2));
printf("\n data read from parent:%s\n",buff2);
}

else
{
close(fd1[1]);
n=read(fd1[0],buff1,sizeof(buff1));
printf("\n data read from child:%s\n",buff1);
close(fd2[0]);
write(fd2[1],"hello from parent",18);
sleep(1);
}

}
