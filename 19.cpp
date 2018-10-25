/*************************************************************************
	> File Name: 19.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 20 Oct 2018 05:27:58 AM PDT
 ************************************************************************/
#include<vector>
#include<iostream>
using namespace std;
int jian(int,int );
int cheng(int,int );
int chu(int,int);
int jia(int  ,int );
int main(){
    
    int(*p)(int ,int);
    vector<decltype(p)>s ;
    p = jia ;
    s.push_back(p);
    p = jian;
    s.push_back(p);
    p = cheng ;
    s.push_back(p);
    p = chu;
    s.push_back(p);
    int i ;
    i = (*s[0])(1,2);
    cout<<i<<"   ";
    int j = (*s[1])(2,4);
    cout<<j<<"   "; 
    int k = (*s[2])(4,3);
    cout<<k<<"   ";
    int l = (*s[3])(6,7);
    cout<<l<<endl;
}

int jia(int s,int k){
    return s+k ;
}
int cheng(int s,int k){
    return  s*k ;
}
int chu(int s,int k ){
    return s/k;
}
int jian(int s,int k){
    return s-k ;

}
