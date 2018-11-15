/*************************************************************************
	> File Name: typevector.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 03 Nov 2018 08:17:04 PM PDT
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class ID{

public  :
    string name ;
    int score ;
public:
    ID():name(""),score(0){}
    ID(string sname ,int s):name(sname),score(s){}
    ~ID() {}
};

bool operator==(const ID&x ,const ID&y){
   return (x.name == y.name )&&(x.score == y.score);
}

bool operator<(const ID & x ,const ID &y){
    return x.score< y.score ;
}

bool compare(const ID &x,const ID &y){
    return x.score >y.score;
}
int main(){

    vector<ID>a ;
    a.push_back(ID("tom",30));
    a.push_back(ID("hello",10));
    a.push_back(ID("nunu",19));
    for(auto b = a.begin();b!= a.end();b++){
        
        cout<<(*b).name<<"   "<<(*b).score<<endl;
    }
    sort(a.begin(),a.end());
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++"<<endl ;
    for(auto b = a.begin();b!= a.end();b++){
        
        cout<<(*b).name<<"   "<<(*b).score<<endl;
    }
    sort(a.begin(),a.end(),compare);
    cout<<"----------------------------------------------"<<endl ;
    for(auto b = a.begin();b!= a.end();b++){
        
        cout<<(*b).name<<"   "<<(*b).score<<endl;
    }

    cout<<"=============================================="<<endl;
    
}
