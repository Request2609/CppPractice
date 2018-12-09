#ifndef  _STRING_H_
#define _STRING_H_
#include<iostream>
#include<string.h>
using namespace std ;
class mystring{
    friend ostream&operator<<(ostream &out,mystring&h);
    friend istream&operator>>(istream&in,mystring&p);
private:
    char *p;
    int len ;

public :
    mystring();
    mystring(int length);
    mystring(char* ss);
    mystring(const mystring&h);
    ~mystring(); 
public:
    char operator[](int i);
    mystring&operator=(const char *ss);
    mystring&operator=(const mystring&h);
    bool operator>(const char*ss);
    bool operator>(const mystring &h);
};

bool mystring::operator>(const char *ss){

    return strcmp(p,ss) ?true:false;
}


istream&operator>>(istream&in,mystring&h){
    cin>>h.p;
    return in ;
}

ostream&operator<<(ostream&out,mystring&h){
    out<<h.p;
    return out ;
}
bool mystring::operator>(const mystring &h){

    return strcmp(p,h.p) ?true:false;
}

mystring ::~mystring(){
    if(p!=NULL){
        delete[]p ;
        len = 0 ;
    }
    else{
        len = 0 ;
    }
}
mystring&mystring::operator=(const char* ss){
   
    if(p != NULL){
        delete[]p ;
        len  = 0; 
    }
    if(ss == NULL){
        len =  0;
        p = new char[len+1];
        strcpy(p,"");
    }
    if(ss!=NULL){
        len = strlen(ss);
        p = new char[len+1];
        strcpy(p,ss);
    }
    return *this ;
}

mystring&mystring::operator=(const mystring&h){
    
    if(p == NULL){
        len = strlen(h.p) ;        
        p = new char[len+1];
        strcpy(p,h.p);
    }
    else{
        delete[]p ;
        len = strlen(h.p);
        p = new char[len];
        strcpy(p,h.p);
    }
    return *this ;
}
char mystring::operator[](int i){
    if(i >= len){
        return '\0';
    }
    else{
        return p[i];
    }
}

mystring::mystring(){
    
    len= 0;
    p = new char[len+1];
    strcpy(p,"");
}

mystring ::mystring(int length){
    len = length ;
    p = new char [len+1];
    bzero(p,sizeof(p));
}
mystring::mystring(char * ss){
    if(ss == NULL){
        len= 0 ;
        p = new char[len+1];
        strcpy(p,"");    
    }
    else{
        len = strlen(ss);
        p = new char[len+1];
        strcpy(p,ss);
    }
}
mystring ::mystring(const mystring&h){
    
    if(h.p == NULL){
        len = 0 ;
        p = new char[len+1];
        strcpy(p,"");
    }
    else{
        len = strlen(h.p);
        p = new char[len+1];
        strcpy(p,h.p);
    }
}
#endif