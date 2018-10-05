#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#define PORT 2345       /*定义端口号*/

int main(void)
{
   int sockfd;          /*定义相关的变量*/
   struct sockaddr_in addr;          /*定义IPv4套接口地址数据结构addr*/
   int addr_len = sizeof(struct sockaddr_in);
   if((sockfd = socket(AF_INET,SOCK_STREAM,0))<0)  /*建立一个socket*/
   {
      perror("socket error!");
      exit(1);
   }
   else       /*socket创建成功*/
   {
      printf("socket created successfully!\n");
      printf("socket id:%d\n",sockfd);
   }
   bzero(&addr,sizeof(struct sockaddr_in));     /*清空表示地址的结构体变量*/
   addr.sin_family = AF_INET;               /*设置addr的成员信息*/
   addr.sin_port = htons(PORT);
   addr.sin_addr.s_addr = htonl(INADDR_ANY); /*IP地址设为本机IP*/
   if(bind(sockfd, (struct sockaddr *)(&addr), sizeof(struct sockaddr))<0)
                                     /*调用bind函数绑定端口*/
   {
      perror("bind error!");
      exit(1);
   }
   else       /*端口绑定成功*/
   {
       printf("bind port successfully!\n");  
       printf("local port:%d\n",PORT);
   }
   return 0;
}
