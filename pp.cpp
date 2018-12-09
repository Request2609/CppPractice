/*************************************************************************
	> File Name: pp.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 18 Nov 2018 11:38:28 PM PST
 ************************************************************************/

#include<iostream>
#include<fstream>
using namespace std;
int main(){
    
    ofstream outfile("data.txt");
    outfile<<"use your n=vote\n";
    outfile<<"use your weise\n";
    outfile.close();
    char buffer[80];
    ifstream infile("data.txt");
    while(infile){

        infile.getline(buffer,80);
        cout<<buffer<<endl;
    }
    infile.close();
}
