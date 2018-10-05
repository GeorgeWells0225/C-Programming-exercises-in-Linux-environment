#include <stdio.h>
#include <pthread.h>
#define BUFFER_SIZE 4
#define OVER (-1)
struct producers                                        //定义生产者条件变量结构。
{
        int buffer[BUFFER_SIZE];                        //定义缓冲区。
        pthread_mutex_t lock;                           //定义访问缓冲区的互斥锁。
        int             readpos, writepos;                      //读写的位置。
        pthread_cond_t  notempty;                       //缓冲区有数据时的标记。
        pthread_cond_t  notfull;                        //缓冲区未满的标记。
};
//初始化缓冲区
void init(struct producers *b)
{
        pthread_mutex_init(&b->lock,NULL);
        pthread_cond_init(&b->notempty,NULL);
        pthread_cond_init(&b->notfull,NULL);
        b->readpos=0;
        b->writepos=0;
}
//在缓冲区中存放一个整数。
void put(struct producers *b, int data)
{
        pthread_mutex_lock(&b->lock);
        //当缓冲区为满时等待。
        while((b->writepos+1)%BUFFER_SIZE==b->readpos)
        {
          pthread_cond_wait(&b->notfull,&b->lock);
          //在返回之前，pthread_cond_wait需要参数b->lock。
        }
        //向缓冲区中写数据，并将写指针向前移动。
        b->buffer[b->writepos]=data;
        b->writepos++;
        if(b->writepos>=BUFFER_SIZE)
        {
         b->writepos=0;
        }
        //发送当前缓冲区中有数据的信号。
        pthread_cond_signal(&b->notempty);
        pthread_mutex_unlock(&b->lock);
}
//从缓冲区中读数据并将数据从缓冲区中移走。
int get(struct producers *b)
{
        int data;
        pthread_mutex_lock(&b->lock);
        //当缓冲区中有数据时等待。
        while(b->writepos==b->readpos)
        {
           pthread_cond_wait(&b->notempty,&b->lock);
        }
       //从缓冲区中读数据，并将指针前移。
       data=b->buffer[b->readpos];
       b->readpos++;
       if(b->readpos>=BUFFER_SIZE)
       {
         b->readpos=0;
       }
       //发送当前缓冲区未满的信号。
       pthread_cond_signal(&b->notfull);
       pthread_mutex_unlock(&b->lock);
       return data;
}

struct producers  buffer;

void *producer(void *data)
{
    int n;
    for(n=0;n<10;n++)
    {
      printf("Producer: %d-->\n",n);
      put(&buffer,n);
    }
    put(&buffer,OVER);
    return NULL;
}

void *consumer(void *data)
{
    int d;
    while(1)
    {
      d=get(&buffer);
      if(d==OVER)
      {
       break;
      }
      printf("Consumer: --> %d\n",d);
    }
    return NULL;
}
//主程序
int main(void)
{
    pthread_t tha,thb;
    void *retval;
    init(&buffer);
    pthread_create(&tha,NULL,producer,0);
    pthread_create(&thb,NULL,consumer,0);
    pthread_join(tha,&retval);
    pthread_join(thb,&retval);
    return 0;
}
