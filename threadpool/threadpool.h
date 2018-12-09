/*************************************************************************
	> File Name: threadpool.h
	> Author: 
	> Mail: 
	> Created Time: Wed 14 Nov 2018 10:54:45 PM PST
 ************************************************************************/

#ifndef _THREADPOOL_H
#define _THREADPOOL_H
#include<thread>
#include<mutex>
#include<condition_variable>
#include<list>
#include<vector>
#include<memory>
#include<functional>
#endif
#uising namespace std ;
namespace netlib{
    
    class ThreadPool{

    public :
        //ding yi ren wu dui lie
        typedef function<void(void)>Task;
        ThreadPool(int threadNumber);
        ~ThreadPool();
        //tian jia ren wu daoren wu dui lie
        bool append(Task task);
        //qi dong xian cheng chi
        bool start(void);
        //ting zhi xian cheng chi
        bool stop();
    private:
        //xian cheng suo zhi xing de gong zuo han shu 
        mutex mutex_;//hu chi suo 
        condition_viriable_any cond_empty;//dang ren wu wei kong shi de tiao jianbian liang
        list<Task>tasks_
        bool running;
        int threadNumber ;
        //bao cun xian chengdui xiangde zhi zhen 
        vector<shared_ptr<thread>>threads ;

    }
    
};
