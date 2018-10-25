/*************************************************************************
	> File Name: 10.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 20 Oct 2018 06:24:33 AM PDT
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

class Person{

private:
    char addr[100] ;
    char name[100];
public: 
    Person(const char* name1 ,const char* addr1){
    
        strcpy(name,name1);
        strcpy(addr,addr1);
    }
    void getinfo(){
        printf("%-10s%-10s",name,addr);
    }

};
int main(){
    
    char  name[100];
    char addr[100];
    cout<<"Input name:"<<endl;
    scanf("%[^\n]",name);
    getchar();
    cout<<"Input addr:"<<endl ;
    scanf("%[^\n]",addr);
    Person p(name,addr) ;
    p.getinfo();   
    cout<<endl;
}
