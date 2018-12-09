#include"unp.h"
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int tcp_listen(char *addr,char * port,socklen_t *len);
int main(int argc,char ** argv){

    int sockfd,connfd;
    struct sockaddr_in serv ,cli;
    pid_t pid ;
    socklen_t clilen,addrlen ;
    void sig_chld(int),sig_int(int),wed_child(int);
    struct sockaddr*cliaddr ;
    if(argc == 2){
        sockfd = tcp_listen(NULL ,argv[1],&addrlen);
        if(sockfd<0)return -1 ;
    }
    else if(argc == 3){
        sockfd = tcp_listen(argv[1],argv[2],&addrlen);
        if(sockfd<0)return ;
    }
    else{
        cout<<"error input usage:serv <addr><port>"<<endl ;
        return -1 ;
    }
    // cliaddr = malloc(addrlen);
    signal(SIGCHLD,sig_chld);
    signal(STGINT,sig_int);
    // for()

}

int tcp_listen(char *addr,char *port,socklen_t *len){

    int fd,connfd ;
    fd = socket(AF_INET,SOCK_STREAM,0);
    if(fd<0){
        cout<<"error!"<<endl ;
        return -1;
    }
    int ports = atoi(port);
    struct sockaddr_in serv,cli ;
    serv.sin_family= AF_INET;
    serv.sin_port = htons(ports);
    if(addr==NULL){
        serv.sin_addr.s_addr =htonl(INADDR_ANY); 
    }
    else{
        serv.sin_addr.s_addr = inet_addr(addr);
    }
    int ss ;
    int flag = 1 ;
    if((ss = setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&flag ,sizeof(int)))<0){
        cout<<"error!"<<endl;
        return -1 ;
    }
   ss=bind(fd,(struct sockaddr*)&serv,sizeof(serv));
    if(ss < 0){
        cout<<"bind error!"<<endl;
        return -1 ;
    }
    cout<<"bind success!"<<endl ;
    ss = listen(fd ,20);
    if(ss<0){
        cout<<"listen error!"<<endl;
        return -1 ;
    }
    cout<<"listen....."<<endl ;
    connfd = accept(fd,(struct sockaddr*)&cli,len);
    if(connfd < 0){
        cout<<"connect dump!"<<endl ;
        return -1 ;
    }
    if(connfd < 0)return -1 ;
    return fd ;
}