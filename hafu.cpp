/*************************************************************************
	> File Name: hafu.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 19 Nov 2018 01:11:47 AM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAX 6
//template <typename T>
/*
T vector::operator[](int i){
    return *this[i];
}*/
typedef struct node{
    
    char ch ;
    int num ;
    int l,r,p;
}node_t ,*node_l;
void process(vector<node_t>list);
void getChild(vector<node_t>list,int&s1,int&s2);
int main(){
    
    int len = 2*MAX-1;
    vector<node_t>list ;
    bzero(&list,sizeof(list));
    
    int num, i;
    for(i = 0 ;i < MAX;i++){
        list[i].ch = 'A'+i;
    }
    for(i = 0;i < MAX ;i++){
        scanf("%d",&list[i].num);
    }
    process(list);
}
void process(vector<node_t>list){
    int  j = 0;
    int s1 =-1 ;
    int s2 = -1;
    int len = list.size();
    while(1){
        if(getChild(list,s1,s2,len)==2){
            
        }
        else if(getChild(list,s1,s2)==1){

        }
        else{
            break;
        }
        s1=-1;
        s2=-1;
    }
}

void getChild(vector<node_t>list,int&s1,int &s2,int len){
    
    int  i =0 ,min=0;
    int flag = 0;
    for(j =0 ;j< 2;j++){
      for(i = 1 ;i < 2;i++){
        if(flag==0&&list[i].num >= list[i-1].num){
            flag = 1 ;
            min = i-1;
        }
        if(flag==0&&list[i].num<=list[i-1].num){
            flag = 0 ;
            min = i-1 ;
        }
        if(flag == 1&&min< list[i].num){
              min =list[i].num ;
          }
        }
        if(j ==0){
            s1= min ;
            list[]
        }
        if(j == 1)s2= min ;
    }
}

