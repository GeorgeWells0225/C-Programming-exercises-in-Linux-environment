#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void ElsfTimer(int signo)      /*�źŴ�����*/
{
   struct timeval tp;
   struct tm *tm;
   gettimeofday(&tp,NULL);   /* gettimeofday �������ϵͳ��ǰʱ�䣨���΢�룩*/
   tm=localtime(&tp.tv_sec);   /* localtimeȡ�õ���Ŀǰʱ�������*/
   printf(" sec = %ld \t",tp.tv_sec);    /*��ӡ��UNIX��Ԫ��ʼ�����ڵ�����*/
   printf(" usec = %ld \n",tp.tv_usec);  /*��ӡ΢��*/
   printf("%d-%d-%d%d:%d:%d\n",tm->tm_year+1900,tm->tm_mon+1,tm->tm_mday,
          tm->tm_hour,tm->tm_min,tm->tm_sec);  /*��ӡ����Ŀǰʱ�������*/
}

static void InitTime(int tv_sec,int tv_usec)
{
   struct itimerval value;        /*����ʱ������ṹ��value */
   signal(SIGALRM, ElsfTimer); /*ע���ź�SIGALRM ���źŴ�����ElsfTimer ()*/
   value.it_value.tv_sec = tv_sec;   /*��*/
   value.it_value.tv_usec = tv_usec; /*΢��*/
   value.it_interval.tv_sec = tv_sec; 
   value.it_interval.tv_usec = tv_usec; 
   setitimer(ITIMER_REAL, &value, NULL);
/*setitimer �����źţ���ʱ����ΪITIMER_REAL*/
}

int main(void)
{
   InitTime(5,0);      /*����InitTime ()�Ӻ�����ʵ����tv_sec Ϊ5��΢��Ϊ0*/
   while(1)           /*��ѭ��������һֱִ��*/
   {
   }
   exit(0);
}
