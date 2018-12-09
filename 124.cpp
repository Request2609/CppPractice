/*************************************************************************
	> File Name: 124.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 27 Nov 2018 03:58:45 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;
class C{
public:
    C(){
        cout<<"C"<<endl;
    }
    ~C(){
        cout<<"~C"<<endl;
    }
};
class A{
public:
    A(){
        cout<<"A"<<endl;
    }
    ~A(){
        cout<<"~A"<<endl;
    }
    void say(){
        cout<<"hello world!"<<endl;
    }
};

class B:public A,public C{
    
public:
    B(){

        cout<<"B"<<endl ;
    }
    ~B(){
        cout<<"~B"<<endl ;
    }
};

class D:public B{
    
public:
    D(){
        cout<<"D"<<endl;
    }
    ~D(){
        cout<<"~D"<<endl;
    }
};
int main(){
  
    D *d = new D();
    d->say();
    delete(d);
}
