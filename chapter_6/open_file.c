#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#define FLAGS O_WRONLY | O_CREAT | O_TRUNC
/*����flags��ֻд���ļ��������򴴽����ļ����Ƚض�Ϊ0*/
#define MODE S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH 
/*�����ļ���Ȩ�ޣ��û���д��ִ�У������ִ�У������û�����ִ��*/

int main(void)
{
   const char *pathname;     /*ָ����Ҫ�򿪣��򴴽����ļ��ľ���·���������·����*/
   int fd;                  /*�ļ�������*/
   char pn[30];             /*pnΪ�ַ������飬���Ҫ�򿪣��򴴽������ļ���*/
   printf("Input the pathname[<30 strings]:");    /*����·������С��30���ַ�*/
   gets(pn);
   pathname = pn;
   if((fd=open(pathname,FLAGS,MODE))==-1)  /*����open����*/
     {
        printf("error,open file failed!\n");
        exit(1);   /*�����˳�*/
     }
   printf("OK,open file successful!\n");
   printf("fd=%d\n",fd);
   return 0;
}

