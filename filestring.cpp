/*************************************************************************
	> File Name: filestring.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 18 Nov 2018 11:12:24 PM PST
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main(){
    
    char str[] = "hello this is a c++ program";
    ofstream outfile("data.txt");
    int i = 0;
    for(i = 0 ; i< strlen(str);i++){
        cout<<"ddd"<<endl;
        outfile.put(str[i]);
    }
    outfile.close();
    char ch ;
    ifstream infile("data.txt");
    while(infile){
        cout<<ch<<endl;
        infile.get(ch);
        cout<<ch<<endl;
    }
}
