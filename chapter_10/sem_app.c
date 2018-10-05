#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
#define SEM_PATH "/unix/my_sem"
#define max_tries 3 
int semid;
int main(void)
{
int flag1,flag2,key,i,init_ok,tmperrno;
struct semid_ds sem_info;
struct seminfo sem_info2;
union semun arg; 			/*定义union semun联合体*/
struct sembuf askfor_res, free_res;
flag1=IPC_CREAT|IPC_EXCL|00666; 
/*只执行创建信号量集的操作，00666为信号量集的访问权限*/
flag2=IPC_CREAT|00666; 
/*如果key为某个已存在的信号量集的键值，则执行打开这个键的操作*/
key=ftok(SEM_PATH,'a');
if(key == -1)
{
    perror("ftok error");
    exit(1);
}
init_ok=0;
semid=semget(key,1,flag1);   /*创建一个新的信号量集，其中只包含一个信号量*/
if(semid<0)
{
	    tmperrno=errno;
	    perror("semget");
if(tmperrno==EEXIST)   /*信号量集已存在，产生EEXIST错误，则使用flag2*/
	    {
		  semid=semget(key,1,flag2);
  /*flag2 只包含了IPC_CREAT标志, 参数nsems(这里为1)必须与原来的信号量数目一致*/
		  arg.buf=&sem_info; /*获得信号量的semid_ds结构，保存在arg.buf指向的缓冲区*/
		  for(i=0; i<max_tries; i++)
		  {
			if(semctl(semid, 0, IPC_STAT, arg)==-1)
/*0指定第一个信号量（该信号量集中唯一的一个信号量）*/
			{
perror("semctl error");
			   i=max_tries;
			}
			else
			{
			   if(arg.buf->sem_otime!=0)  
/*sem_otime：最后一次调用semop的时间，信号量集创建时该值为0*/
			   {
i=max_tries;
				  init_ok=1;
			   }
			   else
				 sleep(1);
			}
		}
		if(!init_ok)
     /*do some initializing, here we assume that the first process that creates the sem will*/
     /*finish initialize the sem and run semop in max_tries*1 seconds. else it will not run*/
     /*semop any more.*/
		{
		   arg.val=1;
		   if(semctl(semid,0,SETVAL,arg)==-1)/*指定信号量集semid中信号量0的值arg.val*/
			 perror("semctl setval error");
		} 
}
	 else
	 {
perror("semget error, process exit");
	   exit(1);
	 }
}
else  /*semid>=0; do some initializing*/
{
	   arg.val=1;
	   if(semctl(semid,0,SETVAL,arg)==-1)
		 perror("semctl setval error");
}
/*get some information about the semaphore and the limit of semaphore in RedHat 9.0*/
	 arg.buf=&sem_info;
	 if(semctl(semid, 0, IPC_STAT, arg)==-1)
		perror("semctl IPC STAT");		
	 printf("owner's uid is %d\n",arg.buf->sem_perm.uid);/*信号量集所有者的有效用户ID*/
	 printf("owner's gid is %d\n",arg.buf->sem_perm.gid);/*所有者的有效组ID*/
	 printf("creater's uid is %d\n",arg.buf->sem_perm.cuid);/*创建者的有效用户ID*/
	 printf("creater's gid is %d\n",arg.buf->sem_perm.cgid);/*创建者的有效组ID*/
	 arg.__buf=&sem_info2;
	 if(semctl(semid,0,IPC_INFO,arg)==-1)
		perror("semctl IPC_INFO");
	 printf("the number of entries in semaphore map is %d \n",arg.__buf->semmap);
	 printf("max number of semaphore identifiers is %d \n",arg.__buf->semmni);
	 printf("mas number of semaphores in system is %d \n",arg.__buf->semmns);
	 printf("the number of undo structures system wide is %d \n",arg.__buf->semmnu);
	 printf("max number of semaphores per semid is %d \n",arg.__buf->semmsl);
	 printf("max number of ops per semop call is %d \n",arg.__buf->semopm);
	 printf("max number of undo entries per process is %d \n",arg.__buf->semume);
	 printf("the sizeof of struct sem_undo is %d \n",arg.__buf->semusz);
	 printf("the maximum semaphore value is %d \n",arg.__buf->semvmx);
	 
/*now ask for available resource:*/
	 askfor_res.sem_num=0;
	 askfor_res.sem_op=-1;
	 askfor_res.sem_flg=SEM_UNDO;
	 if(semop(semid,&askfor_res,1)==-1) /*ask for resource*/
		perror("semop error");
	 sleep(3); /*do some handling on the sharing resource here, just sleep on it 3 seconds*/
	 printf("now free the resource\n");
	 
/*now free resource*/
	 free_res.sem_num=0;
	 free_res.sem_op=1;
	 free_res.sem_flg=SEM_UNDO;
	 if(semop(semid,&free_res,1)==-1) /*free the resource.*/
		if(errno==EIDRM)
			printf("the semaphore set was removed\n");
/*you can comment out the codes below to compile a different version:*/
	 if(semctl(semid, 0, IPC_RMID)==-1)
		perror("semctl IPC_RMID");
	 else
printf("remove sem ok\n");
return 0;
}
