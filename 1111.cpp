#include <stdio.h>
#include <thread>
#include <mutex>
#include<list>
#include<vector>
#include <memory>
#include<condition_variable>
#include <functional>
#include<iostream>
#include <unistd.h>
using namespace std;
class ThreadPool
    {
        public:
            typedef std::function<void(void)> Task;
            ThreadPool(int threadNumber);
            ~ThreadPool();

            //������������������
            bool append(Task task);

            //�����̳߳�
            bool start(void);

            //ֹͣ�̳߳�
            bool stop(void);

        private:
            //�߳���ִ�еĹ�������
            void threadWork(void);

            std::mutex mutex_;                                              //������
            std::condition_variable_any condition_empty_;                   //���������Ϊ��ʱ����������
            std::list<Task> tasks_;                                         //�������
            bool running_;                                                  //�̳߳��Ƿ�������
            int threadNumber_;                                              //�߳���
            std::vector<std::shared_ptr<std::thread>> threads_;             //���������̶߳���ָ��
    };


ThreadPool::ThreadPool(int threadNumber)
    :threadNumber_(threadNumber),
    running_(true),
    threads_(threadNumber_)
{

}

ThreadPool::~ThreadPool()
{
    if(running_)
    {
        stop();
    }
}

bool ThreadPool::start(void)
{
    for(int i = 0; i < threadNumber_; i++)
    {
        threads_.push_back(make_shared<thread>(bind(&ThreadPool::threadWork,this)));//ѭ�������߳�       
    }
    usleep(500);
    printf("�̳߳ؿ�ʼ����\n");
    return true;   
}

bool ThreadPool::stop(void)
{
    if(running_)
    {
        running_= false;
        for(auto t : threads_)
        {
            t->join();  //ѭ���ȴ��߳���ֹ
        }
    }
    return true;
}

bool ThreadPool::append(Task task)
{
    std::lock_guard<std::mutex> guard(mutex_);
    tasks_.push_front(task);   //������������������
    condition_empty_.notify_one();//����ĳ���߳���ִ�д�����
    return true;
}

void ThreadPool::threadWork(void)
{
    Task task = NULL;
    while(running_)
    {   
        {
            std::lock_guard<std::mutex> guard(mutex_);
            if(tasks_.empty())
            {
                condition_empty_.wait(mutex_);  //�ȴ���������������
            }
            if(!tasks_.empty())
            {
                task = tasks_.front();  //����������л�ȡ�ʼ����
                tasks_.pop_front();     //��ȡ�ߵ����񵯳��������
            }
            else
            {
                continue;
            }
        }
        task(); //ִ������
    }
}
void fun(void)
{
    std::cout<<"hello"<<std::endl;
}

int main(int argc,char **argv)
{
    ThreadPool pool();


    pool.start();
    pool.append(fun);
    pool.stop();
  return 0;
}

