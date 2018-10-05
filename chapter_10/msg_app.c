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
   }msg_sbuf;      /*发送消息缓冲区数据结构*/
struct msgmbuf
   {
      int mtype;
      char mtext[10];
   }msg_rbuf;      /*接收消息缓冲区数据结构*/
struct msqid_ds msg_ginfo,msg_sinfo;
char* msgpath="/unix/msgqueue";
key=ftok(msgpath,'a');  /*获取消息队列键值*/
gflags=IPC_CREAT|IPC_EXCL;
msgid=msgget(key,gflags|00666);  /*调用msgget创建消息队列*/
if(msgid==-1)
{
       printf("msg create error\n");
       return;
}
msg_stat(msgid,msg_ginfo);
/*创建一个消息队列后，输出消息队列缺省属性。第一次调用msg_stat 子函数*/
sflags=IPC_NOWAIT;   /*消息队列满时，msgsnd 不等待，立刻出错返回*/
msg_sbuf.mtype=10;
msg_sbuf.mtext[0]='a';   /*将要发送的消息数据*/
reval=msgsnd(msgid,&msg_sbuf,sizeof(msg_sbuf.mtext),sflags); /*调用msgsnd发送消息*/
if(reval==-1)
{
       printf("message send error\n");
}
msg_stat(msgid,msg_ginfo);
/*成功发送一个消息后，输出此时消息队列属性。第二次调用msg_stat 子函数*/
rflags=IPC_NOWAIT|MSG_NOERROR;       /*含义见表10.1*/
reval=msgrcv(msgid,&msg_rbuf,4,10,rflags);  
/*调用msgrcv接收消息，接收数据长度为4，type > 0，含义见表10.2*/
if(reval==-1)
{
       printf("read msg error\n");
    }
else
{
       printf("read from msg queue %d bytes\n",reval);   /*打印接收到数据的字节数*/
    }
msg_stat(msgid,msg_ginfo);
/*从消息队列中读出消息后，再次输出消息队列属性。第三次调用msg_stat 子函数*/
msg_sinfo.msg_perm.uid=8;
/*试图更改消息队列的缺省属性（要求root用户权限），所有者有效用户ID更改为8*/
msg_sinfo.msg_perm.gid=8;
/*消息队列的所有者有效组ID更改为8*/
msg_sinfo.msg_qbytes=16388;
/*消息队列可容纳最大字节数更改为16388（缺省为16384）*/
reval=msgctl(msgid,IPC_SET,&msg_sinfo);   /*调用msgctl设置消息队列属性*/
if(reval==-1)
{
       printf("msg set info error\n");
       return;
}
msg_stat(msgid,msg_ginfo);  /*验证设置消息队列属性。第三次调用msg_stat 子函数*/
reval=msgctl(msgid,IPC_RMID,NULL);  /* 操作完毕，调用msgctl删除消息队列*/
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
sleep(1);   /*只是为了后面输出时间的方便*/
reval=msgctl(msgid,IPC_STAT,&msg_info);  /*调用msgctl 获得消息队列属性信息*/
if(reval==-1)
{
      printf("get msg info error\n");
      return;
}
printf("\n");
printf("current number of bytes on queue is %d\n",msg_info.msg_cbytes);
printf("number of messages in queue is %d\n",msg_info.msg_qnum);
printf("max number of bytes on queue is %d\n",msg_info.msg_qbytes);
/*每个消息队列的容量（字节数）都有限制MSGMNB，值的大小因系统而异。在创建*/
/*新的消息队列时，msg_qbytes的缺省值就是MSGMNB*/
printf("pid of last msgsnd is %d\n",msg_info.msg_lspid);
/*最近一个执行msgsnd函数的进程ID*/
printf("pid of last msgrcv is %d\n",msg_info.msg_lrpid);
/*最近一个执行msgrcv函数的进程ID*/
printf("last msgsnd time is %s", ctime(&(msg_info.msg_stime)));
/*最近一次执行msgsnd函数的时间。ctime()将时间转变成周、月、日、时分秒、年的*/
/*形式，属于标准C函数*/
printf("last msgrcv time is %s", ctime(&(msg_info.msg_rtime)));
/*最近一次执行msgrcv函数的时间*/
printf("last change time is %s", ctime(&(msg_info.msg_ctime)));
/*最近一次改变该消息队列的时间*/
printf("msg uid is %d\n",msg_info.msg_perm.uid);/*消息队列所有者的有效用户ID*/
printf("msg gid is %d\n",msg_info.msg_perm.gid); /*消息队列所有者的有效组ID*/
}
