#include <sys/types.h>
//#include <unistd.h>
#include <stdio.h>
int main(void)
{
   //if (lseek (STDIN_FILENO,0,SEEK_CUR) == -1) /*判断标准输入文件能否被设置位移量*/
   if (lseek (0, 0, SEEK_CUR) == -1) /*判断标准输入文件能否被设置位移量*/
      printf("cannot seek!\n");
   else
      printf("seek OK!\n");
   exit(0);
}
