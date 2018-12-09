#include"Mystring.h"
// #include<string>
using namespace std;
int main(){

    mystring s = "changke";
    mystring ss ="liuchangke";
    cout<<"s=="<<s<<endl;
    cout<<"ss = "<<ss<<endl;
    if(s!=ss){
        cout<<"s!=ss"<<endl ;
    }
    else{
        cout<<"s==ss"<<endl ;
    }
    s = ss ;
    cout<<"s = "<<s<<endl ;
    cout<<"s[1] = "<<s[1]<<endl ;
    cin>>ss ;
    cout<<ss<<endl ;
}