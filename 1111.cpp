/*************************************************************************
	> File Name: 1111.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 16 Oct 2018 04:34:29 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
int  main(){

    const int ci = 0 ,&cj = ci ;
    decltype(ci)  x = 0 ;
    decltype(cj)  z =ci ;
    cout<< z<<endl;
    
}
