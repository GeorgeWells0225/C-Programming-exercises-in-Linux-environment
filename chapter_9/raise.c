#include <sys/types.h>
#include <signal.h>
int main(void)
{
   printf("Hello, I like Linux C programs!\n");
   if(raise(SIGABRT) == -1)    /*����̱�����SIGABRT�ź�*/
   {
	   printf("raise failed!\n");   /*����ʧ�ܣ��˳�*/
       exit(1);
   }
   printf("Hello, I like Linux C programs,again!\n");   /*���̷������������˾䲻��ִ��*/
   return 0;
}
