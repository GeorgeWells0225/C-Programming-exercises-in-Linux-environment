#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define FILENAME "/home/zhangfan/hello"    /*Ҫ����д�������ļ�*/
#define SIZE 80                         /*���建������С*/
#define FLAGS O_RDWR | O_APPEND
/*�������flags���Զ�д��ʽ���ļ������ļ��������ʱ���ļ�β��ʼд*/

int main(void)
{
   int count;
   int fd;                       /*�ļ�������*/
   char write_buf[SIZE];          /*д������*/
   const char *pathname = FILENAME;    /*ָ����Ҫ���ļ���·����*/
   if((fd=open(pathname,FLAGS))==-1)   /*����open�������ļ�*/
     {
        printf("error,open file failed!\n");
        exit(1);   /*�����˳�*/
     }
   printf("OK,open file successful!\n");
   printf("Begin write:\n");
   gets(write_buf);
   count = strlen(write_buf);            /*Ҫд���ļ������ݵ��ֽ���*/
   if (write(fd, write_buf, count)==-1)
{
   printf("error,write file failed!\n");
   exit(1);   /*д�����˳�*/
}
 printf("OK,write %d strings to file!\n",count);
 return 0;
}
