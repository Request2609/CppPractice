/*************************************************************************
	> File Name: deleteModi.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 18 Nov 2018 11:46:16 PM PST
 ************************************************************************/

#include<iostream>
#include<fstream>
using namespace std;
int main(){

    int n[5] = {1,2,3,4,5};
    register int i ;

    ofstream out("test",ios::out|ios::binary);
    if(!out){
        cout<<"Cannot open file!\n"<<endl ;
        return 1 ;
    }
    out.write((char*)&n,sizeof(n));
    out.close();
    for(i = 0 ; i< 5;i++){
        n[i]=0 ;
    }
    ifstream in("test",ios::in|ios::binary);
    if(!in){
        cout<<"Cannot open file\n"<<endl ;
        return 1;
    }
    in.read((char*)&n,sizeof n);
    for(i = 0 ;i< 5 ;i++){
        cout<<n[i]<<endl ;
    }
    in.close();
    return 1;
}
