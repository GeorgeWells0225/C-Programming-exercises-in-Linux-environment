#include <stdio.h>
int calculate(int x,int y);
int main(void)
{
    int num_1,num_2,result;
    while(1)            /*ʹ����ѭ����ʹ�������һֱ�����ն˵�����*/
    {
         printf("Enter two integers,or use 0 0 to exit:");
         scanf("%d %d",&num_1,&num_2);    /*������������*/
         if (num_1==0 && num_2==0)       /*����������Ϊ0ʱ�˳�*/
           exit(0); 
         result=calculate(num_1,num_2);       /*����calculate�������м��� */
         printf("The result is:%d\n",result);     /*������*/
     }
   return 0;
}
int calculate(int x,int y)
{  
   int res;
    res = x*x + y*y;
    return res;
}