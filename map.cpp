/*************************************************************************
	> File Name: map.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 03 Nov 2018 09:05:35 PM PDT
 ************************************************************************/

#include<iostream>
#include<string>
#include<map>

class compare{

public:
    bool operator()(int a, int b){
        return a> b ;
    }
};
using namespace std;


void show(const map<int ,string,compare>coll){

    for(auto a = coll.begin() ; a!= coll.end() ; a++){
        
        cout<<a->first<<"   "<<a->second<<endl;
    }
}

int main(){
    
    map<int,string,compare>coll ;
    //the first method 
    coll.insert(pair<int,string>(1,"chang"));
    //the second method
    coll.insert(map<int ,string>::value_type(4,"ane"));   
    coll.insert(make_pair(2,"two"));
    show(coll);
}
