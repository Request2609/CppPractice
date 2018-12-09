#include<iostream>
#include<memory>
#include<mcheck.h>
using namespace std;
class A{
public:
	A()	{
		a++ ;
		cout<<"build"<<"  "<<a<<endl;}
	~A(){
		a-- ;
		cout<<"destroy"<<"  "<<a<<endl;
	}
    void say(){
        cout<<"away from kingdom game"<<endl ;
    }
private:
	static int a ;
};

int A::a = 0 ;
int main(){
#ifndef  MEMORY_TRACE 
    mtrace();
#endif
	shared_ptr<A>demo1(new A);
	shared_ptr<A>demo2(new A);
	weak_ptr <A>demo3 = demo1;
    demo1->say();
    demo2->say();
    auto s= demo3.lock();
    demo1->say();
    s->say();
#ifndef MEMORY_TRACE
    muntrace();
#endif
}

