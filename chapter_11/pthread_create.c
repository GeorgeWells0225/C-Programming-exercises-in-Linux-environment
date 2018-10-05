#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
pthread_t ntid;  //线程号
//打印标识符的函数
void  printids(const char *s)
{
        pid_t		pid;   //进程标识符
	pthread_t	tid;   //线程标识符

	pid = getpid();     
	tid = pthread_self();  //分别获得进程和线程编号
	printf("%s pid %u tid %u (0x%x)\n", s, (unsigned int)pid,
	  (unsigned int)tid, (unsigned int)tid);
        //打印线程和进程编号
}
//线程中开始运行的函数
void *thr_fn(void *arg)
{
	printids("new thread: ");
	return((void *)0);
}
//主函数
int  main(void)
{
	int		err;
	err = pthread_create(&ntid, NULL, thr_fn, NULL); //创建一个线程
	if (err != 0)  //如果出错则打印错误标号
        {
		printf("can't create thread: %s\n", strerror(err));
	}
        printids("main thread:");  //打印主线程号
	sleep(1);
	exit(0);
}
