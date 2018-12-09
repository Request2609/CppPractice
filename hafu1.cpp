#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<memory>
#include<string>
#include<vector>
#include<list>
#include<string.h>
#include<array>
using namespace std;
enum {SIZE = 11,MAXLINE = 100};
class data{
public:
    int a ;
    char ch ;
    list<char>s;
};

class hafu:public data{
public:
    
    data da;
    int tag ;

    int l,p,r;
    hafu():tag(0){}
    ~hafu(){}
    static int findmax(int s,int &kl,array<shared_ptr<hafu>,SIZE>&ls);
    static void find(int s,int& kl,int &kr,array<shared_ptr<hafu>,SIZE>&ls);
    static void init(array<shared_ptr<hafu>,SIZE>&ls,int *a);
    static void process(array<shared_ptr<hafu>,SIZE>&ls);
    static void makeCode(array<shared_ptr<hafu>,SIZE>&ls);
    static void reverse(list<char>&s);
    static void printCodes(array<shared_ptr<hafu>,SIZE>&ls);
    static void request(const array<shared_ptr<hafu>,SIZE>&ls,char *arr);
    static void printlist( list<char>&s);
    static void transform(const array<shared_ptr<hafu>,SIZE>&ls,char *s);
    static int search(list<char>&s ,char* arr,int i);
};

int hafu::search(list<char>&s,char *arr,int i){

        list<char>::iterator iter ;
        int k = 0 ;

        for(k = 0 ;k < strlen(arr);k++ ){
            if(arr[k]!='#')break ;
        }
        
        int m = k ;
        int count = 0 ;
        for(iter = s.begin();iter!=s.end();iter++){
                if(*iter == arr[k]){
                    count ++ ;
                    k++ ;
                }
                else{
                    return 0;
                }
        }

            int len = s.size();
            int kk = m;
            for(k = 0 ;k< len ;k++){
                kk = m+k;
                arr[kk] ='#';
            }
            return 1 ;
}

void hafu::transform(const array<shared_ptr<hafu>,SIZE>&ls,char *s){
    
    int i = 0,j ;
    int len = strlen(s);
    for(i =0 ;i< (SIZE+1)/2;i++){
        i = j ;
        if(s[strlen(s)-1]=='#'){
            break;

        }
        if(search(ls[i]->da.s,s,i)){
                cout<<ls[i]->da.ch<<"";
                j = 0 ;
                if(i == (SIZE+1)/2-1){
                    i = 0;
                }
            }
        else{
                j++ ;
            }
        }
}

void hafu::printlist( list<char>&s){
     list<char>::iterator iter ;
     for(iter=s.begin();iter!=s.end() ;iter++){
                cout<<*iter<<"";
    }
}

void hafu::request(const array<shared_ptr<hafu>,SIZE>&ls,char *arr){

    int len = strlen(arr);
    int i ,j;
    int flag = 0 ;
    for(i = 0 ;i< len ;i++){
        for(j = 0 ;j<(SIZE+1)/2;j++){
            if(ls[j]->da.ch == arr[i]){
                printlist(ls[j]->da.s);
                flag =1 ;
            }
        }
        if(flag==0)return ;
    }
    cout<<endl ;
}

void hafu::printCodes(array<shared_ptr<hafu>,SIZE>&ls){
    
    int  i =  0;
    for(i = 0 ; i < (SIZE+1)/2 ;i++){
        list<char>::iterator iter ;
        cout<<ls[i]->da.ch<<":";
        for(iter = ls[i]->da.s.begin() ; iter!=ls[i]->da.s.end();iter++){
            cout<<*iter<<"";
        }
        cout<<endl ;
    }
    
}

void hafu:: reverse(list<char>&s){

    int i ;
    s.reverse();
}

void hafu::makeCode(array<shared_ptr<hafu>,SIZE>&ls){
    int  i  =  0 ;
    int j = 0;
    for(j = 0 ;j < (SIZE+1)/2;j++){
        int index = ls[j]->p;
         int k = j ;
         while(index){
          
            if(ls[index]->l == k){
               
                ls[j]->da.s.push_back('0');
            }
            if(ls[index]->r == k){
               
                ls[j]->da.s.push_back('1');
            }
            k = index ;
            index = ls[index]->p;
        }
        reverse(ls[j]->da.s);
    }
    printCodes(ls);
    
}

int hafu::findmax(int s,int &kl,array<shared_ptr<hafu>,SIZE>&ls){

        int i ,j;
        int temp ;
        kl = -1 ;
        int count = 0; 
        for(i = 0;i < s ;i++){
            if(kl< ls[i]->da.a && ls[i]->tag != 1){
                    kl = i;    
            }
            if(ls[i]->tag == 0)count++ ;
        }
}

void hafu::find(int s,int& kl,int &kr,array<shared_ptr<hafu>,SIZE>&ls){

    int i= 0, j = 0 ;
    int count ;
    count = findmax(s,kl,ls);
    if(count==1){
        kr = -1 ;
        return ;
    }
    
    int mins =ls[kl]->da.a+10;
    
    for(i = 0 ;i < 2 ;i++){
        int min = mins ;
        for(j = 0 ; j < s ; j++){
            
            if(i==0&&ls[j]->da.a < min&&ls[j]->tag == 0){

                   min = ls[j]->da.a ;
                   kl = j ;
            }

            if(i==1&&ls[j]->da.a < min&& ls[j]->tag==0){
                min = ls[j]->da.a ;
                kr = j;
            }
        }
        if(i == 0)ls[kl]->tag = 1 ;
        if(i == 1){
            ls[kr]->tag = 1 ;
            break ;
        }
    }
}

void hafu::process(array<shared_ptr<hafu>,SIZE>&ls){

    int  j = (SIZE+1)/2;
    int i ;
    int kl=-1,kr=-1 ;
    for(i =j ;i< SIZE;i++){
        find(i,kl,kr,ls);
        if(kr == -1)break ;
        ls[i]->da.a = ls[kr]->da.a + ls[kl]->da.a ;
        ls[i]->l = kl ;
        ls[i]->r = kr ;
        ls[kl]->p = i ;
        ls[kr]->p = i ;
    }
}

void hafu::init(array<shared_ptr<hafu>,SIZE>&ls,int *a){
    int j = 0 ;
    
    for(j = 0;j < SIZE;j++){
      shared_ptr<hafu>p(new hafu);
      if(j<6)p->da.a = a[j] ;
      ls[j] = p ;
    }

    int i = 0;
    char ch;
    char arr[6] = {'A','B','C','D','E','F'};
        
    for(i = 0 ;i< (SIZE+1)/2;i++){
        ls[i]->da.ch=arr[i];
    }
    i = 0 ;
    while(1){
        if(i == SIZE){
            break ;
        }
        ls[i]->l = 0;
        ls[i]->r = 0;
        ls[i]->p = 0;
        if(i >= (SIZE+1)/2){
            ls[i]->da.ch = '\0';
            ls[i]->da.a = 0;
            i++ ;
            continue ;
        }
        i++ ;
    }
}

int main(){


    array<shared_ptr<hafu>,SIZE>arr ;
    char ss[MAXLINE];
    char s[MAXLINE];
    int sss[MAXLINE];
    int i ;
    for(i = 0 ;i< (SIZE+1)/2;i++){
        cin>>sss[i];
    }
    cin>>ss ;
    cin>>s ;
    hafu::init(arr,sss); 
    hafu::process(arr);
    hafu::makeCode(arr);
    hafu::request(arr,ss);
    hafu::transform(arr,s);
    cout<<endl;
}
