/*************************************************************************
	> File Name: 555.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 14 Oct 2018 11:33:22 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
class Car{

private:
    double price ;
    string color ;
public:
    Car();
    void introduce();
    void run();
    void stop();
};

Car::Car(){
    
    cout<< "Input price:"<<"";
    cin>>price ;
    getchar();
    cout<< "Input color:"<<"";
    getline(cin,color);
}

void Car::introduce(){
        
    cout<< "The color is"<<color<<endl ;
    cout<<"The price is "<<price<<endl;
}

void Car :: run(){

    cout<< " The car is running"<<endl ;
}

void Car :: stop(){
    
    cout<<"The car stopped!"<<endl ;
}

int main(){
    
    Car car ;
    car.introduce();
    car.run();
    car.stop();
}
