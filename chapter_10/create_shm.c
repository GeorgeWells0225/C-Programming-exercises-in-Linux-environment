#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>
#define BUFSZ 4096
int main (void)
{
    int shm_id;    /*共享内存标识符*/
    shm_id = shmget (IPC_PRIVATE, BUFSZ, 0666 ) ;
    if (shm_id < 0 ) 
    {  
        printf("shmget failed!\n");
        exit (1);
    }
    printf ("creat a shared memory segment successfully: %d \n", shm_id);
    system( "ipcs -m");     /*调用ipcs命令查看IPC*/
    exit(0);
}
