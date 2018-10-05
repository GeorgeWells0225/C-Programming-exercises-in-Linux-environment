#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#define FLAGS O_WRONLY | O_CREAT | O_TRUNC
/*定义flags：只写，文件不存在则创建，文件长度截短为0*/
#define MODE S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH 
/*创建文件的权限：用户读写、执行，组读、执行，其他用户读、执行*/

int main(void)
{
   const char *pathname;     /*指向需要打开（或创建）文件的绝对路径名或相对路径名*/
   int fd;                  /*文件描述符*/
   char pn[30];             /*pn为字符串数组，存放要打开（或创建）的文件名*/
   printf("Input the pathname[<30 strings]:");    /*输入路径名，小于30个字符*/
   gets(pn);
   pathname = pn;
   if((fd=open(pathname,FLAGS,MODE))==-1)  /*调用open函数*/
     {
        printf("error,open file failed!\n");
        exit(1);   /*出错退出*/
     }
   printf("OK,open file successful!\n");
   printf("fd=%d\n",fd);
   return 0;
}

