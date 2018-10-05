#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <limits.h>
#define BUFSIZE PIPE_BUF  /* PIPE_BUF：管道默认一次性读写的数据长度*/

void err_quit(char * msg)
{
    printf ( msg );
    exit(1);
}

int main(void)
{
    int fd[2];
    char buf[BUFSIZE] = "hello my brother!\n";        /* 缓冲区 */
    pid_t pid;
    int len;
    if ( (pipe(fd)) < 0 )           /*创建管道*/
    {
        err_quit("pipe failed\n");
    }
    if ( (pid = fork()) < 0 )        /*创建第一个子进程*/
    {
        err_quit("fork failed\n");
    }
    else if ( pid == 0 )            /*子进程中*/
	{
        close ( fd[0] );                /*关闭不使用的文件描述符*/
        write(fd[1], buf, strlen(buf));    /*写入消息*/
        exit(0);
    }
    if ( (pid = fork()) < 0 )             /*创建第二个子进程*/
    {
        err_quit("fork failed\n");
    }
    else if ( pid > 0 )             /*父进程中*/
	{
        close ( fd[0] );
        close ( fd[1] );
        exit ( 0 );
    }
    else                       /*第二个子进程中*/
	{
        close ( fd[1] );                  /*关闭不使用的文件描述符*/
        len = read (fd[0], buf, BUFSIZE);  /*读取消息*/
        write(STDOUT_FILENO, buf, len); /*将消息输出到标准输出*/
        exit(0);
    }
    return 0;
}
