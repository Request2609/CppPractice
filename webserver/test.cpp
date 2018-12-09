/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 25 Nov 2018 07:14:28 AM PST
 ************************************************************************/

#include<iostream>
#include<thread>
using namespace std;
#include"sem_t.h"

void func1(){

    cout<<"thread1"<<endl ;
}

void func2(){

    cout<<"thread2"<<endl ;
}
int main(){
    
    thread p(func1) ;
    thread p1(func2);
    cout<<"hello world"<<endl;
    p.join();
    p1.join();
    
}
