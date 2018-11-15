/*************************************************************************
	> File Name: stack1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 03 Nov 2018 08:52:22 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
template <typename T>
class stack{
    
private:
    enum{SIZE = 100};
    T data[SIZE] ;

    int top=0 ;
public:
    stack();
    ~stack();
    int push(T m_data);
    T pop();
    int getTop();
};

template <typename T>
stack<T>::stack(){

}
template<typename T>
stack<T>::~stack(){
    
}
template<typename T>
int stack<T>::push(T m_data){
    
    if(top == SIZE)return -1;
    data[top]= m_data ;
    top++;
}

template <typename T>
T stack<T>::pop(){

    top --;
    T d = data[top];

    return d;
}
template<typename T>
int stack<T>::getTop(){
    return top ;
}

int main(){

    stack<int>a;
    a.push(11);
    a.push(12);
    a.push(13);
    a.push(14);
    cout<<"-------------------------------"<<endl;
    while(a.getTop() != 0){

        cout<<a.pop()<<endl;
    }

    cout<<"-------------------------------"<<endl;
}
