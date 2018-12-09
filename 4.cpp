/*************************************************************************
	> File Name: 4.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 18 Nov 2018 11:06:13 PM PST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<iostream>
#include<fstream> 
using namespace std;
int main(){
	 
	/*ofstream out("file") ;
	
	char buf[10];
	out.write("Hello Linux!");
	out.close();
	ifstream in("file");
	while(in.read(buf,10)){
		cout<<buf<<endl;
	}
	in.close();*/
    ofstream outfile("data.txt");
    int i =0 ;
    for(i = 0 ;i< 10 ;i++){
        cout<<i<<" ";
        cout<<"ok,press a key"<<endl ;
        getchar();
    }
    int data ;
    ifstream infile("data.txt");
    for(i = 0;i< 10 ;i++){
        infile>>data;
        cout<<data<<" ";
    }
	return 1;
}
