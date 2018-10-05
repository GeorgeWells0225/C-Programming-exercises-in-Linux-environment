#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> 
int main(void)
{
    pid_t pid;  
    if ( (pid = fork() )==-1 )
     {
        printf ("failed to create a new process\n");
        exit(0);
     }
    else if(pid==0)  /*子进程*/
     {
        printf("child process, output begin\n");
        printf("child process, content in buffer");   /*没有换行符'\n'*/
        exit(0);
     }
    else  /*父进程*/
     {
        printf("\nparent process, output begin\n");
        printf("parent process, content in buffer");  /*没有换行符'\n'*/
        _exit(0);
     }
	return 0;
}
