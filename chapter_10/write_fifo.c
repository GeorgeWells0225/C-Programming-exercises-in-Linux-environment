#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#define BUFES PIPE_BUF
int main(void)
{
    int fd ;
    int n, i ;
    char buf[BUFES];
    time_t tp;
    printf("I am %d\n",getpid());       /*˵�����̵�ID*/
    if((fd=open("fifo1",O_WRONLY))<0)  /*��ֻд��ʽ��һ��FIFO���ܵ���Ϊfifo1*/
	{
        printf("Open failed!\n");
        exit(1);
    }
    for ( i=0 ; i<10; i++)    /*ѭ��10����FIFO��д������*/
	{
        time(&tp);        /*ȡϵͳ��ǰʱ��*/
        n=sprintf(buf,"write_fifo %d sends %s",getpid(),ctime(&tp));
                       /*ʹ��sprintf ������buf�и�ʽ��д�����ID ��ʱ��ֵ*/
        printf("Send msg:%s\n",buf);
        if((write(fd, buf, n+1))<0)
		{   /*д�뵽FIFO��*/
            printf ("Write failed!\n");
            close(fd);                  /*�ر�FIFO�ļ�*/
            exit(1);
        }
        sleep(3);                      /*����˯��3�룬���ڹ۲�*/
    }
    close(fd);                          /*�ر�FIFO�ļ�*/
    exit(0);
}
