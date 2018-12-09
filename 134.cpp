/*************************************************************************
	> File Name: 134.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 26 Nov 2018 10:14:02 PM PST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    char arr[100];
    char ch = 'A';
    int i ;
    for(i = 0 ; i < 26; i++){
       // ch = ch+i;
        printf("%c",ch+9);
        break;
        arr[i]= ch;
    }
    printf("%s",arr);
    
}
