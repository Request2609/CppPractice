/*************************************************************************
	> File Name: smartpointer.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 22 Nov 2018 05:22:43 AM PST
 ************************************************************************/

#include<iostream>
#include<memory>
using namespace std;
//shared_ptr
//unique_pointer //the unique pointer
//weak_pointer//he shared pointer yi qi shi yong

class objects{

public:
    objects(int id):m_id(id){cout<<"init obj"<<endl ;}
    ~objects(){
        cout<<"bye bye"<<m_id<<endl ;
    }
    int id()const{return m_id;}
private:
    int m_id ;
};
static void interfaceOfSharedPtr();

void print(){

    ObjectPtr NULL ;

}
