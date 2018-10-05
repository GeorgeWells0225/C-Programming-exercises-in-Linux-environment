#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <limits.h>
#define BUFSIZE PIPE_BUF  /* PIPE_BUF���ܵ�Ĭ��һ���Զ�д�����ݳ���*/

void err_quit(char *msg)
{
    printf (msg);
    exit(1);
}

int main(void)
{
    int fd[2];
    char buf[BUFSIZE] = "hello my child!\n";   /*д��ܵ��Ļ�����*/
    pid_t pid;
    int len;
    if ((pipe(fd)) < 0)   /*�����ܵ�*/
	{
        err_quit ("pipe failed\n");
    }
    if ((pid = fork()) < 0)  /*����һ���ӽ���*/
	{
        err_quit ("fork failed\n");
    }
    else if (pid > 0)
	{
        close ( fd[0] );                /*�������йرչܵ��Ķ�����*/
        write (fd[1], buf, strlen(buf));  /*��������ܵ�д������*/
        exit (0);
    }
    else
	{
        close ( fd[1] );                        /*�ӽ��̹رչܵ���д���*/
        len = read (fd[0], buf, BUFSIZE);     /*�ӽ��̴ӹܵ��ж�������*/
        if (len < 0)
		{
            err_quit ("process failed when read a pipe\n");
        }
        else
        {
            write(STDOUT_FILENO, buf, len);  /*�������׼���*/
        }
     exit(0);
    }
}
