/*************************************************************************
	> File Name: func.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 03 Nov 2018 09:13:04 PM PDT
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Compare{

public:
    bool operator()(int a,int b ){
        return a > b ;
    }
};
int main(){
    
    Compare com ;
    bool val = com(1,4);
    cout<<val<<endl;

}
