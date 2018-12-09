#include"string.h"
int main(){
    
    mystring s ;
    s="changke";
    cout<<s<<endl;
    if(s>"liang"){
        cout<<s;
        cout<<">"<<"liang"<<endl;
    }
    else{
        cout<<s<<"<"<<"liang"<<endl;
    }
    cout<<s<<endl ;
    cin>>s;
    cout<<"s:"<<s<<endl;
}