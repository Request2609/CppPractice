/*************************************************************************
	> File Name: temp.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 03 Nov 2018 09:50:42 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

template <typename T>
class stack{

private:
    
    T data ;
public:
    stack(T m_data):data(m_data){

    }
    ~stack(){

    }
    void setData(T m_data);
    T getData();
};
 
template <typename T>
void stack<T>::setData(T m_data){
    data=m_data ;
}

template<typename T>
T stack<T>::getData(){
    
     return data ;
}

int main(){
    
    stack<int> b(11) ;
    b.setData(10);
    int a = b.getData();
    cout<<"a:"<<a<<endl ;
    stack<double>c(10) ;
    c.setData(11);
    int s = c.getData();
    cout<<"s:"<<s<<endl;
}
