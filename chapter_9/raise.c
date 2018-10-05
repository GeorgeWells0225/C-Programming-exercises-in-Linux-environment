#include <sys/types.h>
#include <signal.h>
int main(void)
{
   printf("Hello, I like Linux C programs!\n");
   if(raise(SIGABRT) == -1)    /*向进程本身发送SIGABRT信号*/
   {
	   printf("raise failed!\n");   /*发送失败，退出*/
       exit(1);
   }
   printf("Hello, I like Linux C programs,again!\n");   /*进程非正常结束，此句不会执行*/
   return 0;
}
