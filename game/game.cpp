/*************************************************************************
	> File Name: game.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 14 Nov 2018 06:40:28 AM PST
 ************************************************************************/
#include"game.h"
#include"gamehead.h"
int getch(void) {
	 struct termios tm, tm_old; 
	int fd = 0, ch; 
	if (tcgetattr(fd, &tm) < 0) {//保存现在的终端设置 
		return -1;
	 } 
	tm_old = tm; 
	cfmakeraw(&tm);//更改终端设置为原始模式，该模式下所有的输入数据以字节为单位被处理 
	if (tcsetattr(fd, TCSANOW, &tm) < 0) 
	{//设置上更改之后的设置 
		return -1;
	 } 
    ch = getchar();
    cout<<ch<<endl;
	if (tcsetattr(fd, TCSANOW, &tm_old) < 0) {//更改设置为最初的样子 
		return -1; } 
	return ch; 
}

void print(const char arr[N][N]){
    
    int i = 0;
    int j = 0;
    printf("%-3s","CK");
    for(i = 0 ;i < N ;i++){
        printf("%-3d",i+1);
    }
    cout<<"\n"<<endl ;
    for(i =0 ;i< N ;i++){
        printf("%-3d",i+1);
        for(j = 0 ; j< N ;j++){
            printf("%-3c",arr[i][j]);
        }
        cout<<"\n\n"<<endl;
    }
}

int modify(int x,int y,pan * p){
    
    int i = 0 ;
    int j = 0 ;
    for(i = 0;i < N ; i++){
        for(j = 0 ; j< N ;j++){
            if(x-1 == i&&y-1 == j&&p->arr[i][j]== '#'){
                p->arr[i][j]=p->keys;
                if(iswon(x-1,y-1,p)){
                    cout<<"You have won!"<<endl ;
                    return 6;
                }
                else{
                    return 1 ;
                }
            }
        }
    }
    return 0 ;
}


int iswon(int x,int y,const pan *p){

    int i = 0 ;
    int j = 0 ;
    int  flag = 0;
    for(i = 1 ; i<= 4 ; i++){
        for(j = 1;j<= 4 ;j++){
            if(i == j){
                //judge is outside of the aside and  is equal the cur keys
                if(!isoutside(x+i,y+j)&&p->arr[x+i][j+x] == p->keys){
                    flag ++ ;
                }
            }
        }
    }

}

int isoutside(int x,int y){
    
    if(x<N&&x>=0&&y<N&&y>=0){
        return 1 ;
    }
    return 0 ;
}
