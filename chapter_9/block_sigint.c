#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

int g_iSeq=0;

void SignHandlerNew(int iSignNo,siginfo_t *pInfo,void *pReserved)  /*�źŴ�����*/
{
    int iSeq=g_iSeq++; 
    printf("%d Enter SignHandlerNew,signo:%d.\n",iSeq,iSignNo); 
    sleep(3);      /*˯��3����*/
    printf("%d Leave SignHandlerNew,signo:%d\n",iSeq,iSignNo); 
}

int main(void)
{
    char szBuf[20];    /*���뻺����������Ϊ20*/
    int iRet;
    struct sigaction act;   /*�����źŴ������Ľṹ��*/
    act.sa_sigaction=SignHandlerNew;   /*ָ���źŴ�����*/
    act.sa_flags=SA_SIGINFO;   /*�����źŴ�������sa_sigactionָ��*/
    /*���ε�SIGINT�źţ�SigHandlerNew �������ٲ�׽SIGINT*/
    sigset_t sigSet; 
    sigemptyset(&sigSet); 
    sigaddset(&sigSet,SIGINT); 
    sigprocmask(SIG_BLOCK,&sigSet,NULL); 
    sigemptyset(&act.sa_mask); 
    sigaction(SIGINT,&act,NULL);   /*ע��SIGINT�ź�*/
    sigaction(SIGQUIT,&act,NULL);  /*ע��SIGQUIT�ź�*/
    do{ 
        iRet=read(STDIN_FILENO,szBuf,sizeof(szBuf)-1);  /*�ӱ�׼�����������*/
        if(iRet<0){ 
            perror("read fail."); 
            break;   /* read�����˳�*/
        } 
        szBuf[iRet]=0; 
        printf("Get: %s",szBuf);       /*��ӡ�ն�������ַ���*/
    }while(strcmp(szBuf,"quit\n")!=0);  /*����"quit"ʱ�˳�����*/
    return 0;
}
