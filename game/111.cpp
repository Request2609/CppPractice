/*************************************************************************
	> File Name: 111.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 14 Nov 2018 11:17:39 PM PST
 ************************************************************************/
#include<stdio.h>
#include<unistd.h>
#include<termio.h>
#include<iostream>
using namespace std;
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

int main(){
    while(1){
        char a = getch();
        cout<<a<<endl;
        if(a== 'q')break;
    }
}
