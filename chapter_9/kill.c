#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
int main(void)
{
   pid_t pid;
   int status;
   if(!(pid= fork()))
   {
      printf("Hi I am child process!\n");
      sleep(10);        /*让子进程睡眠，看父进程的行为*/
      printf("Hi I am child process, again!\n");
      return;
   }
   else
   {
      printf("send signal to child process (%d) \n",pid);
      sleep(1);
      if(kill(pid ,SIGABRT) == -1)
	  {
          printf("kill failed!\n");
	  }
      wait(&status);
      if(WIFSIGNALED(status))
	  {
          printf("child process receive signal %d\n",WTERMSIG(status));
       }
   }
   return 0;
}
