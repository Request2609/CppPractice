#include<iostream>
#include<stdlib.h>
#include<memory>
#include<list>
#include<stdio.h>
#include<strings.h>
#include"hafuman.h"
using namespace std;
void getchars(char *arr){
    
    int a ;
    char ch = 'A';
    char k ;
    int i = 0 ;
    arr[0] = ' ';
    arr[1] = '.';
    for(i = 2 ; i < 28 ; i++){
        k = ch + i-2 ;
        arr[i] = k ;
    } 
    ch = 'a';
    int j ;
    for(j = 0 ;j < 26 ;j++){
        k = ch + j;
        arr[j+i] = k ;
    }
    j = j+i ;
    cout<<arr<<endl;
}
int main(){

    

    char line[MAXLINE];
    array<shared_ptr<record>,MAXLINE>ls;
    scanf("%[^\n]",line);
    //record::getchars(line);
    record::initarr(ls);
    record::input(line,ls);

    array<shared_ptr<hafu>,SIZE>arr ;

    hafu::init(arr,ls); 
    
    hafu::process(arr);
    hafu::request(arr);
    hafu::makeCode(arr);
    // cout<<endl;*/
    hafu::transform(arr);
}

