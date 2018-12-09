#include<iostream>
using namespace std ;
class array{
public:
    array(int length);
    array(const array &obj){}
    ~array();
private:
    int length ;
    int * m_space ;

public:
    void setData(int value);
    void getData(int index);
    int length();
public:
    operator[](int i);
};

void setData(int index ,int value){
    m_space[index]= value ;
}


array::array(const array&obj){
    int i ;
    array ob(length) ;
    for(i =0 ;i< length ;i++){
        ob[i] = obj[i] ;
    }
    delete obj ;
    return ob ;
}

void getData(int data){
    return m_space[data];
}
int length(){
    return m_length ;
}
int& array::operator[](int i){
    return m_space[i];
}

array::array(int length){
    (*this).length =length ; 
}

int  main(){

    array arr(10) ;
    int i= 0 ;
    for(i =0 ;i< arr.length() ;i++){
        arr[i]=i ;
    }
    for(i =0 ; i< arr.length() ;i++){
        cout<<arr[i]<<endl ;
    }
}