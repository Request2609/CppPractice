/*************************************************************************
	> File Name: 13.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 16 Oct 2018 05:33:05 AM PDT
 ************************************************************************/
#include<unistd.h>
#include<iostream>
#include<vector>
using namespace std;
int main(){

    int i ,j;
    vector<int>a ;
    cout<<"Input the number you want to sort(0 break):"<<endl ;
    while(1){
               
        cin>>i ;
        if(i == 0)break ;
        a.push_back(i) ;
    }

    for(auto j = 0 ; j < a.size() ; j++ ){
        int flag = 0 ;
        for(i = 1 ; i < a.size() ;i++){
            
            if(a[i-1] > a[i]){
                
                flag = 1 ;
                a[i-1] = a[i]+a[i-1] ;
                a[i] = a[i-1] -a[i] ;
                a[i-1] = a[i-1]-a[i] ;
            }
        }
        if(flag = 0)break ;
    }
    for(j = 0;j< a.size();j++){

        cout<<a[j]<<endl;
    }
    auto b = a.begin(),e = a.begin();
    auto mid = b+ (e-b)/2 ;
    int sought;
    cout<<endl ;
    cout<<"Input which you want to research:"<<endl ;
    cin>>sought;
    cout<<sought<<endl ;
    int flag = 1 ;
    while(1){
        cout<< *mid<<endl;
        if(*mid == sought|| mid == e)break ;
        flag ++ ;
        if(*(mid) > sought){
            e = mid;
        }
        else{
            
            b = mid+1;
        cout<<*b<<endl;
        }
        sleep(1);

        mid = b+(e-b)/2 ;
    }
    
    cout<< flag <<endl;
}
