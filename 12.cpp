/*************************************************************************
	> File Name: 12.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 16 Oct 2018 05:06:53 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int main(){

    vector<int>a{1,2,3,4,5,5};
    for(auto i = a.begin(); i != a.end() ;i++){
            cout<< *i <<endl;
    }
}
