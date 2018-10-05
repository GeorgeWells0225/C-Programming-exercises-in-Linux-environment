#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    pid_t pc,pr;
    if ((pc = fork()) < 0)
    {
       printf("error in fork!");
       exit(1);    /* fork出错退出*/
    }
    else if(pc==0)  /*子进程*/
    {
       printf("This is child process with pid of %d\n",getpid());
       sleep(10);       /*睡眠10秒钟*/
    }
    else   /*父进程*/
    {
        pr=wait(NULL);     /*在这里等待*/
        printf("I catched a child process with pid of %d\n",pr);
    }
    exit(0);
}
