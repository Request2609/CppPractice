/*************************************************************************
	> File Name: server.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年11月13日 星期二 19时25分02秒
 ************************************************************************/
#include"unp.h"
#include<iostream>
using namespace std;
int main(int argc,char**argv){

    int sockfd ,n ;
    char recvline[1000];
    struct sockaddr_in serv;
    if(argc != 2){
     cout<<"输入格式不对" <<endl;
        return 0 ;
    }
    sockfd= socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0){
        cout<<"socket 出错"<<endl;
        return 0 ;
    }
    bzero(&serv,sizeof(serv));
    serv.sin_family = (AF_INET);
    serv.sin_port  = htons(5678);
    if(inet_pton(AF_INET,argv[1],&serv.sin_addr)<=0){
        cout<<"出现错误"<<endl;
        return 0 ;
    }
    if(connect(sockfd,(struct sockaddr*)&serv,sizeof(serv))< 0){
        cout<<"connect 出现错误"<<endl;
        return 0;
    }
    while((n =read(sockfd,recvline,100))>0){
        recvline[n-1]='\0';
        if(fputs(recvline,stdout) == EOF){
            cout<<"读取出错"<<endl ;
            return  0 ;
        }
        if(n< 0){
            cout<<"读取完毕"<<endl ;
            return 0 ;
        }
    }
    cout<<recvline<<endl ;
}

