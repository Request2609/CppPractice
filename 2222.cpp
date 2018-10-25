/*************************************************************************
	> File Name: 2222.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 16 Oct 2018 04:54:37 AM PDT
 ************************************************************************/
#include<vector>
#include<iostream>
using namespace std;
int main(){

    vector<int>v{1,2,3,4,5,6,7,8};
    for(auto &i : v)i*= i  ;
    for(auto i : v)
        cout<< i<<"  ";
    cout<<endl;
          }
