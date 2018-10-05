#include <stdio.h>
#include <stdlib.h>
#define Src_File "/home/zhangfan/CODE/hello.txt"
#define Des_File "/home/zhangfan/CODE/test.txt"
int main(void)
{
    FILE *fp1, *fp2;  /*源文件和目标文件的文件指针*/
    int c;            /*要进行输入和输出的字符*/
    if ((fp1 = fopen(Src_File, "rb")) == NULL)   /*以只读方式打开源文件hello.txt */
	{
         printf("fail to open source file\n");
         exit(1);     /*出错退出*/
     }
    if ((fp2 = fopen(Des_File, "wb")) == NULL)    /*以只写方式打开目标文件test.txt*/
	{
         printf ("fail to open des file\n");
         exit(1);
     }
    /*开始复制文件，每次读写一个字符*/
    while((c = fgetc(fp1)) != EOF)
	{  /*读源文件，直到将文件内容全部读完*/
        if(fputc(c, fp2) == EOF)
        {   /*将读入的字符写到目标文件中去*/
               printf ("fail to write\n");
               exit(1);    /*出错退出*/
        }
        if(fputc(c, stdout) == EOF)
		{   /*将读入的字符输出到屏幕*/
               printf ("fail to write\n");
               exit(1);    /*出错退出*/
        }
    }
    fclose(fp1);   /*操作完毕，关闭源文件和目标文件*/
    fclose(fp2);
    return 0;
}
