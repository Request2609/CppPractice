/*************************************************************************
	> File Name: 44.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 14 Oct 2018 06:38:29 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
using std::vector ;
int main(){
    
    vector<string>s(5) ;
    int i= 0 ;
    for(i = 0 ; i < 5 ;i++ ){
        
        getline(cin , s[i]);
    }
    for(i = 0 ; i< 5 ;i++ ){
        
        cout<<s[i]<<endl ;
    }

}
