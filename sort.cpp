/*************************************************************************
	> File Name: sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 03 Nov 2018 08:05:50 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int a ,int b){

    return a>b ;

}
int main(){
    
    vector<int>a ;
    int data ;
    while(cin>>data){
        if(data == -1)break ;
        a.push_back(data);
    }
    for(auto n = a.begin() ;n!=a.end();n++){
        cout<<*n<<endl;
    }
    sort(a.begin(),a.end());
    cout<<"sorted information"<<endl ;
    for(auto s = a.begin() ;s!=a.end();s++){
        cout<<*s<<endl;
    }
    sort(a.begin() ,a.end(),compare);
    cout<<"----------------------------------"<<endl ;
    for(auto h = a.begin() ;h!=a.end();h++){
        cout<<*h<<endl;
    }
}
