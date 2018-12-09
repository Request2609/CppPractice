/*************************************************************************
	> File Name: sem_t.h
	> Author: 
	> Mail: 
	> Created Time: Sun 25 Nov 2018 07:03:16 AM PST
 ************************************************************************/

#ifndef _SEM_T_H
#define _SEM_T_H
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<iostream>
using namespace std;
class sem_locker{

private:
    sem_t m_sem ;
public:
    sem_locker(){
        //init pos to 0
        if(sem_init(&m_sem,0,0)!= 0){
            
            printf("sem init error!\n");
        }
    }
    
    ~sem_locker(){
            sem_destroy(&m_sem);
    }
    
    bool wait(){

        return sem_wait(&m_sem) == 0 ;
    }
    
    bool add(){

        return sem_post(&m_sem)==0;
    }

};

#endif
