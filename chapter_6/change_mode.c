#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#define FILENAME "/home/zhangfan/test"    /*要进行操作的文件*/
#define MODE 0755
 /*定义参数MODE ：文件所有者读、写、执行；组读、执行；其他读、执行方式*/

int main(void)
{
    const char *pathname = FILENAME;   /*指向需要进行操作的文件的路径名*/
    if(chmod (pathname,MODE) == -1)     /*调用chmod函数改变文件权限*/
     {
        printf("error,change failed!\n");
        exit(1);   /*出错退出*/
     }
    printf("OK,change successful!\n");
    return 0;
}
