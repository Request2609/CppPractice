/*************************************************************************
	> File Name: 22.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 14 Oct 2018 05:33:44 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){

    string s ;
    string s1 ;
    while((getline(cin,s))){
        getline(cin,s1);
        if(!s.empty()){
            s = s+s1 ;
            cout<< s<<endl;
            cout<<"the string long"<<s.size()<<endl;
        }
        else{
            
            cout<<"empty chuan    "<<s1<<endl ;
        }
    }
}
