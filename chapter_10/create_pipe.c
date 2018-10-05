#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int fd[2];              /* �ܵ����ļ����������� */
    char str[256];
    if((pipe(fd)) < 0)
	 {
        printf("create the pipe failed!\n");
        exit(1);    /*pipe�����˳�*/
     }
    write(fd[1], "create the pipe successfully!\n", 31 );   /*��ܵ�д���д������*/
    read(fd[0], str, sizeof(str) );   /*�ӹܵ������˶�������*/
    printf ("%s", str );
    printf ("pipe file descriptors are%d,%d \n", fd[0], fd[1]) ;
    close(fd[0]);              /* �رչܵ��Ķ������ļ�������*/
    close(fd[1]);              /* �رչܵ���д����ļ�������*/
    return 0;
}
