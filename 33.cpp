/*************************************************************************
	> File Name: 33.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 14 Oct 2018 06:01:58 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){

    string s ;
    getline(cin,s);
    cout<<s<<endl ;
    int  i= 0;
    for(i = 0;i < s.size();i++){

        s[i] = 'x';
    }
    cout<<s<<endl ;
}
