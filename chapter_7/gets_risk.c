#include <stdio.h>
int main(void)
{
    char buf[2048];       /*����һ���㹻��Ļ�����*/
    while (gets(buf) == buf)
    {  /*����Ļ����һ���ַ�������gets ����ֵ��Ϊ���������׵�ַʱ��ֹͣ����*/
       printf("%s\n", buf);  /*���ҽ����ַ�����ʾ�������Ļ��*/
    }
    return 0;
}
