#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
pthread_t ntid;  //�̺߳�
//��ӡ��ʶ���ĺ���
void  printids(const char *s)
{
        pid_t		pid;   //���̱�ʶ��
	pthread_t	tid;   //�̱߳�ʶ��

	pid = getpid();     
	tid = pthread_self();  //�ֱ��ý��̺��̱߳��
	printf("%s pid %u tid %u (0x%x)\n", s, (unsigned int)pid,
	  (unsigned int)tid, (unsigned int)tid);
        //��ӡ�̺߳ͽ��̱��
}
//�߳��п�ʼ���еĺ���
void *thr_fn(void *arg)
{
	printids("new thread: ");
	return((void *)0);
}
//������
int  main(void)
{
	int		err;
	err = pthread_create(&ntid, NULL, thr_fn, NULL); //����һ���߳�
	if (err != 0)  //����������ӡ������
        {
		printf("can't create thread: %s\n", strerror(err));
	}
        printids("main thread:");  //��ӡ���̺߳�
	sleep(1);
	exit(0);
}
