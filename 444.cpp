/*************************************************************************
	> File Name: 444.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 14 Oct 2018 06:43:59 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int main(){
    string word ;
    vector<string>s ;
    int i = 0 ;
    for( i= 0;i < 5 ;i++ ){

        getline(cin ,word);
        s.push_back(word);
    }
    for(i  = 0 ;i< 5 ; i++){

        cout<< s[i]<< endl;
    }
}
