#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#define PORT 5566             /*����˿ں�*/

int main(void)
{
   int sockfd,newsockfd;       /*������صı���*/
   struct sockaddr_in addr;       /*����IPv4�׽ӿڵ�ַ���ݽṹaddr*/
   int addr_len = sizeof(struct sockaddr_in);
  // fd_set myreadfds;
   char msgbuffer[256];          /*���ͺͽ������ݻ�����*/
   //char msg[ ] ="This is the message from server.Connected.\n";
   if ((sockfd = socket(AF_INET,SOCK_STREAM,0))<0)  /*����һ��socket*/
   {
      perror("socket error! ");
      exit(1);
   }
   else       /*socket�����ɹ�*/
   {
      printf("socket created successfully!\n");
      printf("socked id: %d \n",sockfd);
   }
   bzero(&addr,sizeof(struct sockaddr_in));  /*��ձ�ʾ��ַ�Ľṹ�����*/
   addr.sin_family =AF_INET;            /*����addr�ĳ�Ա��Ϣ*/
   addr.sin_port = htons(PORT);
   addr.sin_addr.s_addr = htonl(INADDR_ANY);  /*IP��ַ��Ϊ����IP*/
   if(bind(sockfd, (struct sockaddr *)(&addr), sizeof(struct sockaddr))<0)
                                     /*����bind�����󶨶˿�*/
   {
      perror("bind error!");
      exit(1);
   }
   else       /*�˿ڰ󶨳ɹ�*/
   {
      printf("bind port successfully!\n");
      printf("local port:%d\n",PORT);
   }
   if(listen(sockfd,3)<0) /*����listen���������˿ںţ���ͬʱ������������������Ϊ3*/
   {
      perror("listen error!");
      exit(1);
   }
   else
   {
      printf("listenning......\n");    /*�˿ڼ�����......*/
   }
   if((newsockfd = accept(sockfd,(struct sockaddr *)(&addr),&addr_len))<0)
/*����accept����һ����������*/
   {
      perror("accept error! ");
   }
   else                   /*���ӳɹ���������*/
   {
       printf("connect from %s\n",inet_ntoa(addr.sin_addr));
       if(read(newsockfd,msgbuffer,sizeof(msgbuffer))<=0)   /*����read������Ϣ*/
       { 
         perror("accept error!");
       }
       else
       {
          printf("message:\n%s \n",msgbuffer);    /*������յ�����Ϣ*/
        }
   }
return 0;
}
