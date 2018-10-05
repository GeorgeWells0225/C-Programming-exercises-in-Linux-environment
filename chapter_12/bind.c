#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#define PORT 2345       /*����˿ں�*/

int main(void)
{
   int sockfd;          /*������صı���*/
   struct sockaddr_in addr;          /*����IPv4�׽ӿڵ�ַ���ݽṹaddr*/
   int addr_len = sizeof(struct sockaddr_in);
   if((sockfd = socket(AF_INET,SOCK_STREAM,0))<0)  /*����һ��socket*/
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
   addr.sin_family = AF_INET;               /*����addr�ĳ�Ա��Ϣ*/
   addr.sin_port = htons(PORT);
   addr.sin_addr.s_addr = htonl(INADDR_ANY); /*IP��ַ��Ϊ����IP*/
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
   return 0;
}
