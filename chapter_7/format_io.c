#include <stdio.h>
#define File_path "/home/zhangfan/CODE/hello.txt"
int main(void)
{
    FILE *fp;      /*ָ������ļ����ļ�ָ��*/
    char buf[ ]="Hello! I like Linux C program!";
    char buf2[80];
    fp=fopen(File_path,"w");   /*��ֻд��ʽ���ļ�*/
    fprintf(fp, "%s", buf);    /*����ļ�������ַ�������buf*/
    fprintf(fp, "\n");         /*����ļ����������*/
    fclose(fp);                /*�ر��ļ���*/
    fp=fopen(File_path, "r");  /*����ֻ����ʽ���ļ�*/
    fscanf(fp,"%s",&buf2);     /*�����ļ����е����ݶ��뵽buf2*/
    fclose(fp);
    printf("%s\n",buf2);       /*��ӡbuf2������*/
    return 0;
}
