#include <stdio.h>
#define SIZE 1024                   /*缓冲区的大小*/
int main(void)
{
   char buf[SIZE];                   /*缓冲区*/
   if(setvbuf(stdin, buf, _IONBF, SIZE)!=0)   /*将标准输入的缓冲类型设为无缓冲*/
     {
       printf("error!\n");
       exit(1);                     /*出错退出*/
     }
   printf("OK, set successful!\n");
   printf("stdin is ");                  /*打印缓冲区信息*/
   if(stdin->_flags & _IO_UNBUFFERED) /*判断标准输入流对象的缓冲区类型*/
      printf("unbuffered\n");
   else if(stdin->_flags & _IO_LINE_BUF)
      printf("line-buffered\n");
   else
      printf("fully-buffered\n");
   printf("buffer size is %d\n", stdin->_IO_buf_end - stdin->_IO_buf_base); 
       /*打印缓冲区的大小*/
   printf("file discriptor is %d\n", fileno(stdin));  /*输出文件描述符*/
   if(setvbuf(stdin, buf, _IOFBF, SIZE)!=0)     
     { /*将标准输入的缓冲类型设为全缓冲，缓存大小为1024*/
       printf("error!\n");
       exit(1);     /*出错退出*/
     }
   printf("OK, change successful!\n");
   printf("stdin is ");                    /*打印缓冲区信息*/
   if(stdin->_flags & _IO_UNBUFFERED)  /*判断标准输入流对象的缓冲区类型*/
      printf("unbuffered\n");
   else if(stdin->_flags & _IO_LINE_BUF)
      printf("line-buffered\n");
   else
      printf("fully-buffered\n");
   printf("buffer size is %d\n", stdin->_IO_buf_end - stdin->_IO_buf_base); 
      /*打印缓冲区的大小*/
   printf("file discriptor is %d\n", fileno(stdin));  /*输出文件描述符 */
}
