/*************************************************************************
	> File Name: list.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 03 Nov 2018 08:39:23 PM PDT
 ************************************************************************/

#include<iostream>
#include<list>
using namespace std;

void show(const list<int>coll){

    for(auto a = coll.begin() ; a!=coll.end(); a++){
        cout<<(*a)<<endl;

    }
}

bool compare(const int x ,const int y){

    return x>y ;
}
int main(){
    
    list<int>coll ;
    coll.push_back(10);
    coll.push_back(11);
    coll.push_front(15);
    coll.push_back(12);
    coll.sort();
    cout<<"+++++++++++++++++++++++++++"<<endl ;
    show(coll);
    coll.sort(compare);
    cout<<"----------------------------"<<endl ;
    show(coll);
}
