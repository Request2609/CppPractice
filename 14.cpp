/*************************************************************************
	> File Name: 14.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 16 Oct 2018 06:34:25 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){

    int a[5][5];
    int cnt = 0 ;
    for(auto &row : a){

        for(auto &col : row){

            col = cnt ;
            ++cnt ;
        }
    }
    
    int i,j ;
    for(i = 0 ;i < 5 ;i++){
        cout<<endl ;
       for(j = 0 ;j< 5 ;j++){
            cout<< a[i][j]<<endl ;
        }
    }
}
