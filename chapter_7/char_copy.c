#include <stdio.h>
#include <stdlib.h>
#define Src_File "/home/zhangfan/CODE/hello.txt"
#define Des_File "/home/zhangfan/CODE/test.txt"
int main(void)
{
    FILE *fp1, *fp2;  /*Դ�ļ���Ŀ���ļ����ļ�ָ��*/
    int c;            /*Ҫ���������������ַ�*/
    if ((fp1 = fopen(Src_File, "rb")) == NULL)   /*��ֻ����ʽ��Դ�ļ�hello.txt */
	{
         printf("fail to open source file\n");
         exit(1);     /*�����˳�*/
     }
    if ((fp2 = fopen(Des_File, "wb")) == NULL)    /*��ֻд��ʽ��Ŀ���ļ�test.txt*/
	{
         printf ("fail to open des file\n");
         exit(1);
     }
    /*��ʼ�����ļ���ÿ�ζ�дһ���ַ�*/
    while((c = fgetc(fp1)) != EOF)
	{  /*��Դ�ļ���ֱ�����ļ�����ȫ������*/
        if(fputc(c, fp2) == EOF)
        {   /*��������ַ�д��Ŀ���ļ���ȥ*/
               printf ("fail to write\n");
               exit(1);    /*�����˳�*/
        }
        if(fputc(c, stdout) == EOF)
		{   /*��������ַ��������Ļ*/
               printf ("fail to write\n");
               exit(1);    /*�����˳�*/
        }
    }
    fclose(fp1);   /*������ϣ��ر�Դ�ļ���Ŀ���ļ�*/
    fclose(fp2);
    return 0;
}
