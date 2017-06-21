#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>

#define SRVPORT 10005
#define CONNECT_NUM 5
#define MAX_NUM 80
#include<iostream>

using namespace std ;

int main()
{
    int clientSock=-1;
    struct sockaddr_in serverAddr;

    clientSock=socket(AF_INET,SOCK_STREAM,0);
    if(clientSock<0)
    {
        printf("socket creation failed\n");
        exit(-1);
    }
    printf("socket create successfully.\n");

    memset(&serverAddr,0,sizeof(serverAddr));
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_port=htons((u_short) SRVPORT);
    serverAddr.sin_addr.s_addr=htons(INADDR_ANY);

    if(connect(clientSock,(struct sockaddr*)&serverAddr,sizeof(struct sockaddr_in))<0)
    {
        printf("Connect error.\n");
        exit(-1);
    }
    printf("Connect successful.\n");

    string sendString = "CDCD";
    char revBuf[MAX_NUM]={0};
     for(int i=0;i<10;i++)
    //while(sendString!= "")
    {
         sleep(1);
        if(write(clientSock,sendString.c_str(),strlen(sendString.c_str()))==-1)
        {
            printf("send error!\n");
        }
        cout<<"客户端发送了--"<<sendString<<endl;
        sendString = "CD";

        //接收
        if(read(clientSock,revBuf,sizeof(revBuf))==-1)//MAX_NUM
        {
            printf("rev error!\n");
        }
        string receive = revBuf;
       // receive = "Goodbye,my dear client!";
        cout<<"收到服务器的信息 "<<receive<<endl;
        bzero(revBuf,sizeof(revBuf));
        
    }
       sendString = "quit";
       if(write(clientSock,sendString.c_str(),strlen(sendString.c_str()))==-1)
        {
            printf("send error!\n");
        }
    close(clientSock);
    return 0;
}
