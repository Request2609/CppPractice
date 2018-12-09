#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
#define PORT 8000
#define IP "127.0.0.1"
typedef struct data{
	int i ;
	int cmd ;
}Data ;

void *recieve(void* args);

int main(){

	Data s ;
	int sock_fd ,choose;
	struct sockaddr_in sin ;
	memset(&sin , 0, sizeof(sin));
	//14字节位网址
	sin.sin_family = AF_INET ;
	//服务器端端口号,将其端口号的本地字节序转网络字节序
	sin.sin_port = htons(PORT);
	//将地址转化网络字节序
	inet_aton(IP , &sin.sin_addr);
	if((sock_fd = socket(AF_INET , SOCK_STREAM , 0))< 0){
		
		printf("socket\n");
		return 0;
	}
	if(connect(sock_fd , (struct sockaddr*)&sin , sizeof(sin)) < 0){
	
		printf("connect error!\n");
		return 0 ;
	}
	pthread_t thid ;
	//开线程接收数据
	pthread_create(&thid , NULL , (void *)recieve,(void *)&sock_fd) ;

	
	//该循环为主线程,客户端通过主线程给服务器发送请求
	while(1){
				printf("-------------------------------\n");
				printf("请输入要发给服务器的请求(输入1):\n");
				scanf("%d" , &(s.cmd));
				if(s.cmd == -1 ){
					close(sock_fd);
					exit(0);
				}
				printf("请输入一些数据:\n");
				scanf("%d",&(s.i));
				
				send(sock_fd , (void*)&s , sizeof(s) , 0);
	}
}


//接收服务器端返回的信息
void* recieve(void* args){

	Data s ;
	int ret,p ;
	p = *(int*)args ;
	while(1){
		if((ret = (recv(p ,(void *)&s , sizeof(s),0)))< 0){
			printf("recv\n");
			pthread_exit(NULL);
		}	
		else{

			printf("从服务器接收到数据:");
			printf("%d\n",s.i);
			printf("\n");
		}
	}
}