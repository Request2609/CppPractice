/*************************************************************************
	> File Name: kmp.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 15 Nov 2018 05:56:39 AM PST
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;
void getnext(char* str){

    int i = 0;
    int j = 1;
    int next[100];
    cout<<str<<endl;
    bzero(next,sizeof(next));
    int len = strlen(str);
    next[1]=0;
    while(j<len){
        if(i==0||str[i]==str[j]){
            
            ++i ;
            ++j ;
            next[j]= i ;
        }
        else
        i =  next[i];
    }
    int a ;
    for(a= 0 ; a<20 ;a++){
        cout<<next[a];
    }
}
int main(){

    char str[100];
    cin>>str ;
    getnext(str);
}


