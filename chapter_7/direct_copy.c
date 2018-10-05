#include <stdio.h>
#define Src_File "/home/zhangfan/CODE/hello.txt"
#define Des_File "/home/zhangfan/CODE/test.txt"
int main(void)
{
    FILE *fp1, *fp2;    /*源文件和目标文件的文件指针*/
    char buf[1024];
    int n;
    if ((fp1 = fopen(Src_File, "rb")) == NULL)
    /*以只读方式打开源文件，读开始位置为文件开头*/
	{
         printf("fail to open source file\n");
         exit(1);      /*出错退出*/
    }
    if ((fp2 = fopen(Des_File, "wb")) == NULL)
    /*以只写方式打开目标文件，写开始位置为文件结尾*/
	{
         printf("fail to open des file\n");
         exit(1);       /*出错退出*/
    }
    /*开始复制文件，文件可能很大，缓冲一次装不下，所以使用一个循环进行读写*/
    while ((n = fread(buf, sizeof(char), 1024, fp1)) > 0)
	{  /*读源文件，直到将文件内容全部读完*/
        if (fwrite(buf, sizeof(char), n, fp2) == -1)
	    {  /*将读出的内容全部写到目标文件中去*/
            printf("fail to write\n");
            exit(1);    /*出错退出*/
        }
    }
    if(n == -1)
	{  /*如果因为读入字节小于0而跳出循环，则说明出错了*/
         printf("fail to read\n");
         exit(1);     /*出错退出*/
    }
    fclose(fp1);   /*操作完毕，关闭源文件和目标文件*/
    fclose(fp2);
    return 0;
}
