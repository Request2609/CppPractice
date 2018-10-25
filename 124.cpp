/*************************************************************************
	> File Name: 124.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 20 Oct 2018 10:39:58 PM PDT
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

class ob1{
    static ob1 s ;

public :
    static ob1 getOb1();
private:
    ob1();
    int id ;
    char name[100];
};

ob1 ob1::getOb1(){

    return s ;
}
ob1::ob1(){

    strcpy(name ,"changke");
    id = 1;
    cout<<"chang ke bei chuang jian!"<<endl;
}


int main(){

    ob1::getOb1();
    
}
