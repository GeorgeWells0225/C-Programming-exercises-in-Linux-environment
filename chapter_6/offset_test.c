#include <sys/types.h>
//#include <unistd.h>
#include <stdio.h>
int main(void)
{
   //if (lseek (STDIN_FILENO,0,SEEK_CUR) == -1) /*�жϱ�׼�����ļ��ܷ�����λ����*/
   if (lseek (0, 0, SEEK_CUR) == -1) /*�жϱ�׼�����ļ��ܷ�����λ����*/
      printf("cannot seek!\n");
   else
      printf("seek OK!\n");
   exit(0);
}
