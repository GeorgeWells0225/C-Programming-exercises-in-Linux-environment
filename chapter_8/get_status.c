#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    int status;
    pid_t pc,pr;
    if ((pc = fork()) < 0)
    {
        printf("error in fork!");
        exit(1);    /*fork出错退出*/
    }
    else if(pc==0)
	{  /*子进程*/
        printf("This is child process with pid of %d.\n",getpid());
        exit(3);  /*子进程返回3 */
    }
    else
	{   /*父进程*/
        pr=wait(&status);
        if(WIFEXITED(status))
		{   /*如果WIFEXITED返回非零值*/
            printf("the child process %d exit normally.\n",pr);
            printf("the return code is %d.\n",WEXITSTATUS(status));
        }
        else
		{   /*如果WIFEXITED返回零 */
            printf("the child process %d exit abnormally.\n",pr);
		}
    }
    return 0;
}
