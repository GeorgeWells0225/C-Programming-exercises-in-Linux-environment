#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>                             /*����ͷ�ļ���*/
#define PORT 21                                     /*����һ���˿ںš�*/
#define REMOTE_IP "140.186.70.20"                   /*����һ��IP��ַ��*/

int main(void)
{   
   int sockfd;
   struct sockaddr_in addr;        /*����IPv4�׽ӿڵ�ַ���ݽṹaddr*/
   char buf[256];
   if((sockfd=socket(AF_INET,SOCK_STREAM,0)) < 0)   /*����һ��socket*/
   {
      perror("socket error!");
      exit(1);
   }
   else       /*socket�����ɹ�*/
   {
      printf("socket created successfully!\n");
      printf("socked id: %d \n", sockfd);
   }
   bzero(&addr,sizeof(struct sockaddr_in));     /*��ձ�ʾ��ַ�Ľṹ�����*/
   addr.sin_family =AF_INET;               /*����addr�ĳ�Ա��Ϣ*/
   addr.sin_port=htons(PORT);
   addr.sin_addr.s_addr=inet_addr(REMOTE_IP);
   if(connect(sockfd, (struct sockaddr *)(&addr), sizeof(struct sockaddr))<0)
                                   /*����connect���ӵ�Զ�̷�����*/
   {
      perror("connect error!");
      exit(1);
   }
   else         /*���ӳɹ�����������Ϣ*/
   {
      printf("connected successfully!\n");
      printf("remote ip:%s\n",REMOTE_IP);
      printf("remote port:%d\n",PORT);
   }
   recv(sockfd ,buf,sizeof(buf),0);     /*������Ϣ*/
   printf("%s\n",buf);                /*������յ�����Ϣ��*/
   return 0;
}
