#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
//清理函数，用于输出相应的参数
void *clean(void *arg)
{
    printf("cleanup :%s  \n",(char *)arg);
    return (void *)0;
}
//线程1的启动函数
void *thr_fn1(void *arg)
{
    printf("thread 1 start  \n");
    //格式化清理参数
    pthread_cleanup_push( (void*)clean,"thread 1 first handler");
    pthread_cleanup_push( (void*)clean,"thread 1 second hadler");
    printf("thread 1 push complete  \n");
    if(arg) //如果arg不为0，返回
    {
        return((void *)1);
    }
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);//调用清理函数
    return (void *)1;
}
//线程2的启动函数，参考fn1
void *thr_fn2(void *arg)
{
    printf("thread 2 start  \n");
    pthread_cleanup_push( (void*)clean,"thread 2 first handler");
    pthread_cleanup_push( (void*)clean,"thread 2 second handler");
    printf("thread 2 push complete  \n");
    if(arg)
    {
        pthread_exit((void *)2);
    }
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    pthread_exit((void *)2);
}
//主函数
int main(void)
{
    int err;
    pthread_t tid1,tid2;  //线程标识符
    void *tret;
    //创建线程1
    err=pthread_create(&tid1,NULL,thr_fn1,(void *)1);
    if(err!=0)  //如果创建出错
    {
        perror("create pthread 1 error\n");
        return -1;
    }
    err=pthread_create(&tid2,NULL,thr_fn2,(void *)1);

    if(err!=0)
    {
        perror("create pthread 2 error \n");
        return -1;
    }
    err=pthread_join(tid1,&tret);  //阻塞线程1以等待结束
    if(err!=0)
    {
        perror("join thread1 error \n");
        return -1;
    }
    printf("thread 1 exit code %d  \n",(int)tret);

    err=pthread_join(tid2,&tret);  //阻塞线程2
    if(err!=0)
    {
        perror("join thread2 error ");
        return -1;
    }

    printf("thread 2 exit code %d  \n",(int)tret);

    return 1;
}
