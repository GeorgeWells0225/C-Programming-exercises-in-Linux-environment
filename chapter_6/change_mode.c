#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#define FILENAME "/home/zhangfan/test"    /*Ҫ���в������ļ�*/
#define MODE 0755
 /*�������MODE ���ļ������߶���д��ִ�У������ִ�У���������ִ�з�ʽ*/

int main(void)
{
    const char *pathname = FILENAME;   /*ָ����Ҫ���в������ļ���·����*/
    if(chmod (pathname,MODE) == -1)     /*����chmod�����ı��ļ�Ȩ��*/
     {
        printf("error,change failed!\n");
        exit(1);   /*�����˳�*/
     }
    printf("OK,change successful!\n");
    return 0;
}
