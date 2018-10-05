#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <limits.h>
#define BUFSIZE PIPE_BUF  /* PIPE_BUF：管道默认一次性读写的数据长度*/

void err_quit(char *msg)
{
    printf (msg);
    exit(1);
}

int main(void)
{
    int fd[2];
    char buf[BUFSIZE] = "hello my child!\n";   /*写入管道的缓冲区*/
    pid_t pid;
    int len;
    if ((pipe(fd)) < 0)   /*创建管道*/
	{
        err_quit ("pipe failed\n");
    }
    if ((pid = fork()) < 0)  /*创建一个子进程*/
	{
        err_quit ("fork failed\n");
    }
    else if (pid > 0)
	{
        close ( fd[0] );                /*父进程中关闭管道的读出端*/
        write (fd[1], buf, strlen(buf));  /*父进程向管道写入数据*/
        exit (0);
    }
    else
	{
        close ( fd[1] );                        /*子进程关闭管道的写入端*/
        len = read (fd[0], buf, BUFSIZE);     /*子进程从管道中读出数据*/
        if (len < 0)
		{
            err_quit ("process failed when read a pipe\n");
        }
        else
        {
            write(STDOUT_FILENO, buf, len);  /*输出到标准输出*/
        }
     exit(0);
    }
}
