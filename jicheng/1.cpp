/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 28 Oct 2018 03:49:33 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

class Animal{

public :
    int age ;
    int weight;
    Animal();
    ~Animal();
    void setAge(int ages);
    int getAge();

};

class Cat :public Animal{

private:
    string color ;
    int weight;
public:
    Cat();
    ~Cat();
    
    void setColor(string colors);
    string  getColor();
    void setWeight(int weights);
    int getWeight();
};

class Dog :public Animal{



public :
    int weight ;

    Dog();
    ~Dog();
    void setWeight(int wieghts);
    int getWeight();
};

Animal::Animal(){   
}
Animal::~Animal(){

}
Dog::Dog(){
    cout<<"Dog distructing"<<endl ;
}
Dog::~Dog(){

}
Cat::Cat(){
    cout<<"Cat distructing"<<endl ;
}
Cat::~Cat(){
    cout<<"Dog "<<endl ;
}
int Animal::getAge(){

    return age ;
}

void Animal::setAge(int ages){
    age = ages;
}
/*
int Dog::getAge(){
    
    return age ;
}

void Dog ::setAge(int ages){

    age = ages ;
}
int  Cat::getAge(){

    return age  ;

}
void Cat::setAge(int ages){
    age = ages;
}
*/
int Cat:: getWeight(){
    
    return weight ;
}

void Cat :: setWeight(int weights){

    weight = weights ;
}
void Dog ::setWeight(int weights){
    
    weight = weights ;
    
}
int main(){
    
    Cat c = Cat();
    Dog d = Dog();
    c.setAge(8);
    d.setAge(9);
    c.setWeight(21);
    d.setWeight(90);
}
