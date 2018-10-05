#include <stdio.h> 
int main(void)
{
   int input = 0;
   printf("Input an integer:");
   scanf("%d",&input);                /*这里出现了错误*/
   printf("The integer you input is %d\n", input);
   return 0;
}
