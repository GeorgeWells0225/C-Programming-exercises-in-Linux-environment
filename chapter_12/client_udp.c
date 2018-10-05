#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <errno.h> 
#include <stdio.h> 
#include <unistd.h>

#define MAX_BUF_SIZE 1024

//void udpc_requ(int sockfd,const struct sockaddr_in *addr,int len)


int main(int argc,char **argv) 
{
int sockfd,port,addrlen;
char buffer[MAX_BUF_SIZE]; 
int n; 
struct sockaddr_in addr;
if(argc!=3)
{ 
fprintf(stderr,"Usage:%s server_ip server_port\n",argv[0]);
exit(1);
}
if((port=atoi(argv[2]))<0) 
{ 
fprintf(stderr,"Usage:%s server_ip server_port\n",argv[0]); 
exit(1); 
} 
sockfd=socket(AF_INET,SOCK_DGRAM,0);  /*建立客户端socket*/
if(sockfd<0) 
{
fprintf(stderr,"Socket Error:%s\n",strerror(errno));
exit(1);
} 
/* 填充服务端的资料 */
addrlen=sizeof(struct sockaddr_in); 
bzero(&addr,addrlen); 
addr.sin_family=AF_INET; 
addr.sin_port=htons(port); 
if(inet_aton(argv[1],&addr.sin_addr)<0) 
{ 
fprintf(stderr,"Ip error:%s\n",strerror(errno)); 
exit(1); 
} 

//udpc_requ(sockfd,&addr,sizeof(struct sockaddr_in)); 
while(1) 
{ /* 从键盘读入, 写到服务端*/ 

bzero(buffer,MAX_BUF_SIZE); 
fgets(buffer,MAX_BUF_SIZE,stdin); 
sendto(sockfd,buffer,strlen(buffer),0,(struct sockaddr *)(&addr),addrlen); 
printf("Client endpoint input message:%s",buffer);
/* 从网络上读,写到屏幕上 */ 
n=recvfrom(sockfd,buffer,strlen(buffer),0,(struct sockaddr *)(&addr),&addrlen); 
//buffer[n]=0; 
//fputs(buffer,stdout); 
fprintf(stdout,"Receive message from server: %s",buffer);
} 
close(sockfd); 
exit(0);
}
