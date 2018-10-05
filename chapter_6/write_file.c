#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define FILENAME "/home/zhangfan/hello"    /*要进行写操作的文件*/
#define SIZE 80                         /*定义缓冲区大小*/
#define FLAGS O_RDWR | O_APPEND
/*定义参数flags：以读写方式打开文件，向文件添加内容时从文件尾开始写*/

int main(void)
{
   int count;
   int fd;                       /*文件描述符*/
   char write_buf[SIZE];          /*写缓冲区*/
   const char *pathname = FILENAME;    /*指向需要打开文件的路径名*/
   if((fd=open(pathname,FLAGS))==-1)   /*调用open函数打开文件*/
     {
        printf("error,open file failed!\n");
        exit(1);   /*出错退出*/
     }
   printf("OK,open file successful!\n");
   printf("Begin write:\n");
   gets(write_buf);
   count = strlen(write_buf);            /*要写入文件的数据的字节数*/
   if (write(fd, write_buf, count)==-1)
{
   printf("error,write file failed!\n");
   exit(1);   /*写出错，退出*/
}
 printf("OK,write %d strings to file!\n",count);
 return 0;
}
