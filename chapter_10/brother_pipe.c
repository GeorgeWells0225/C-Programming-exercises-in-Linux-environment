#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <limits.h>
#define BUFSIZE PIPE_BUF  /* PIPE_BUF���ܵ�Ĭ��һ���Զ�д�����ݳ���*/

void err_quit(char * msg)
{
    printf ( msg );
    exit(1);
}

int main(void)
{
    int fd[2];
    char buf[BUFSIZE] = "hello my brother!\n";        /* ������ */
    pid_t pid;
    int len;
    if ( (pipe(fd)) < 0 )           /*�����ܵ�*/
    {
        err_quit("pipe failed\n");
    }
    if ( (pid = fork()) < 0 )        /*������һ���ӽ���*/
    {
        err_quit("fork failed\n");
    }
    else if ( pid == 0 )            /*�ӽ�����*/
	{
        close ( fd[0] );                /*�رղ�ʹ�õ��ļ�������*/
        write(fd[1], buf, strlen(buf));    /*д����Ϣ*/
        exit(0);
    }
    if ( (pid = fork()) < 0 )             /*�����ڶ����ӽ���*/
    {
        err_quit("fork failed\n");
    }
    else if ( pid > 0 )             /*��������*/
	{
        close ( fd[0] );
        close ( fd[1] );
        exit ( 0 );
    }
    else                       /*�ڶ����ӽ�����*/
	{
        close ( fd[1] );                  /*�رղ�ʹ�õ��ļ�������*/
        len = read (fd[0], buf, BUFSIZE);  /*��ȡ��Ϣ*/
        write(STDOUT_FILENO, buf, len); /*����Ϣ�������׼���*/
        exit(0);
    }
    return 0;
}
