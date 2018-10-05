#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
   pid_t pc, pr;
   if ( (pc = fork() )==-1 )
   {
       printf ("failed to create a new process\n");
       exit(0);
   } 
   else if(pc==0)  /*如果是子进程*/
   {
       sleep(10);          /*睡眠10秒钟*/
       exit(0);
   }
       /*如果是父进程*/
   do{
        pr=waitpid(pc, NULL, WNOHANG); /*使用了WNOHANG参数，waitpid不会在这里等待*/
        if(pr==0)
		{    /*如果没有收集到子进程 */
            printf("No child exited\n");
            sleep(1);
        }
      }while(pr==0);    /*没有收集到子进程，就继续尝试*/
    if(pr==pc)
    {
       printf("successfully get child %d\n", pr);
    }
    else
    {
       printf("some error occured\n");
    }
    return 0;
}
