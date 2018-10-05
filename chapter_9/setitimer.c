#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void ElsfTimer(int signo)      /*信号处理函数*/
{
   struct timeval tp;
   struct tm *tm;
   gettimeofday(&tp,NULL);   /* gettimeofday 函数获得系统当前时间（秒和微秒）*/
   tm=localtime(&tp.tv_sec);   /* localtime取得当地目前时间和日期*/
   printf(" sec = %ld \t",tp.tv_sec);    /*打印从UNIX纪元开始到现在的秒数*/
   printf(" usec = %ld \n",tp.tv_usec);  /*打印微秒*/
   printf("%d-%d-%d%d:%d:%d\n",tm->tm_year+1900,tm->tm_mon+1,tm->tm_mday,
          tm->tm_hour,tm->tm_min,tm->tm_sec);  /*打印当地目前时间和日期*/
}

static void InitTime(int tv_sec,int tv_usec)
{
   struct itimerval value;        /*定义时间参数结构体value */
   signal(SIGALRM, ElsfTimer); /*注册信号SIGALRM 和信号处理函数ElsfTimer ()*/
   value.it_value.tv_sec = tv_sec;   /*秒*/
   value.it_value.tv_usec = tv_usec; /*微秒*/
   value.it_interval.tv_sec = tv_sec; 
   value.it_interval.tv_usec = tv_usec; 
   setitimer(ITIMER_REAL, &value, NULL);
/*setitimer 发送信号，定时类型为ITIMER_REAL*/
}

int main(void)
{
   InitTime(5,0);      /*调用InitTime ()子函数，实参秒tv_sec 为5，微秒为0*/
   while(1)           /*死循环，程序一直执行*/
   {
   }
   exit(0);
}
