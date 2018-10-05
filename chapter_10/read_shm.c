#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
typedef struct{
	char name[4];
	int age;
} people;

int main(int argc, char** argv)
{
	int shm_id,i;
	people *p_map;
	if ( argc != 2 )
	 { /* 命令行参数错误 */
        printf ( "USAGE: atshm <identifier>" );   /*打印帮助消息*/
        exit (1 );
    }
    shm_id = atoi(argv[1]);                        /*得到要引入的共享内存段*/
	p_map = (people*)shmat(shm_id,NULL,0);
	for(i = 0;i<10;i++)
	{
	printf( "name:%s   ",(*(p_map+i)).name );
	printf( "age %d\n",(*(p_map+i)).age );
	}
	if(shmdt(p_map) == -1)
		perror(" detach error ");
	return 0;
}


