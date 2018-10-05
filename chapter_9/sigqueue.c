#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void SigHandler(int signo,siginfo_t *info,void *context)
{
    char *pMsg=(char*)info->si_value.sival_ptr;
    printf("Receive signal number:%d\n", signo);
    printf("Receive Message:%s\n", pMsg);
}
int main(void)
{
    struct sigaction sigAct;    /*��������źŴ������Ľṹ��*/
    sigAct.sa_flags=SA_SIGINFO;  /*�����źŴ�������sa_sigactionָ��*/
    sigAct.sa_sigaction=SigHandler;  /*ָ���źŴ�����*/
    if(sigaction(SIGUSR1,&sigAct,NULL)==-1)
    {
        printf("sigaction failed!\n");
        exit(1);
    }
    sigval_t val;       /*����sigqueue�����ĵ���������*/
    char pMsg[ ]="I like Linux C programs!";/*��Ҫ���ݵ���Ϣ����--һ���ַ�������*/
    val.sival_ptr = pMsg;
    if(sigqueue(getpid(),SIGUSR1,val) == -1)
             /*����sigqueue��������SIGUSR1�źţ���Я��һ��4�ֽڵ��������ݽṹ*/
    {
        printf("sigqueue failed!\n");
        exit(1);
    }
    sleep(3);
    return 0;
}
