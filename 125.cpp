/*************************************************************************
	> File Name: 125.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 20 Oct 2018 10:46:03 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
class singleTon{
public :
    static singleTon *getSingle();
    void doSomething();
    void destroy();
private:
    singleTon();
    ~singleTon();
    static singleTon*s ;
};

void singleTon::destroy(){

    delete this ;
    s = NULL;
    cout<<"the object is detoroied\n"<<endl;
}
singleTon* singleTon ::s = NULL ;


singleTon::singleTon(){

    cout<<"sington is exist!\n"<<endl;
}

void singleTon::doSomething(){
    cout<<"hello world!\n"<<endl;
}

//fei xian cheng an quan 
singleTon* singleTon:: getSingle(){
    
    singleTon * ret = s ;
    if(ret == NULL){
        
        s = new singleTon();
        ret = s ;
    }
    return s ;
}

singleTon::~singleTon(){
    cout<<"the single has been destoried\n"<<endl;

}

int main(){

    singleTon* s =singleTon::getSingle();
    s->doSomething();
    s->destroy();
}
