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
    struct sigaction sigAct;    /*定义包含信号处理动作的结构体*/
    sigAct.sa_flags=SA_SIGINFO;  /*表明信号处理函数由sa_sigaction指定*/
    sigAct.sa_sigaction=SigHandler;  /*指定信号处理函数*/
    if(sigaction(SIGUSR1,&sigAct,NULL)==-1)
    {
        printf("sigaction failed!\n");
        exit(1);
    }
    sigval_t val;       /*定义sigqueue函数的第三个参数*/
    char pMsg[ ]="I like Linux C programs!";/*将要传递的信息参数--一个字符串数据*/
    val.sival_ptr = pMsg;
    if(sigqueue(getpid(),SIGUSR1,val) == -1)
             /*调用sigqueue向自身发生SIGUSR1信号，并携带一个4字节的联合数据结构*/
    {
        printf("sigqueue failed!\n");
        exit(1);
    }
    sleep(3);
    return 0;
}
