/*************************************************************************
	> File Name: threads.h
	> Author: 
	> Mail: 
	> Created Time: Wed 14 Nov 2018 11:09:10 PM PST
 ************************************************************************/

#ifndef _THREADS_H
#define _THREADS_H
#include"threadpool.h"
#include<stdio.h>
#include<memory>
#include<functional>
#include<unistd.h>
#include<mutex>
#endif
using namespace netlib;

ThreadPool::ThreadPool(int threadNumbers):threadNumber(threadNumbers),running(true),threads(threadNumber){}

ThreadPool ::~ThreadPool(){
    
    if(running){
        stop();
    }
}
bool ThreadPool ::start(void){
    int i ;
    for(i = 0 ; i< threadNumber ;i++){
        //xun huan chuang jian xian cheng 
        threads.push_back(make_shared<thread>(&ThreadPool::threadWork,this);
    }
    usleep(500);
    cout<<"threadpool is running"<<endl ;
    return true ;
}

bool ThreadPool::stop(void){

    if(running){
        running = false;
    
        for(auto t:threads){
            t->join();//xun huan deng dai xian cheng zhong zhi
        }

    }
    return true ;
}
bool ThreadPool::threadWork(void){
    
    Task task = NULL ;
    while(running){
        {

        }
    }

}
