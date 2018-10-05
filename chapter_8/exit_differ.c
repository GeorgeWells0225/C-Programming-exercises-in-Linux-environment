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
    else if(pid==0)  /*�ӽ���*/
     {
        printf("child process, output begin\n");
        printf("child process, content in buffer");   /*û�л��з�'\n'*/
        exit(0);
     }
    else  /*������*/
     {
        printf("\nparent process, output begin\n");
        printf("parent process, content in buffer");  /*û�л��з�'\n'*/
        _exit(0);
     }
	return 0;
}
