/*************************************************************************
	> File Name: moban.c
	> Author: 
	> Mail: 
	> Created Time: Fri 02 Nov 2018 07:53:07 AM PDT
 ************************************************************************/
#include<iostream>
using namespace std ;
template <typename T>
class Test{
               
    public :
        Test(T val):m_val(val){
        }
        ~Test(){}
        void set(T value){
            m_val = value ;
        }
        T get()const{
            return m_val;
        }
    private:
        T m_val ;
};

int main(){
    
    Test<int>a(1);
    a.set(10);
    int data = a.get();
    cout<<data<<endl;
    return  0 ;
}
