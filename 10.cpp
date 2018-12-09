/*************************************************************************
	> File Name: 10.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 15 Nov 2018 12:11:01 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include "thread_pool.h"
#include <unistd.h>

void fun(std::string s)
{
    std::cout<<s<<std::endl;
}

int main(int argc,char **argv)
{
  netlib::ThreadPool pool(10);
  pool.start();
  while(1)
  {
    pool.append(std::bind(fun,std::string("hello")));
  }  
  return 0;
}
