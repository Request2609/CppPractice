/*************************************************************************
	> File Name: little.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 26 Nov 2018 11:45:31 PM PST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
void getLittle(char *arr){
    int i = 0 ;
    char ch = 'A';
    char k,j ;
    for(i = 0 ; i < 26 ;i++){
        
        k = ch + i ;

        arr[i] = k ;
        cout<<arr[i]<<endl;
    }
    int m ;
    ch = 'a';
    for(m = 0 ;m < 26 ; m++){
        k = ch+m;
        arr[i+m] = k;
    }
    m = i+m ;
    arr[m++] = '.';
    arr[m++] = ' ';
    arr[m] = '#';
    cout<<arr<<endl;
}
