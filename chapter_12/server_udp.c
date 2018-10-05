#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <errno.h>

#define SERVER_PORT 8888
#define MAX_MSG_SIZE 1024

int main(void)
{
int sockfd,addrlen,n;
struct sockaddr_in addr;   /*定义套接口地址数据结构addr */
char msg[MAX_MSG_SIZE]; 
sockfd=socket(AF_INET,SOCK_DGRAM,0); /*服务器端开始建立socket描述符*/
if(sockfd<0)
{
fprintf(stderr,"Socket Error:%s\n",strerror(errno));
exit(1);
}
/*服务器端填充 sockaddr结构*/
addrlen=sizeof(struct sockaddr_in);
bzero(&addr,addrlen);
addr.sin_family=AF_INET;
addr.sin_addr.s_addr=htonl(INADDR_ANY);
addr.sin_port=htons(SERVER_PORT);
if(bind(sockfd,(struct sockaddr *)(&addr),addrlen)<0) /*调用bind函数绑定端口*/
{ 
fprintf(stderr,"Bind Error:%s\n",strerror(errno)); 
exit(1); 
} 
//udps_respon(sockfd); 
while(1) 
{ /* 从网络上度,写到网络上面去 */ 
//n=recvfrom(sockfd,msg,MAX_MSG_SIZE,0, (struct sockaddr*)&addr,&addrlen); 
bzero(msg,MAX_MSG_SIZE);
n=recvfrom(sockfd,msg,sizeof(msg),0,(struct sockaddr*)(&addr),&addrlen); 
//msg[n]=0; 
/* 显示服务端已经收到了信息 */ 
fprintf(stdout,"Receive message from client: %s",msg); 
fgets(msg,MAX_MSG_SIZE,stdin);
printf("Server endpoint input message:%s",msg);
sendto(sockfd,msg,n,0,(struct sockaddr*)(&addr),addrlen); 
} 
close(sockfd); 
exit(0);
} 
