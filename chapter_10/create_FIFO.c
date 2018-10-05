#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[ ])
{
    mode_t mode = 0666;    /*�´�����FIFOģʽ*/
    if(argc != 2)
	{
        printf("USEMSG: create_FIFO { FIFO name}\n"); /*���û���ʾ����ʹ�ð���*/
        exit(1);
    }
    if((mkfifo(argv[1], mode)) < 0)  /* ʹ��mkfifo��������һ��FIFO�ܵ�*/
	{
        perror("failed to mkfifo!\n");
        exit(1);
    }
    else
	{  /*���FIFO�ļ�������*/
        printf("you successfully create a FIFO name is : %s\n", argv[1]); 
	}
    return 0;
}
