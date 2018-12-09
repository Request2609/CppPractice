/*************************************************************************
	> File Name: 12.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 31 Oct 2018 06:17:46 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
class animal{

public:
    animal();
    ~animal();
    virtual void print();
};

class cat:public animal{
    
public:
    cat() ;
    ~cat();
    void print (){

        cout<<"hello"<<endl;
    }
};

class dog:public animal{

public :
    dog();
    ~dog();
    void print(){
        
        cout<<"wwwowdwd"<<endl ;
    }
};

void animal::print(){
    
    cout<<"hhelloj"<<endl;
}

animal::~animal(){
    
}
animal::animal(){

}
cat :: cat(){
    

}
cat ::~cat(){
    
}
dog ::dog(){


}
dog::~dog(){

}

void func(animal &an){
    an.print();
}

int main(){
    
    animal an ;
    cat c ;
    dog d ;
    func(c);
    func(d);
    
}
