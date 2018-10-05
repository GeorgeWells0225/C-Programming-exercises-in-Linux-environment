#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 80                       /*����һ���˿ں�*/
#define REMOTE_IP "119.75.213.61"      /*����һ��IP��ַ*/

int main(void)
{
   int sockfd;
   struct sockaddr_in addr;     /*����IPv4�׽ӿڵ�ַ���ݽṹaddr*/
   if( (sockfd = socket(AF_INET,SOCK_STREAM,0))<0 )  /*����һ��socket*/
   {
      perror("socket error!");
      exit(1);
   }
   else       /*socket�����ɹ�*/
   {
      printf("socket created successfully!\n");
      printf("socket id:%d\n",sockfd);
   }
   bzero(&addr,sizeof(struct sockaddr_in));     /*��ձ�ʾ��ַ�Ľṹ�����*/
   addr.sin_family = AF_INET;              /*����addr�ĳ�Ա��Ϣ*/  
   addr.sin_port=htons(PORT);
   addr.sin_addr.s_addr=inet_addr(REMOTE_IP);
   if(connect(sockfd, (struct sockaddr *)(&addr), sizeof(struct sockaddr)) < 0)
                              /*����connect���ӵ�Զ�̷�����*/
   {
      perror("connect error!");
      exit(1);
   }
   else         /*���ӳɹ�����������Ϣ*/
   {
      printf("connected successfully!\n");
    }
return 0;
}
