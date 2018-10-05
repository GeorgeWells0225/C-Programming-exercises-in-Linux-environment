#include <stdio.h>
#include <fcntl.h>
int main(void)
{
    FILE *fp;
    int fd;
    if( (fp = fopen("hello.txt", "r+")) == NULL)
    {   /*�Զ�д��ʽ��������û��hello.txt �ļ����򴴽��������ļ���ͷ��ʼ��д*/
        printf ("fail to open!\n");
        exit(1);          /*�����˳�*/
    }
    fprintf(fp, "Hello! I like Linux C program!\n"); 
        /*��������һ����Ϣ�������Ϣ�ᱣ�浽�򿪵��ļ���*/
    fclose(fp);               /*������ϣ��ر���*/
    if( (fd = open("hello.txt", O_RDWR)) == -1)
      {  /*�Զ�д�ķ�ʽ���ļ�--�����ļ��������ķ�ʽ*/
         printf ("fail to open!\n");
         exit(1);         /*�����˳�*/
      }
    if((fp = fdopen(fd, "a+")) == NULL)
      {  /*�ڴ򿪵��ļ��ϴ�һ�����������ļ�β��ʼ��д*/
         printf ("fail to open stream!\n");
         exit(1);         /*�����˳�*/
      }
    fprintf(fp, "I am doing Linux C programs!\n");
         /*��������һ����Ϣ�������Ϣ�ᱣ�浽�򿪵��ļ���*/
    fclose(fp);             /*�ر������ļ�Ҳ���ر�*/
    return 0;
}
