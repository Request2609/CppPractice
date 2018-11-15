/*************************************************************************
	> File Name: vector.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 03 Nov 2018 07:38:22 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    
    vector<int>a ;
    int i ;
    while(cin>>i){

        if(i == -1)break;
        a.push_back(i);
        
    }
    int j = 0 ;
    while(j < a.size()){
        cout<<a[j]<<endl;
        j++;
    }
    
    cout<<"iterator all is here......"<<endl;
    auto iter = a.begin();
    while(iter != a.end()){
        cout<<*iter<<endl;
        iter++ ;
    }
}
