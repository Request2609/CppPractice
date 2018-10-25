/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 13 Oct 2018 11:20:26 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

namespace one{
    
    int one =1;
}
namespace two{

    int one;
}

int main(){

    using namespace one ;
    int one ;
    one = 90 ;

    cout<<"hello world!"<<endl ;
    cout<<"the namespace is "<<one<<endl ;
    two:: one = 5 ;
    cout<< "thee name is "<<two::one<<endl ;
}
