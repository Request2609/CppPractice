/*************************************************************************
	> File Name: 17.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 17 Oct 2018 07:03:57 AM PDT
 ************************************************************************/
#include<string.h>
#include<iostream>
using namespace std;
#define  N 40
class Student{
public :
    Student(char* pname,int pid);
    ~Student();
    Student(Student&s);
    void print();
    
private:
        
    int id ;
    char name[N] ;
    
};

void Student :: print(){

    printf("name = %s",name) ; 
}

Student::Student(char*pname ,int pid):id(pid)
{

    strcpy(name,pname);
    id = pid ;
    printf("%s",name);

}

Student::Student(Student&s){
    
    strcpy(name,s.name);
    strcat(name ,"copy");
    id = s.id ;
    cout<<"copy the object!"<<endl;
    printf("%s",name);
}

Student :: ~Student(){
    
    cout<< "Stuent destroy"<<endl ;
}


int main(){
   
    int i =10 ;
    Student s("xiaoming",i);
    s.print();
    
    Student l = s ;
                        
}
