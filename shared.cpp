#include<stdio.h>
#include<iostream>
#include<memory>
using namespace  std;
class A{

private: 
    static int a ;
public:

    A(){
        a++ ;
        cout<<"the demo built"<<a<<endl ;
    }
    ~A(){
        a-- ;
        cout<<"the demo destroy"<<a<<endl ;
    }
    void say(){
        cout<<"demo"<<endl;
    }
};
int A::a = 0;
int main(){

    cout<<"-------------------unique ptr----------------"<<endl ;
    unique_ptr <A>demoa(new A);
    unique_ptr <A>demob(new A);
    // unique_ptr democ = demob;
    demoa->say();
    demob->say();
}

