/*************************************************************************
	> File Name: 123.cpp
	> Author:you yuan han shu you yuan lei 
	> Mail: 
    
	>Created Time: Sat 20 Oct 2018 09:56:57 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
void print3();
//void ob2::print1();
class ob2{
public:
    void print1(){
        
        printf("hello world1!\n");

    }
private:
    char name[100];
    int id ;
};
class ob1{
public :
    ob1();
    ~ob1();
    friend void print3();
    friend void ob2::print1();
    friend class ob3 ;
    void print(){
        print3();
//        print1();

        printf("hello world!\n");
    }
private:
    char name[100] ;
    int id ;

};

class ob3{

public :
    void print4(){
        printf("hello world!\n");

    }
};

ob1::ob1(){
    
    cout<<"a object is chuang jian!\n"<<endl;
}
ob1::~ob1(){

    cout<<"shi fang wan cheng"<<endl;
}
/*
 *
class ob2{
public:
    void print1(){
        
        printf("hello world1!\n");

    }
private:
    char name[100];
    int id ;
};
*/
void print3(){
    
    printf("hello world3!\n");
}
int main(){
    
    ob1 s ;
    
    s.print();
    /*s.print1();
    s.print3();
    s.print4();*/
}
