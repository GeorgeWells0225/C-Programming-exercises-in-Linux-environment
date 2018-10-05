#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define SIZE 30

int main(void)
{
    char newpath[SIZE];
    char buf[SIZE];
    printf("Input the new pathname[<30 strings]:");
    gets(newpath);
    if(chdir(newpath) == -1)     
    {
        printf("error,change directory failed!\n");
        exit(1);   /*³ö´íÍË³ö*/
    }
    printf("OK,change directory successful!\n");
    if(getcwd(buf,SIZE)==NULL)
    {
        printf("error,getcwd failed!\n");
        exit(1);
    }
    printf("cwd = %s\n",buf);
    return 0;
}
