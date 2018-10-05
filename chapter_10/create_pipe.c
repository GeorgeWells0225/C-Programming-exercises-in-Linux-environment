#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int fd[2];              /* 管道的文件描述符数组 */
    char str[256];
    if((pipe(fd)) < 0)
	 {
        printf("create the pipe failed!\n");
        exit(1);    /*pipe出错退出*/
     }
    write(fd[1], "create the pipe successfully!\n", 31 );   /*向管道写入端写入数据*/
    read(fd[0], str, sizeof(str) );   /*从管道读出端读出数据*/
    printf ("%s", str );
    printf ("pipe file descriptors are%d,%d \n", fd[0], fd[1]) ;
    close(fd[0]);              /* 关闭管道的读出端文件描述符*/
    close(fd[1]);              /* 关闭管道的写入端文件描述符*/
    return 0;
}
