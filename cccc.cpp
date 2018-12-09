#include<iostream>
#include<memory>
#include<mcheck.h>
using namespace std;
class A{
public:
	A()	{
		
		cout<<"build"<<"  "<<a<<endl;
        a++ ;
        }
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

void func(){
    shared_ptr<A>demo1(new A);
	shared_ptr<A>demo2(new A);
	weak_ptr <A>demo3 = demo1;
    demo1->say();
    demo2->say();
    auto s= demo3.lock();
    demo1->say();
    s->say();
}

int main(){
//检验是否内存泄漏
#ifndef  MEMORY_TRACE 
    mtrace();
#endif  
    func();
#ifndef MEMORY_TRACE
    muntrace();
#endif
}