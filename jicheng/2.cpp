/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 28 Oct 2018 07:14:51 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
class Animal{

public :
    Animal(){};
    void eat(){
        cout<<"hello private"<<endl ;
    }

};

class Duck:private Animal{

public :
    Duck();
    ~Duck();
    void strechNeck(){

        cout<<"hello Duck!"<<endl;
    }
};

Duck::Duck(){
    

}
Duck::~Duck(){


}
int main(){
    
    Duck d = Duck();
    d.strechNeck();
   // d.eat();
}
