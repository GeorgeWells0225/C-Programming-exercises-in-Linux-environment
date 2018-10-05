#include <stdio.h>
#define Src_File "/home/zhangfan/CODE/hello.txt"
#define Des_File "/home/zhangfan/CODE/test.txt"
int main(void)
{
    FILE *fp1, *fp2;    /*Դ�ļ���Ŀ���ļ����ļ�ָ��*/
    char buf[1024];
    int n;
    if ((fp1 = fopen(Src_File, "rb")) == NULL)
    /*��ֻ����ʽ��Դ�ļ�������ʼλ��Ϊ�ļ���ͷ*/
	{
         printf("fail to open source file\n");
         exit(1);      /*�����˳�*/
    }
    if ((fp2 = fopen(Des_File, "wb")) == NULL)
    /*��ֻд��ʽ��Ŀ���ļ���д��ʼλ��Ϊ�ļ���β*/
	{
         printf("fail to open des file\n");
         exit(1);       /*�����˳�*/
    }
    /*��ʼ�����ļ����ļ����ܴܺ󣬻���һ��װ���£�����ʹ��һ��ѭ�����ж�д*/
    while ((n = fread(buf, sizeof(char), 1024, fp1)) > 0)
	{  /*��Դ�ļ���ֱ�����ļ�����ȫ������*/
        if (fwrite(buf, sizeof(char), n, fp2) == -1)
	    {  /*������������ȫ��д��Ŀ���ļ���ȥ*/
            printf("fail to write\n");
            exit(1);    /*�����˳�*/
        }
    }
    if(n == -1)
	{  /*�����Ϊ�����ֽ�С��0������ѭ������˵��������*/
         printf("fail to read\n");
         exit(1);     /*�����˳�*/
    }
    fclose(fp1);   /*������ϣ��ر�Դ�ļ���Ŀ���ļ�*/
    fclose(fp2);
    return 0;
}
