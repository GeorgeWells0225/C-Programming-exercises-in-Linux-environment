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
   else if(pc==0)  /*������ӽ���*/
   {
       sleep(10);          /*˯��10����*/
       exit(0);
   }
       /*����Ǹ�����*/
   do{
        pr=waitpid(pc, NULL, WNOHANG); /*ʹ����WNOHANG������waitpid����������ȴ�*/
        if(pr==0)
		{    /*���û���ռ����ӽ��� */
            printf("No child exited\n");
            sleep(1);
        }
      }while(pr==0);    /*û���ռ����ӽ��̣��ͼ�������*/
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
