#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void print_msg(char *ptr);
//主函数
int main()
{
  pthread_t thread1, thread2;
  int i,j;
  void *retval;
  char *msg1="This is the frist thread\n";
  char *msg2="This is the second thread\n";  //存放两个字符串
  pthread_create(&thread1,NULL, (void *)(&print_msg), (void *)msg1);
  pthread_create(&thread2,NULL, (void *)(&print_msg), (void *)msg2); //创建两个线程
  pthread_join(thread1,&retval);
  pthread_join(thread2,&retval);
  return 0;
}
//打印信息函数，线程从这个函数开始运行
void  print_msg(char *ptr)
{
  int i;
  for(i=0;i<10;i++)
  printf("%s\n",ptr);  //连续输出10个字符串
}
