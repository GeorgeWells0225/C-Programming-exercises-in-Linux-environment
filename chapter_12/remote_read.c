#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#define PORT 5566             /*定义端口号*/

int main(void)
{
   int sockfd,newsockfd;       /*定义相关的变量*/
   struct sockaddr_in addr;       /*定义IPv4套接口地址数据结构addr*/
   int addr_len = sizeof(struct sockaddr_in);
  // fd_set myreadfds;
   char msgbuffer[256];          /*发送和接收数据缓冲区*/
   //char msg[ ] ="This is the message from server.Connected.\n";
   if ((sockfd = socket(AF_INET,SOCK_STREAM,0))<0)  /*建立一个socket*/
   {
      perror("socket error! ");
      exit(1);
   }
   else       /*socket创建成功*/
   {
      printf("socket created successfully!\n");
      printf("socked id: %d \n",sockfd);
   }
   bzero(&addr,sizeof(struct sockaddr_in));  /*清空表示地址的结构体变量*/
   addr.sin_family =AF_INET;            /*设置addr的成员信息*/
   addr.sin_port = htons(PORT);
   addr.sin_addr.s_addr = htonl(INADDR_ANY);  /*IP地址设为本机IP*/
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
   if(listen(sockfd,3)<0) /*调用listen函数监听端口号，能同时处理的最大连接请求数为3*/
   {
      perror("listen error!");
      exit(1);
   }
   else
   {
      printf("listenning......\n");    /*端口监听中......*/
   }
   if((newsockfd = accept(sockfd,(struct sockaddr *)(&addr),&addr_len))<0)
/*调用accept接受一个连接请求*/
   {
      perror("accept error! ");
   }
   else                   /*连接成功，输出结果*/
   {
       printf("connect from %s\n",inet_ntoa(addr.sin_addr));
       if(read(newsockfd,msgbuffer,sizeof(msgbuffer))<=0)   /*调用read接收信息*/
       { 
         perror("accept error!");
       }
       else
       {
          printf("message:\n%s \n",msgbuffer);    /*输出接收到的信息*/
        }
   }
return 0;
}
