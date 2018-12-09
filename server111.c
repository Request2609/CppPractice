#include<stdio.h>
#include<stdlib.h>
#include<sys/epoll.h>
#include<arpa/inet.h>
#include<string.h>
#include<errno.h>
#include<sys/socket.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/fcntl.h>
#define MAX 20 
#define PORT 8000
typedef struct data{
	int  i ;
	int cmd ;
}Data;
int epoll_fd;

int init_sock(int sock_fd);
void user_process(void* ret);
void setnonblocking(int sock_fd);

//将套接字设置为非阻塞模式
void setnonblocking(int sock_fd){
	
	int opts ;
	opts = fcntl(sock_fd ,F_GETFL) ;
	if(opts < 0){
	
		printf("F_GETFL") ;
		return ;
	}

	opts = (opts|O_NONBLOCK);
	if(fcntl(sock_fd , F_SETFL ,opts) < 0){
		printf("F_SETFL");
		return ;
	}
}
//初始化服务器端套接字
int init_sock(int sock_fd){

	int optval ;
	optval = 1 ;
	sock_fd = socket(AF_INET , SOCK_STREAM , 0);
	//保证套接字断开连接后能重新绑定端口
	if(setsockopt(sock_fd , SOL_SOCKET ,SO_REUSEADDR ,(void *)&optval ,sizeof(int)) < 0){
	
		printf("setsockopt error!\n");
	}
	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET ;//14字节序地址
	serv_addr.sin_port = htons(PORT);//端口号
	//INADDR_ANY一个服务器上的所有网卡,多个本地IP地址都进行绑定端口号,进行倾听
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if(bind(sock_fd ,(struct sockaddr*)(&serv_addr) , sizeof(serv_addr))< 0){//绑定端口
		
		printf("bind error!\n") ;
		return 0 ;
	}
	printf("bind finish......   ;)\n");
	if(listen(sock_fd , MAX)< 0){//监听端口
		
		printf("listen");
		return 0 ;
	}
	printf("Listening.....      :)\n");
	return  sock_fd;
}
	 

int main(){

	int sock_fd ;
	int i ,ret;
	int conn_fd ;
	sock_fd = init_sock(sock_fd);
	if(sock_fd == 0){
		return 0 ;
	}
	epoll_fd = epoll_create(256);
	//定义epoll事件结构体
	struct epoll_event  ep_ev ;
	//将事件设置为可读事件
	ep_ev.events = EPOLLIN ;
	//将套接字设置为epoll类型套接字
	ep_ev.data.fd = sock_fd ;
	//将套接字注册到事件列表中
	ret = epoll_ctl(epoll_fd , EPOLL_CTL_ADD , sock_fd ,&ep_ev) ;
	if(ret < 0){
		
		printf("epoll_ctl\n");
		return  0 ;
	}
	//定义epoll表
	struct epoll_event evs[MAX] ;
	while(1){
	
		//等待有活跃事件将其加入到就绪列表中
		int epoll_ret = epoll_wait(epoll_fd , evs , MAX , -1);
		if(epoll_ret > 0){
			//轮询就绪事件
			for( i = 0 ; i < epoll_ret ;i++ ){
				//如果就绪事件时新连接且为可读事件
				if(evs[i].data.fd == sock_fd&&(evs[i].events&EPOLLIN)){
				struct sockaddr_in cli_addr ;
				socklen_t cli_len ;
				cli_len = sizeof(struct sockaddr_in);
				//进行套接字连接,产生新套接字
				conn_fd = accept(sock_fd , (struct sockaddr*)&cli_addr ,&cli_len) ;
				printf("有新连接......    ;)\n");
				if(conn_fd < 0){
					printf("连接出错!\n") ;
					return  0;
				}  
				//设置为非阻塞模式,像本程序种单纯的打印数据,就将非阻塞断了,否则客户端会循环打印数据
				//setnonblocking(conn_fd);
				//设置事件为可读事件且为边缘触发模式ET
				ep_ev.events = EPOLLIN | EPOLLONESHOT ;
				ep_ev.data.fd = conn_fd ;
				ret = epoll_ctl(epoll_fd , EPOLL_CTL_ADD ,conn_fd , &ep_ev) ;

			if(ret < 0){
			
				printf("注册出错!\n");
				exit(0) ;
			}
				}
				else{
				
					if(evs[i].events & EPOLLIN){
					 
						pthread_t thid ;
						pthread_create(&thid , NULL , (void*)&user_process , (void*)&evs[i].data.fd) ;
					}
				}

			}
		}

		else{
		
				printf("轮询出错!\n");
				return 0;
		}
	}


	close(sock_fd);
}

//模拟处理客户端请求
void user_process(void*ret){

	
	int fd ,temp;
	fd = *((int *)ret) ;
	Data s ;
	
	while(1){	//接收客户端数据
		temp = recv(fd ,(void*)&s , sizeof(s) , 0);
		if(temp <= 0){
			printf("连接%d已经断开......      +_+\n",fd);
			close(fd);
			pthread_exit(NULL) ;
		}
		
		if(s.cmd == 1){
		
				printf("------------------------------\n");
				printf("客户端传来的数字:");
				printf("%d\n\n",s.i);
				printf("------------------------------\n");
				printf("给客户端返回个数据吧?\n");
				printf("请输入数据:\n");
				scanf("%d",&s.i);
				send(fd ,(void *)&s ,sizeof(s) , 0 );
			
		}
		else{
		
			s.i = 0 ;
			printf("客户端发来的命令不是1\n");
			send(fd , (void *)&s , sizeof(s) , 0);
		}
	}
}
