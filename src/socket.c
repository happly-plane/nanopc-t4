#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#define ERR_EXIT(m) \
        do  \
        {   \
            perror(m); \
            exit(EXIT_FAILURE); \
        } while (0)

int main(void)
{
// unsigned long addr = inet_addr("192.168.1.100");
// printf("addr = %u \n",ntohl(addr));

int listenfd;
if ((listenfd = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP)) < 0)
        ERR_EXIT("socket");
struct sockaddr_in serveraddr;
memset(&serveraddr,0,sizeof(serveraddr));
serveraddr.sin_family = AF_INET;
serveraddr.sin_port = htons(5188);
serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
//serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (bind(listenfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr)) < 0)
        ERR_EXIT("bind");

    if((listen(listenfd,SOMAXCONN)) < 0 )
        ERR_EXIT("listen");
struct sockaddr_in peeraddr; 
socklen_t peerlen = sizeof(peeraddr);
int conn = 0;
    if ((conn = (accept(listenfd,(struct sockaddr *)&peeraddr,&peerlen)))< 0)
            ERR_EXIT("accept");
char recvbuf[1024];
while (1)
{
    memset(recvbuf,0,sizeof(recvbuf));
    int ret = read(conn,recvbuf,sizeof(recvbuf));
    fputs(recvbuf,stdout);
    write(conn,recvbuf,ret);
    /* code */
}
    
close(conn);
close(listenfd);

// unsigned int x = 0x12345678;
// unsigned char * p = (unsigned char*)&x;
// printf("%0x %0x %0x %0x",p[0],p[1],p[2],p[3]);

return 0;



}
