/*************************************************************************
	> File Name: test3.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 19 Nov 2018 12:09:16 AM PST
 ************************************************************************/

#include<iostream>
#include<fstream>
using namespace std;
class test{

private:
    int  a ;
    string name ;
public:
    test():a(0),name("changke"){}

    test(int as ,string names):a(as),name(names){}
    ~test();
    void print(){}
};
int main(){
    
    test tt(10,"hello linux group!");
    ofstream outfile("test2");
    if(!outfile){
        cout<<"error!"<<endl ;
        return 1 ;
    }
    outfile.write((char*)&tt,sizeof(tt));
    outfile.close();
    ifstream in("test2",ios::in|ios::binary);
    if(!in){
        
        cout<<"error!"<<endl;
        return 1;
    }
    test ttt;
    in.read((char*)&ttt,sizeof(tt));
    
    in.close();
    cout<<ttt.a<<"    "<<ttt.name<<endl;
    return 1 ;
}
