#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//�̴߳�����
void *threaddeal(void *arg)
{
  int i = *(int *)(arg);
  printf("���ǵ�%d���߳�\n",i);
}
//������
int main(void)
{
   //�߳�id
    pthread_t threadid;
    int j;
    //���������߳�
    int count = 20;  //���ѭ��
    for(j=0 ; j < count ; j++)
    {
      //�̲߳���
      int * p = &(j);
      //�����߳�
      int ret= pthread_create(&threadid, NULL, threaddeal, (void*)p);
      if(ret)//����ʧ��
      {
        printf("�����߳�ʧ��:%d\n",ret);
      }
      else//�����ɹ�
      {
        //�����̻߳����̵߳�stackռ�õ��ڴ�
        pthread_detach(threadid);
       }
    }
    return 0;
}
