/*************************************************************************
	> File Name: bind.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 19 Nov 2018 07:13:47 AM PST
 ************************************************************************/

#include<iostream>
#include"unp.h"
#include<sys/un.h>
using namespace std;

int main(int argc ,char** argv){
    int sockfd ;
    socklen_t len ;
    struct sockaddr_in addr1,addr2 ;
    if(argc != 2){
        cout<<"error!"<<endl;
        return 0;
    }
    sockfd = socket(AF_LOCAL,SOCK_STREAM,0);
    unlink(argv[1]);
    bzero(&addr1,sizeof(addr1));
    addr1.sin_family=AF_LOCAL;
    strncpy(addr1.sin_path,argv[1],sizeof(addr1.sin_path)-1)
    bind(sockfd,(struct sockaddr*)&addr2,SUN_LEN(&addr1));
    len = sizeof(addr2);
    getsockname(sockfd,(struct sockaddr*)&addr2,&len);
    cout<<"bound name:"<<addr2.sun_path<<len<<endl;
    exit(0);

}
