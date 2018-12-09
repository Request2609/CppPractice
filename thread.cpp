/*************************************************************************
	> File Name: thread.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 15 Nov 2018 12:33:37 AM PST
 ************************************************************************/

#include<iostream>
#include<mutex>
#include<unistd.h>
#include<mutex>
#include<functional>
#include<string>
#include<vector>
#include<thread>
#include<memory>
#include<list>
#include<condition_variable>
using namespace std;
class pool{

public:
    pool();
    pool(int num);
    ~pool();
    typedef function<void(void)>Task;
    bool start();
    bool stop();
    void threadWork(void);
    bool append(Task task);
private:
    mutex mute;
    //ding yi tiao jian bian liang
    condition_variable_any  condition_empty ;
    //ding yi ren wu dui lie
    list<Task>task;

    bool running ;
    int threadNumber ;

    //jinag chuang jian de xian cheng zhi zhen chuan jin rong qi
    vector<shared_ptr<thread>>threads;
};

pool::pool():threadNumber(1){}

pool::pool(int num):threadNumber(num){
    int i = 0 ;
}

pool::~pool(){
    
    while(running){
        stop();
    }
}
//ting zhi xiang xian cheng
bool pool::stop(void){
    
    if(running){
        //xun han deng dai xian cheng zhong zhi 
        running = false ;
        for(auto t:threads){
            
            t->join();
        }
    }
    return true ;
}

//wang ren wu dui liezhong tian jia xin yuan su
bool pool::append(Task tasks){

    //zi dong shang suo jie suo 
    lock_guard<mutex>guard(mute);
    task.push_front(tasks);
    condition_empty.notify_one();
    return true ;
}

//kai shi chuang jian xiang cehng chi ,chuangjian xian cheng
bool pool::start(){

    int i = 0; 
    for( i = 0 ; i < threadNumber;i++){
        threads.push_back(make_shared<thread>(bind(&pool::threadWork,this)));
    }
    usleep(500);
    cout<<"running....."<<endl ;
    return true ;
}

void pool::threadWork(void){
    
    Task tasks = NULL ;
    while(running){
        
        {
            lock_guard<mutex>guard(mute);
            //ru guo ren wu dui lie fei kong de hua
            //ru wei kong rang dui lie jin xing deng dai
            if(task.empty()){

                condition_empty.wait(mute);
            }

            if(!task.empty()){
                tasks = task.front();
                task.pop_front();
            }
            else{
                continue ;
            }            
        }
        tasks();
   } 
}
void func(){
    while(true)
    cout<<"hello wolrd!"<<endl;
}

void func1(){
    cout<<"hellllll"<<endl;
}
int main(){
    
    pool pp(2);
    pp.start();
    pp.append(func);
    pp.append(func1);

    pp.stop();
}
