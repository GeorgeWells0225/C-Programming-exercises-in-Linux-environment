#include <stdio.h>
#include <fcntl.h>
int main(void)
{
    FILE *fp;
    int fd;
    if( (fp = fopen("hello.txt", "r+")) == NULL)
    {   /*以读写方式打开流，若没有hello.txt 文件，则创建它，从文件开头开始读写*/
        printf ("fail to open!\n");
        exit(1);          /*出错退出*/
    }
    fprintf(fp, "Hello! I like Linux C program!\n"); 
        /*向该流输出一段信息，这段信息会保存到打开的文件上*/
    fclose(fp);               /*操作完毕，关闭流*/
    if( (fd = open("hello.txt", O_RDWR)) == -1)
      {  /*以读写的方式打开文件--基于文件描述符的方式*/
         printf ("fail to open!\n");
         exit(1);         /*出错退出*/
      }
    if((fp = fdopen(fd, "a+")) == NULL)
      {  /*在打开的文件上打开一个流，并从文件尾开始读写*/
         printf ("fail to open stream!\n");
         exit(1);         /*出错退出*/
      }
    fprintf(fp, "I am doing Linux C programs!\n");
         /*向该流输出一段信息，这段信息会保存到打开的文件上*/
    fclose(fp);             /*关闭流，文件也被关闭*/
    return 0;
}
