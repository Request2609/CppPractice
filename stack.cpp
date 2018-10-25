/*************************************************************************
	> File Name: 145.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Oct 2018 05:48:27 PM PDT
 ************************************************************************/

#include<iostream>
#include"stack.h"
using namespace std;
father :: father(){
    
    cout<<"Father has been extends"<<endl ;

}

father :: ~father(){

    cout<< "Father has been destroied!"<<endl ;
}

stack :: stack(){
    
    next =  NULL ;
    *top = next ;
    cout<<"a new stack has been build!"<<endl ;
}

stack ::~stack(){
    
    cout<<"a new stack  has been destroy!"<<endl ;
}

int main(){

    stack  s= new stack() ;

}
