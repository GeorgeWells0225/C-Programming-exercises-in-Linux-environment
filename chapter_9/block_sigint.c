#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

int g_iSeq=0;

void SignHandlerNew(int iSignNo,siginfo_t *pInfo,void *pReserved)  /*信号处理函数*/
{
    int iSeq=g_iSeq++; 
    printf("%d Enter SignHandlerNew,signo:%d.\n",iSeq,iSignNo); 
    sleep(3);      /*睡眠3秒钟*/
    printf("%d Leave SignHandlerNew,signo:%d\n",iSeq,iSignNo); 
}

int main(void)
{
    char szBuf[20];    /*输入缓冲区，长度为20*/
    int iRet;
    struct sigaction act;   /*包含信号处理动作的结构体*/
    act.sa_sigaction=SignHandlerNew;   /*指定信号处理函数*/
    act.sa_flags=SA_SIGINFO;   /*表明信号处理函数由sa_sigaction指定*/
    /*屏蔽掉SIGINT信号，SigHandlerNew 将不能再捕捉SIGINT*/
    sigset_t sigSet; 
    sigemptyset(&sigSet); 
    sigaddset(&sigSet,SIGINT); 
    sigprocmask(SIG_BLOCK,&sigSet,NULL); 
    sigemptyset(&act.sa_mask); 
    sigaction(SIGINT,&act,NULL);   /*注册SIGINT信号*/
    sigaction(SIGQUIT,&act,NULL);  /*注册SIGQUIT信号*/
    do{ 
        iRet=read(STDIN_FILENO,szBuf,sizeof(szBuf)-1);  /*从标准输入读入数据*/
        if(iRet<0){ 
            perror("read fail."); 
            break;   /* read出错退出*/
        } 
        szBuf[iRet]=0; 
        printf("Get: %s",szBuf);       /*打印终端输入的字符串*/
    }while(strcmp(szBuf,"quit\n")!=0);  /*输入"quit"时退出程序*/
    return 0;
}
