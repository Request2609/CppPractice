/*************************************************************************
	> File Name: file.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 18 Nov 2018 10:39:15 PM PST
 ************************************************************************/

#include<iostream>
#include<fstream>
using namespace std;

class aa{

public:
    int a ;
    string name;
    aa():a(0),name(NULL){}
    aa(int a ,string name){
        (*this).a = a ;
        (*this).name = name ;
    }
    ~aa(){}
    void print(){

        cout<<a<<"      "<<name<<endl ;
    }
};
int main(){

    aa ex(6,"changke");
    ofstream outfile("test1",ios::out|ios::binary);
    if(!outfile){
        cout<<"cannot open file!"<<endl ;
        return 1 ;
    }
    outfile.write((char*)&ex,sizeof(ex));
    outfile.close();
    ifstream in("test1",ios::in|ios::binary);
    if(!in){
        cout<<"cannot open file!"<<endl ;
        return 1 ;
    }

    in.read((char*)&ex ,sizeof(ex));
    cout<<ex.name<<"        "<<ex.a<<endl;
    ex.print();

}
