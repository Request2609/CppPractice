/*************************************************************************
	> File Name: 129.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 25 Oct 2018 01:08:03 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

class sale{

public:
    int units_sold ;
    sale();
    ~sale();
    void setUnitSold();
    sale& getUnitSold();
};

sale::sale(){
    
    cout<<"A object has been build!"<<endl ;
}

sale::~sale(){

    cout<<"A object has been destroy!"<<endl ;
}
void sale::setUnitSold(){
    
    cout<<"Input unit sold money:"<<endl ;
    cin>>units_sold ;
    cout<<"All of sold money is  "<<units_sold<<endl ;
}

sale &sale::getUnitSold(){
    
    units_sold += 10 ;
    return *this ;

}

int main(){

    sale s = sale();
    s.setUnitSold();
    s =s.getUnitSold();
    cout<<"The return money is  "<<s.units_sold<<endl;
}


