/*************************************************************************
	> File Name: 111.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 14 Oct 2018 07:08:18 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int main(){

    string word ;
    vector<string>s ;
    int i  ;
    for (i = 0; i < 5 ;i++){

        getline(cin,word);
        s.push_back(word);
    }
    
    for(i = 0 ;i < 5 ;i++){
        for(auto &c:s[i])
        c = toupper(c);
    }
    for( i =0 ; i< 5;i++ ){

        cout<<s[i]<<endl;
    }

}
