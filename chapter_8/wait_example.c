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
       exit(1);    /* fork�����˳�*/
    }
    else if(pc==0)  /*�ӽ���*/
    {
       printf("This is child process with pid of %d\n",getpid());
       sleep(10);       /*˯��10����*/
    }
    else   /*������*/
    {
        pr=wait(NULL);     /*������ȴ�*/
        printf("I catched a child process with pid of %d\n",pr);
    }
    exit(0);
}
