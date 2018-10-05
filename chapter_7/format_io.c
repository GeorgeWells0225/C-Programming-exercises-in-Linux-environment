#include <stdio.h>
#define File_path "/home/zhangfan/CODE/hello.txt"
int main(void)
{
    FILE *fp;      /*指向操作文件的文件指针*/
    char buf[ ]="Hello! I like Linux C program!";
    char buf2[80];
    fp=fopen(File_path,"w");   /*以只写方式打开文件*/
    fprintf(fp, "%s", buf);    /*向该文件流输出字符串数据buf*/
    fprintf(fp, "\n");         /*向该文件流输出换行*/
    fclose(fp);                /*关闭文件流*/
    fp=fopen(File_path, "r");  /*再以只读方式打开文件*/
    fscanf(fp,"%s",&buf2);     /*将该文件流中的数据读入到buf2*/
    fclose(fp);
    printf("%s\n",buf2);       /*打印buf2的内容*/
    return 0;
}
