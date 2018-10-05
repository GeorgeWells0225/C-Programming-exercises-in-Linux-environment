#include <stdio.h>
int main(void)
{
    char buf[2048];       /*定义一个足够大的缓冲区*/
    while (gets(buf) == buf)
    {  /*从屏幕读入一行字符串，当gets 返回值不为缓冲区的首地址时则停止读入*/
       printf("%s\n", buf);  /*并且将该字符串显示输出到屏幕上*/
    }
    return 0;
}
