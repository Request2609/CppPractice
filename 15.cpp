/*************************************************************************
	> File Name: 15.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 17 Oct 2018 01:39:38 AM PDT
 ************************************************************************/

#include<iostream>
#include<stdlib.h>

using namespace std;

class Test{

    public :
          Test():age(0)//init cheng yuan bian liang
            {
            
            cout<<"Test    "<<"age:"<<age<<endl ;
        }
    ~Test(){

        cout<<"end of the Test"<<endl;
    }
    private:
        int age ;
};

int main(){

    {
        Test a ;

    }
    Test* b = new Test();
    delete  b;
    b = NULL ;
    int * p = (int *)malloc(sizeof(int));
    free(p);
    p = NULL ;
    return 0 ;
}
