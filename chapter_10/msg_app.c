#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
void msg_stat(int,struct msqid_ds );

int main(void)
{
int gflags,sflags,rflags;
key_t key;
int msgid;
int reval;
struct msgsbuf
{
      int mtype;
      char mtext[1];
   }msg_sbuf;      /*������Ϣ���������ݽṹ*/
struct msgmbuf
   {
      int mtype;
      char mtext[10];
   }msg_rbuf;      /*������Ϣ���������ݽṹ*/
struct msqid_ds msg_ginfo,msg_sinfo;
char* msgpath="/unix/msgqueue";
key=ftok(msgpath,'a');  /*��ȡ��Ϣ���м�ֵ*/
gflags=IPC_CREAT|IPC_EXCL;
msgid=msgget(key,gflags|00666);  /*����msgget������Ϣ����*/
if(msgid==-1)
{
       printf("msg create error\n");
       return;
}
msg_stat(msgid,msg_ginfo);
/*����һ����Ϣ���к������Ϣ����ȱʡ���ԡ���һ�ε���msg_stat �Ӻ���*/
sflags=IPC_NOWAIT;   /*��Ϣ������ʱ��msgsnd ���ȴ������̳�����*/
msg_sbuf.mtype=10;
msg_sbuf.mtext[0]='a';   /*��Ҫ���͵���Ϣ����*/
reval=msgsnd(msgid,&msg_sbuf,sizeof(msg_sbuf.mtext),sflags); /*����msgsnd������Ϣ*/
if(reval==-1)
{
       printf("message send error\n");
}
msg_stat(msgid,msg_ginfo);
/*�ɹ�����һ����Ϣ�������ʱ��Ϣ�������ԡ��ڶ��ε���msg_stat �Ӻ���*/
rflags=IPC_NOWAIT|MSG_NOERROR;       /*�������10.1*/
reval=msgrcv(msgid,&msg_rbuf,4,10,rflags);  
/*����msgrcv������Ϣ���������ݳ���Ϊ4��type > 0���������10.2*/
if(reval==-1)
{
       printf("read msg error\n");
    }
else
{
       printf("read from msg queue %d bytes\n",reval);   /*��ӡ���յ����ݵ��ֽ���*/
    }
msg_stat(msgid,msg_ginfo);
/*����Ϣ�����ж�����Ϣ���ٴ������Ϣ�������ԡ������ε���msg_stat �Ӻ���*/
msg_sinfo.msg_perm.uid=8;
/*��ͼ������Ϣ���е�ȱʡ���ԣ�Ҫ��root�û�Ȩ�ޣ�����������Ч�û�ID����Ϊ8*/
msg_sinfo.msg_perm.gid=8;
/*��Ϣ���е���������Ч��ID����Ϊ8*/
msg_sinfo.msg_qbytes=16388;
/*��Ϣ���п���������ֽ�������Ϊ16388��ȱʡΪ16384��*/
reval=msgctl(msgid,IPC_SET,&msg_sinfo);   /*����msgctl������Ϣ��������*/
if(reval==-1)
{
       printf("msg set info error\n");
       return;
}
msg_stat(msgid,msg_ginfo);  /*��֤������Ϣ�������ԡ������ε���msg_stat �Ӻ���*/
reval=msgctl(msgid,IPC_RMID,NULL);  /* ������ϣ�����msgctlɾ����Ϣ����*/
if(reval==-1)
{
       printf("unlink msg queue error\n");
       return;
}
return 0;
}

void msg_stat (int msgid,struct msqid_ds msg_info)
{
int reval;
sleep(1);   /*ֻ��Ϊ�˺������ʱ��ķ���*/
reval=msgctl(msgid,IPC_STAT,&msg_info);  /*����msgctl �����Ϣ����������Ϣ*/
if(reval==-1)
{
      printf("get msg info error\n");
      return;
}
printf("\n");
printf("current number of bytes on queue is %d\n",msg_info.msg_cbytes);
printf("number of messages in queue is %d\n",msg_info.msg_qnum);
printf("max number of bytes on queue is %d\n",msg_info.msg_qbytes);
/*ÿ����Ϣ���е��������ֽ�������������MSGMNB��ֵ�Ĵ�С��ϵͳ���졣�ڴ���*/
/*�µ���Ϣ����ʱ��msg_qbytes��ȱʡֵ����MSGMNB*/
printf("pid of last msgsnd is %d\n",msg_info.msg_lspid);
/*���һ��ִ��msgsnd�����Ľ���ID*/
printf("pid of last msgrcv is %d\n",msg_info.msg_lrpid);
/*���һ��ִ��msgrcv�����Ľ���ID*/
printf("last msgsnd time is %s", ctime(&(msg_info.msg_stime)));
/*���һ��ִ��msgsnd������ʱ�䡣ctime()��ʱ��ת����ܡ��¡��ա�ʱ���롢���*/
/*��ʽ�����ڱ�׼C����*/
printf("last msgrcv time is %s", ctime(&(msg_info.msg_rtime)));
/*���һ��ִ��msgrcv������ʱ��*/
printf("last change time is %s", ctime(&(msg_info.msg_ctime)));
/*���һ�θı����Ϣ���е�ʱ��*/
printf("msg uid is %d\n",msg_info.msg_perm.uid);/*��Ϣ���������ߵ���Ч�û�ID*/
printf("msg gid is %d\n",msg_info.msg_perm.gid); /*��Ϣ���������ߵ���Ч��ID*/
}
