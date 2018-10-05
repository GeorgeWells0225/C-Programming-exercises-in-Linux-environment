#include <stdio.h>
#define SIZE 1024                   /*�������Ĵ�С*/
int main(void)
{
   char buf[SIZE];                   /*������*/
   if(setvbuf(stdin, buf, _IONBF, SIZE)!=0)   /*����׼����Ļ���������Ϊ�޻���*/
     {
       printf("error!\n");
       exit(1);                     /*�����˳�*/
     }
   printf("OK, set successful!\n");
   printf("stdin is ");                  /*��ӡ��������Ϣ*/
   if(stdin->_flags & _IO_UNBUFFERED) /*�жϱ�׼����������Ļ���������*/
      printf("unbuffered\n");
   else if(stdin->_flags & _IO_LINE_BUF)
      printf("line-buffered\n");
   else
      printf("fully-buffered\n");
   printf("buffer size is %d\n", stdin->_IO_buf_end - stdin->_IO_buf_base); 
       /*��ӡ�������Ĵ�С*/
   printf("file discriptor is %d\n", fileno(stdin));  /*����ļ�������*/
   if(setvbuf(stdin, buf, _IOFBF, SIZE)!=0)     
     { /*����׼����Ļ���������Ϊȫ���壬�����СΪ1024*/
       printf("error!\n");
       exit(1);     /*�����˳�*/
     }
   printf("OK, change successful!\n");
   printf("stdin is ");                    /*��ӡ��������Ϣ*/
   if(stdin->_flags & _IO_UNBUFFERED)  /*�жϱ�׼����������Ļ���������*/
      printf("unbuffered\n");
   else if(stdin->_flags & _IO_LINE_BUF)
      printf("line-buffered\n");
   else
      printf("fully-buffered\n");
   printf("buffer size is %d\n", stdin->_IO_buf_end - stdin->_IO_buf_base); 
      /*��ӡ�������Ĵ�С*/
   printf("file discriptor is %d\n", fileno(stdin));  /*����ļ������� */
}
