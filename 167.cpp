/*************************************************************************
	> File Name: 167.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 22 Oct 2018 09:57:16 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

class Animal{
    
protected:
    string type ;
    string eatWhat ;
public:
    void printInfo();
};

class Cat:public Animal{
private:
    int age  ;
    string name ;
public :
    Cat();
    ~Cat();
    void setCat();
    void getCat();
};
/*
void Cat::printInfo();
Cat::Cat();
Cat::~Cat();
*/

void Animal::printInfo(){

    cout<<"Animal infomation"<<endl ;
}

Cat::Cat(){
    
    cout<<"The member has been chuangjian"<<endl ;
       
}

Cat::~Cat(){

    cout<<"The member has been destroy!"<<endl ;
}

void Cat::setCat(){
    
    cout<<"Input cat type"<<endl ;
    getline(cin,type);
    cout<<"Input cat eatwhat"<<endl ;
    getline(cin,eatWhat);
    cout<<"Input cat age"<<endl ;
    cin>>age ;
    getchar();
    cout<<"Input cat name"<<endl ;
    getline(cin,name);
}

void Cat::getCat(){
    
    cout<<"The cat informatiion is here!"<<endl ;
    cout<<"type:"<<type<<endl ;
    cout<<"eatWhat:"<<eatWhat<<endl ;
    cout<<"age:"<<age<<endl ;
    cout<<"name:"<<name<<endl ;

}
int main(){
    
    Cat cat ;
    cat.printInfo();
    cat.setCat() ;
    cat.getCat() ;
}
