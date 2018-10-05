#include <stdio.h>
int calculate(int x,int y);
int main(void)
{
    int num_1,num_2,result;
    while(1)            /*使用死循环，使程序可以一直接收终端的输入*/
    {
         printf("Enter two integers,or use 0 0 to exit:");
         scanf("%d %d",&num_1,&num_2);    /*输入两个整数*/
         if (num_1==0 && num_2==0)       /*两个整数均为0时退出*/
           exit(0); 
         result=calculate(num_1,num_2);       /*调用calculate函数进行计算 */
         printf("The result is:%d\n",result);     /*输出结果*/
     }
   return 0;
}
int calculate(int x,int y)
{  
   int res;
    res = x*x + y*y;
    return res;
}
