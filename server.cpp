/*************************************************************************
	> File Name: server.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年11月13日 星期二 21时46分40秒
 ************************************************************************/

#include"unp.h"
#include<iostream>
using namespace std;
int main(int argc,char **argv){

    int connfd,listenfd;
    listenfd= socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET ;
    time_t times ;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(80);
    int flag = 1 ;
    if(setsockopt(listenfd,SOL_SOCKET,SO_REUSEPORT,&flag,sizeof(int))==1){
        perror("setopt");
        exit(0);
    }
    int ss = bind(listenfd,(struct sockaddr*)&saddr,sizeof(saddr));
    if(ss<0){
        cout<<"bind 出现错误"<<endl ;
        return 0 ;
    }
    cout<<"bind....."<<endl ;
    char buff[1000];
    ss= listen(listenfd,10);
    cout<<"listen....."<<endl;
    while(1){

        if((connfd = accept(listenfd,(struct sockaddr*)NULL,NULL))<0){
            return 0 ;
        }
        cout<<"accept...."<<endl;
        times = time(NULL);
        snprintf(buff,sizeof(buff),"%.24s\r\n",ctime(&times));
        write(connfd , buff,strlen(buff));
        close(connfd);
    }
}
