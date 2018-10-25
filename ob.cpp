/*************************************************************************
	> File Name: ob.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 14 Oct 2018 10:33:18 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

class Car{

private:
    string color ;
    string type ;
    double price ;
    string makercountry;
    string owner ;
public:
    Car(){

        cout<< "Input car color:"<<endl ;
        getline(cin,color);
        cout<< "Input car type:"<<endl ;
        getline(cin, type) ;
        cout<< "Input car makercountry:"<<endl ;
        getline(cin,makercountry);
        cout<<"input car price:"<< endl ;
        cin>> price;
        cout<< "Input owner name:"<<endl ;
        getline(cin,owner);
    }
    
    void introduce(){

        cout<< "color:"<<color<<endl ;
        cout<<"type:"<<type<<endl ;
        cout<<"from country:"<<makercountry<<endl ;
        cout<<"price:"<<price<< endl;
        cout<<"owner :"<<owner<<endl ;

    }

    void run(){
        
        cout<<"the car is running!\n"<<endl ;
    }

    void stop(){
        
        cout<<"the car stop"<<endl ;
    }


};

int main(){

    Car car ;
    car.introduce();
    car.run() ;
    car.stop();
}
