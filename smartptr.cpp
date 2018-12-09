#include<stdlib.h>
#include<memory>
#include<iostream>
using namespace std;
struct test{
    int a ;
};
class demo{
private:
    test*b ;
public: 
    demo(){
        b = new test();
        cout<<"the demo build"<<endl ;
    }
    ~demo(){
        cout<<"the demo destroy"<<endl ;
    }
    void say(){
        cout<<"the No"<<b->a<<endl;
    }
};

int main(){

cout<<"---------------------------the unique_ptr using"<<endl ;
    unique_ptr <demo>demo1(new demo);
    // unique_ptr demo2 = demo1 ;
    unique_ptr<demo> demo3(new demo);
    unique_ptr <demo>demo4(new demo);
    cout<<"demo1"<<"";
    demo1->say() ;
    cout<<"demo3"<<"";
    demo3->say();
    cout<<"demo4"<<"";
    demo4->say() ;
    // cout<<"demo2"<<"";
    // demo2->say() ;
    cout<<"---------------------------shared_ptr using "<<endl ;
    shared_ptr<demo> demos(new demo); 
    cout<<"shared demos"<<"";
    demos->say() ;
    shared_ptr <demo>demoss(new demo);
    cout<<"shared demos"<<"";
    demoss->say() ;
    shared_ptr<demo> demosss(new demo);   
    cout<<"shared demosss"<<"";
    demosss->say() ;
    // cout<<"demo2"<<demo2->say()<<endl ;
    shared_ptr <demo>demod = demos ;
    demos->say();
    demos->say();
    demos->say();
    demod->say();
    cout<<"shared demod"<<"";
    demod->say() ;
}