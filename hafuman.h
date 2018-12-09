#ifndef _HAFU_H_
#define _HAFU_H_
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<memory>
#include<vector>
#include<list>
#include<string.h>
using namespace std;
enum {SIZE = 107,MAXLINE = 1000,MAX = 200};
class chars{
public:
    int a ;
    char ch;
public:
    chars():a(0),ch('\0'){}
};

class record : public chars{
public:
    chars cc ;
    int len ;
    static int calcu ;
    static void initarr(array<shared_ptr<record>,MAXLINE>&ls);   
    static void input(const char *line,array<shared_ptr<record>,MAXLINE>&ss);
    static void arraysort(array<shared_ptr<record>,MAXLINE>&ss);
    static void countchars(const char* arr,const char*zimu,array<shared_ptr<record>,MAXLINE>&ls);
    static void Cout(array<shared_ptr<record>,MAXLINE>&ls,int len );
    static void swap(shared_ptr<record>&p1,shared_ptr<record>&p2);
};

int record::calcu =0 ;
void record::Cout(array<shared_ptr<record>,MAXLINE>&ls,int len){

    int  i = 0 ;
    for(i = 0 ; i < len ; i++){
        cout<<ls[i]->cc.ch<<"     "<<ls[i]->cc.a<<endl ;
    }
}

void record::swap(shared_ptr<record>&p1,shared_ptr<record>&p2){
    shared_ptr<record>p(new record) ;
    p->cc.a = p1->cc.a;
    p->cc.ch = p1->cc.ch;
    p1->cc.a = p2->cc.a;
    p1->cc.ch = p2->cc.ch;
    p2->cc.a= p->cc.a;
    p2->cc.ch= p->cc.ch;
}

void record::arraysort(array<shared_ptr<record>,MAXLINE>&ss){
    
    int num = ss[0]->calcu ;
    int a ;
    int i,j = 0;
    shared_ptr<record>p(new record);
    for(i = 0 ; i< num ; i++){
        int flag = 0 ;
        for(j = 1 ; j <= num-i-1; j++){
       /*     cout<<ss[j-1]->cc.ch<<endl;
           if(ss[j-1]->cc.ch == '.'){
                swap(ss[j-1],ss[j]);
                continue ;
            }*/
            if(ss[j-1]->cc.ch > ss[j]->cc.ch){
                flag =1 ;
                swap(ss[j-1],ss[j]);
                }
            }
        if(flag ==0){
            break ;
        }
        }/*
         for(i = 0 ;i <  2; i++ ){
             for(j = 1 ;j < num ;j++){
                 if(i==0&&ss[j-1]->cc.ch == ' '){
                     swap(ss[j-1],ss[j]);
                     continue ;
                 }
                 if(i==1&&ss[j-1]->cc.ch == '.'){
                     swap(ss[j-1],ss[j]);
                     continue ;
                    
                 }
             }
         }*/
}
void record::input(const char *line, array<shared_ptr<record>,MAXLINE>&ss){
    
    int i = 0 ;
    int j = 0 ;
    int count = 1 ;
    while(line[i]!='#'){
        int flag = 0; 
        for( j = 0 ; j < count ; j++){
                if(ss[j]->cc.a != 0&&ss[j]->cc.ch == line[i]){
                    flag = 1 ;
                    ss[j]->cc.a++ ;
                    break ; 
                }
        }
            
        if(flag == 0){
            ss[count-1]->cc.ch = line[i];
            ss[count-1]->cc.a  = 1 ;
            count++;
        }
        i++ ;
    }
    calcu = count-1 ;
    
    Cout(ss,calcu);
    cin>>i;
    arraysort(ss);
}

void record::initarr(array<shared_ptr<record>,MAXLINE>&ls){
    int i = 0 ;
    for( i = 0 ;i < MAXLINE ;i++ ){
        shared_ptr<record>p(new record);
        p->cc.ch = '#';
        p->cc.a = 0 ;
        ls[i] = p ;           
    }
}

void record::countchars(const char* arr,const char *zimu,array<shared_ptr<record>,MAXLINE>&ss){
    int i = 0 ;
    int j = 0 ; 
    char ch ;
    int k = 0 ;
    for(i = 0 ; i < strlen(arr) ;i++){
           ch = arr[i];
           for(j = 0 ;j < 55 ;j++){
                if(zimu[j] == ch){
                    (ss[i]->a)++;
                }
           }
    }
}
class data{
public: 
    data(){}
    ~data(){}
    int a ;
    char ch ;
    list<char>s;
};

class hafu:public data,public record{
public:
    
    data da;
    int tag ;
    int l,p,r;
    static int counts ;
    hafu():tag(0){}
    ~hafu(){}
    static int findmax(int s,int &kl,array<shared_ptr<hafu>,SIZE>&ls);
    static void find(int s,int& kl,int &kr,array<shared_ptr<hafu>,SIZE>&ls);
    static void init(array<shared_ptr<hafu>,SIZE>&ls,const array<shared_ptr<record>,MAXLINE>&ss);
    static void process(array<shared_ptr<hafu>,SIZE>&ls);
    static void print(const array<shared_ptr<hafu>,SIZE>&ls);
    static void makeCode(array<shared_ptr<hafu>,SIZE>&ls);
    static void reverse(list<char>&s);
    static void printCodes(array<shared_ptr<hafu>,SIZE>&ls);
    static void request(const array<shared_ptr<hafu>,SIZE>&ls);
    static void printlist( list<char>&s);
    static void transform(const array<shared_ptr<hafu>,SIZE>&ls);
    static int search(list<char>&s ,char*arr,int i);
};
int hafu::counts= 0;
int hafu::search(list<char>&s,char* arr,int i){

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

void hafu::transform(const array<shared_ptr<hafu>,SIZE>&ls){
    
    char s[MAXLINE];
    cin>>s;
    int i = 0,j ;
    int num = ls[0]->counts;
    int len = strlen(s);
    for(i =0 ;i< num;i++){
        i = j ;
        if(s[strlen(s)-1]=='#'){
            break;

        }
        if(search(ls[i]->da.s,s,i)){
                cout<<ls[i]->da.ch<<"";
                
                j = 0 ;
                if(i == num-1)i =0;
            }
        else{
                j++ ;
            }
        }
    cout<<endl;
}

void hafu::printlist( list<char>&s){
     list<char>::iterator iter ;
     for(iter=s.begin();iter!=s.end() ;iter++){
              //  cout<<*iter<<"";
    }
    cout<<endl;
}
void hafu::request(const array<shared_ptr<hafu>,SIZE>&ls){

    char arr[MAXLINE];
    int num = ls[0]->counts;
    int len = strlen(arr);
    int i ,j;
    int flag = 0 ;
    for(i = 0 ;i< len ;i++){
        for(j = 0 ;j<num;j++){
            if(ls[j]->da.ch == arr[i]){
                printlist(ls[j]->da.s);
                flag =1 ;
            }
        }
        if(flag==0)return ;
    }
    cout<<endl;
}

void hafu::printCodes(array<shared_ptr<hafu>,SIZE>&ls){
    
    int  i =  0;
    int num = ls[0]->counts;
    for(i = 0 ; i < num ;i++){
        list<char>::iterator iter ;
        cout<<ls[i]->da.ch<<":";
        for(iter = ls[i]->da.s.begin() ; iter!=ls[i]->da.s.end();iter++){
            cout<<*iter<<"";
        }
        cout<<endl;
    }
    
}

void hafu:: reverse(list<char>&s){

    int i ;
    s.reverse();
}

void hafu::makeCode(array<shared_ptr<hafu>,SIZE>&ls){
    int  i  =  0 ;
    int j = 0;
    int num = ls[0]->counts;
    for(j = 0 ;j < num;j++){
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
    cout<<endl;
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
    
    int mins =ls[kl]->da.a+100;
    
    for(i = 0 ;i < 2 ;i++){
        int min = mins ;
        for(j = 0 ; j < s ; j++){
            if(i==0&&ls[j]->da.a < min&&ls[j]->tag == 0){
                    
                   min = ls[j]->da.a ;
                   kl = j ;
            }
            if(i==1&&ls[j]->da.a < min&& ls[j]->tag == 0){
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
void hafu::print(const array<shared_ptr<hafu>,SIZE>&ls){
    int num = ls[0]->counts;
    int i = 0 ;
    for(i =0 ;i < num*2-1;i++){
        cout<<ls[i]->da.ch<<"   "<<ls[i]->da.a<<"   "<<ls[i]->p<<"   "<<ls[i]->l<<"   "<<ls[i]->r<<endl;
    }
}

void hafu::process(array<shared_ptr<hafu>,SIZE>&ls){
    int num = ls[0]->counts;
    int  j = num;
    int i ;
    int kl=-1,kr=-1 ;
    for(i =j ;i< 2*num-1;i++){
        find(i,kl,kr,ls);
        if(kr == -1)break ;
        ls[i]->da.a = ls[kr]->da.a + ls[kl]->da.a ;
        ls[i]->l = kl ;
        ls[i]->r = kr ;
        ls[kl]->p = i ;
        ls[kr]->p = i ;
    }
}

void hafu::init(array<shared_ptr<hafu>,SIZE>&ls,const array<shared_ptr<record>,MAXLINE>&ss){

    int j = 0 ;
    int num = ss[0]->calcu;
    for(j = 0;j < 2*num-1;j++){
      shared_ptr<hafu>p(new hafu);
      if(j<num)
      {  
        p->da.a= ss[j]->cc.a ;
      }
      ls[j] = p ;
    }
    int i = 0;
        
    for(i = 0 ;i< num ;i++){

        ls[i]->da.ch=ss[i]->cc.ch;
    }
    i = 0 ;
    while(1){
        if(i == 2*num-1){
            break ;
        }
        ls[i]->l = 0;
        ls[i]->r = 0;
        ls[i]->p = 0;
        if(i >= num){
            ls[i]->da.ch = '\0';
            ls[i]->da.a = 0;
            i++ ;
            continue ;
        }
        i++ ;
    }
    counts = num ;
    print(ls);
}
#endif
