#include<stdio.h>
#include<iostream>
using namespace std;

static int callFirst(int a){

    cout<<a<<endl ;
    return ++a ;
}
static int callSecond(int a){
    cout<<a<<endl;
    return --a;
}

static void print(int a,int b){
    cout<<a<<"  "<<b<<endl; 
}

void ww(){

    int a= 10 ;
    print(callFirst(++a),callSecond(a--));
}

int main(){
    ww();
}