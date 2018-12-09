/*************************************************************************
	> File Name: client6.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 20 Nov 2018 04:24:26 AM PST
 ************************************************************************/
#include<iostream>
#include"unp.h"
#define MAXLINE 4000
using namespace std;

int getsockfd(char *ip,int port);
int main(int argc,char** argv){
    //client <hostname><port><children><child><request>
    //ip port children  child  jinchengfasongdeqingqiushu  fanhuide shu ju zijie shu
    int i =0 ,j=0;
    char request[MAXLINE],buffer[MAXLINE];
    pid_t pid ;
    int sockfd;
    int nchild = atoi(argv[3]);
    int reqnum = atoi(argv[4]);
    int nbyte = atoi(argv[5]);
    int port = atoi(argv[2]);

    for(i = 0 ; i< nchild ;i++){
        if((pid = fork())==0){
            for(j =0 ;j < reqnum ;j++){
                if((sockfd = getsockfd(argv[1],port))<0){
                    cout<<"error!"<<endl;
                    exit(-1);
                }
                int ss = write(sockfd,request,strlen(request));
            
                if(ss< 0){
                        cout<<"can't writete!"<<endl;
                        exit(-1);
                }
                int n ;
                if((n=read(sockfd,buffer,nbyte))!= nbyte){
                    printf("server returned %d bytes",n);
                }
                close(sockfd);
        }
             cout<<"child %d done"<<endl;
             exit(0);
        }
    }
    while(wait(NULL)>0);
    if(errno!= ECHILD){
        cout<<("wait_error!");
    }
    exit(0);
}

int getsockfd(char *ip,int port){
        
    int sockfd;
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd< 0){
        perror("socket");
        return -1;
    }

    struct sockaddr_in addr;
    addr.sin_family= AF_INET ;
    addr.sin_port = htons(2345);
    int ss = inet_pton(AF_INET,ip,&addr.sin_addr);
    if(ss< -1){
        perror("inet_pton");
        return -1 ;
    }
    while(1){
        ss = connect(sockfd ,(struct sockaddr*)&addr,sizeof(sockaddr));
    }
    if(ss==-1){
        perror("connect");
        return -1;
    }
    return sockfd ;
}

