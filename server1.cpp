/*************************************************************************
	> File Name: server1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 18 Nov 2018 01:50:52 AM PST
 ************************************************************************/

#include<iostream>
#include"unp.h"
#define MAXLINE 100
using namespace std;
void sig_chld(int signo){
    pid_t pid ;
    int stat ;
    while((pid = waitpid(-1,&stat,WNOHANG))>0){
        cout<<"Child "<<pid<<"terminal\n"<<endl;
    }
    return ;
}
void str_echo(int sock_fd){
    
    ssize_t n ;
    char buf[MAXLINE];
again:

    while((n=read(sock_fd,buf,100))>0){
        write(sock_fd,buf,100);
    }
    if(n<0&&errno==EINTR)goto again;
    else if(n<0){
        cout<<"ooooooo"<<endl;
        return ;
    }
}
int main(){

    int connfd ,listenfd ;
    struct sockaddr_in serv,cliaddr ;
    pid_t pid ;

    socklen_t clilen ;

    bzero(&serv,sizeof(serv));
    listenfd = socket(AF_INET,SOCK_STREAM,0);
    serv.sin_family=AF_INET ;
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    serv.sin_port = (PORT);
    int s ;
    int ss = bind(listenfd,(struct sockaddr*)&serv,sizeof(serv));
    if(ss< 0){
        cout<<"error!"<<endl ;
    }
    ss = listen(listenfd,20);
    if(ss<0){
        cout<<"error!"<<endl ;
        return 0 ;
    }
    if(ss<0){
        cout<<"error!"<<endl ;
        return 0 ;
    }
    void sig_chld(int);
    ss= signal(SIGCHLD,sig_chld);
    if(ss< 0){
        cout<<"signal error!"<<endl ;
        return 0;
    }
    for(;;){
        
        clilen = sizeof(cliaddr);
        if((connfd = accept(listenfd,(struct sockaddr*)&cliaddr,&clilen))<0){
            if(errno==EINTR){
                continue ;
            }
            else{
                cout<<"accept error!"<<endl;
            }
        }
        if((pid = fork())<0){
            cout<<"error!"<<endl ;
            return -1;
        }
        if(pid == 0){
             s =close(listenfd);
            if(s<0){
                cout<<"close"<<endl ;
                exit(-1);
            }
            str_echo(connfd);
            exit(0);
        }
        s = close(connfd);
        if(s<0)exit(0);
    }
}
