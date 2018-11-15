/*************************************************************************
	> File Name: client.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 14 Nov 2018 12:21:39 AM PST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
void str_cli(FILE*fd,int sockfd);
using namespace std;
#include"unp.h"
int main(int argc,char ** argv){
    
    int sockfd ;
    struct sockaddr_in servaddr;
    if(argc !=  2){
        cout<<"input error,there has two arguments"<<endl ;
        exit(0);
    }
    sockfd = socket(AF_INET, SOCK_STREAM,0);
    
    if(sockfd < 0){
        cout<<"build socket error!"<<endl ;
        return 0 ;
    }

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family= AF_INET ;
    servaddr.sin_port = htons(2345);
    int ss = inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
    if(ss < 0){
        cout<<"inet_pton error!"<<endl ;
        return 0 ;
    }
    ss = connect(sockfd, (struct sockaddr*)&servaddr,sizeof(sockaddr));
    str_cli(stdin,sockfd);
    exit(0);
}

void str_cli(FILE*fd , int sockfd){
    char sendline[101],recvline[101];
    while(fgets(sendline,100,fd)!= NULL){

        int ss = write(sockfd,sendline,strlen(sendline));
        if(ss< 0){
            cout<<"write error!"<<endl ;
            return ;
        }
        if(readline(sockfd,recvline,100)==0){
            cout<<"str_cli:server terminaled peerematurely"<<endl;
        }
        fputs(recvline,stdout);
    }
}
