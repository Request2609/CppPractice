/*************************************************************************
	> File Name: 55.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 14 Oct 2018 07:45:56 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<string>s ;
    int i = 0 ;
    string word;
    cin>>word ;
    char ch ;
    s.push_back(word);
    if(s[0].begin()!=s[0].end()){
    
        auto it = s[0].begin();
    while(1){
        *it = toupper(*it);
        ch = *it ;
        cout<<ch<<endl;
        it++ ;
        if(*(s[0].end())== ch)break;
        }
    }
}
