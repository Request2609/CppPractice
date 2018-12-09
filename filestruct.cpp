/*************************************************************************
	> File Name: filestruct.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 18 Nov 2018 11:23:15 PM PST
 ************************************************************************/

#include<iostream>
#include<fstream>
using namespace std;
class kkk{
public:
    int a ;
    string name ;
public:
    kkk():a(0),name(NULL){}
    kkk(int a,string name){
        (*this).a = a ;
        (*this).name = name ;
    }
    ~kkk(){}
    void print(){
        cout<<"-----------"<<a<<"---------"<<endl;
    }
};

int main(){
    
    ofstream out("data.txt");
    kkk ks(10,"changke");
    out.put(ks.name[0]);
    out.close();
    ifstream infile("data.txt");
    kkk cc ;
    char ch;
    while(infile){
        infile.get(ch);
        cout<<ch<<endl ;
    }
}
