#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main (void)
{
   int count = 1;
   int child;
   printf("Before create son, the father's count is:%d\n", count);  /*��������֮ǰ*/
   child = vfork();      /*��ʱ�Ѿ�������������ͬʱ����*/
   if(child < 0)
     {
        printf("error in vfork!");
        exit(1);    /* fork�����˳�*/
      }
   if(child==0)     /*�ӽ���*/
     {
        printf("This is son, his pid is: %d and the count is: %d\n", getpid(), ++count);
        exit(1);
     } 
   else            /*������*/
     {
        printf("After son, This is father, his pid is: %d and the count is: %d, and the child is: %d\n", getpid(), count, child); 
     }
   return 0;
}
