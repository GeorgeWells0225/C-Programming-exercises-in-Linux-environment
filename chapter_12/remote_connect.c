#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 80                       /*定义一个端口号*/
#define REMOTE_IP "119.75.213.61"      /*定义一个IP地址*/

int main(void)
{
   int sockfd;
   struct sockaddr_in addr;     /*定义IPv4套接口地址数据结构addr*/
   if( (sockfd = socket(AF_INET,SOCK_STREAM,0))<0 )  /*建立一个socket*/
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
   addr.sin_family = AF_INET;              /*设置addr的成员信息*/  
   addr.sin_port=htons(PORT);
   addr.sin_addr.s_addr=inet_addr(REMOTE_IP);
   if(connect(sockfd, (struct sockaddr *)(&addr), sizeof(struct sockaddr)) < 0)
                              /*调用connect连接到远程服务器*/
   {
      perror("connect error!");
      exit(1);
   }
   else         /*连接成功，输出相关信息*/
   {
      printf("connected successfully!\n");
    }
return 0;
}
