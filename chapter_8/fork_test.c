#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main (void)
{
   int count = 0;
   pid_t pid;        /*��ʱ����һ������*/
   pid = fork();      /*��ʱ�Ѿ�������������ͬʱ����*/
   if(pid < 0)
     {
        printf("error in fork!");
        exit(1);    /* fork�����˳�*/
     }
   else if(pid==0)
     printf("I am the child process, the count is %d, my process ID is %d\n",count,getpid());
   else
     printf("I am the parent process, the count is %d, my process ID is %d\n",++count,getpid());
   return 0;
}
