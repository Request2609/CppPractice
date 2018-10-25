/*************************************************************************
	> File Name: 222.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 14 Oct 2018 07:20:36 AM PDT
 ************************************************************************/
#include<vector>
#include<iostream>
using namespace std;
int main(){

    int i ;
    vector<int>j ;
    int d ;
    cout<<"input data(-1 to end):"<<endl;
    for(i = 0 ; ;i++){

        cin>>d ;
        if(d== -1)break ;
        j.push_back(d);
    }
    int k ;
    cout<<"Print all num which lin:"<< endl ;
    for(k = 0 ; k< i-1 ;k++){

        cout<<j[k]+j[k+1]<<endl ;
    }
    cout<<"Print all num which ge:"<<endl ;
    int m = i/2 ;
    for( k =  0;k < m  ;k++){
        
        cout<<j[k]+j[i-k-1]<< endl;
    }
    if(i%2!=0){

        cout<< j[m]<<endl;
    }
    return 0;
}
