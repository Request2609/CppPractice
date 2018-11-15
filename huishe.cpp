/*************************************************************************
	> File Name: huishe.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 13 Nov 2018 11:57:31 PM PST
 ************************************************************************/

#include<iostream>
#include"unp.h"
using namespace std;
void str_echo(int sockfd);
int main(int argc ,char ** argv){
    
    int listenfd ,connfd ;
    pid_t pid;
    socklen_t  client ;
    struct sockaddr_in serv,cliaddr;
    listenfd = socket(AF_INET,SOCK_STREAM,0);
    if(listenfd < 0){
        cout<<"listen error!"<<endl ;
        return  0 ;
    }
    serv.sin_family= AF_INET ;
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    serv.sin_port = htons(2345);
    
    int ss= bind(listenfd,(struct sockaddr*)&serv,sizeof(serv));
    if(ss< 0){
        cout<<"bind error!"<<endl ;
        return 0 ;
    }
    listen(listenfd,10);
    cout<<"listening......"<<endl;
    for(;;){
        client = sizeof(cliaddr);
        connfd = accept(listenfd,(struct sockaddr*)&cliaddr ,&client);
        if((pid= fork())==0){
            close(listenfd );
            str_echo(connfd);
            exit(0);
        }
        if(pid < 0){
            cout<<"fork error!"<<endl ;
            exit(-1);
        }
        close(connfd);
    }
}

void str_echo(int sockfd){
    ssize_t n ;
    char buf[1000];
again:
    while((n= read(sockfd,buf,n))>0)
        write(sockfd,buf,n);
    
        if(n< 0&&errno== EINTR){
            goto again ;
        }

        else if(n< 0){
            cout<<"str_err:read error!"<<endl;
        }
}
