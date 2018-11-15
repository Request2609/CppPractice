/*************************************************************************
	> File Name: set.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 03 Nov 2018 08:58:50 PM PDT
 ************************************************************************/

#include<iostream>
#include<set>
using namespace std;

int main(){

    set<int>coll ;
    coll.insert(1);
    coll.insert(100);
    coll.insert(14);
    coll.insert(12);
    for(auto a = coll.begin() ; a!=coll.end();a++){
        cout<<*a<<endl ;
    }
}
