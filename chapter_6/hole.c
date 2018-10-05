#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define FILENAME "/home/zhangfan/test"    /*要进行操作的文件*/
#define FLAGS O_WRONLY | O_CREAT | O_TRUNC
/*定义参数flags：以读写方式打开文件，向文件添加内容时从文件尾开始写*/
#define MODE 0600

int main(void)
{
    char buf1[ ] = {"abcdefghij"};    /*缓冲区1，长度为10*/
    char buf2[ ] = {"1234567890"};  /*缓冲区2，长度为10*/
    int fd;                       /*文件描述符*/
    int count;
    const char *pathname = FILENAME;    /*指向需要进行操作的文件的路径名*/
    if((fd=open(pathname,FLAGS,MODE))==-1)   /*调用open函数打开文件*/
     {
        printf("error,open file failed!\n");
        exit(1);   /*出错退出*/
     }
    count = strlen(buf1);                /*缓冲区1的长度*/
    if(write(fd,buf1,count)!=count)       /*调用write函数将缓冲区1的数据写入文件*/
    {
       printf("error,write file failed!\n");
       exit(1);   /*写出错，退出*/
    }
    if(lseek(fd,50,SEEK_SET)==-1) 
    /*调用lseek函数定位文件，偏移量为50，从文件开头计算偏移值*/
    {
       printf("error,lseek failed!\n");
       exit(1);   /*出错退出*/
    }
    count = strlen(buf2);                /*缓冲区2的长度*/
    if(write(fd,buf2,count)!=count)       /*调用write函数将缓冲区2的数据写入文件*/
    {
       printf("error,write file failed!\n");
       exit(1);   /*写出错，退出*/
    }
    return 0;
}
