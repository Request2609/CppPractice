/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 14 Oct 2018 12:53:43 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){

    int cur ;
    int val ,num;
    while(cin >> cur){
        
        num = 1 ;
        while(cin >>val){

            if(val == cur){

                num ++ ;
            }
            else{
                cout<<cur<<"   occurrs   "<<num<<"   times"<<endl ;
                num = 1 ;
                cur = val;
            }
    cout<<cur<<"   occurs   "<< num<<"   times"<<endl ;
        }
    }
}
