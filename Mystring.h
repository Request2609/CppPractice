#ifndef _MYSTRING_H_
#define __MYSTRING_H_
#include<string.h>
#include<iostream>
using namespace std;
class mystring{

    friend ostream&operator<<(ostream &out,mystring &s);
    friend istream&operator>>(istream &in ,mystring &s);
private:
    char* p ;
    int len ;
public:
    mystring();
    mystring(int len);
    mystring(const char * p);
    bool operator==(const mystring &s);
    mystring(const mystring &s);
    ~mystring();
public:
    mystring& operator=(const mystring &s);
    mystring& operator=(const char *q);
    bool operator==(const char * s);
    char operator[](const int i);
    bool operator!=(const mystring &s);
    bool operator!=(const char * s);
    int operator>(const char *s);
    int operator>(const mystring&s);
    int operator<(const char* s);
    int operator<(const mystring &s);
};

istream&operator>>(istream &in ,mystring &s){
    cin>>s.p;
    return in ;
}

int mystring::operator>(const mystring &s){
    return strcmp(p,s.p) ;
}

int mystring::operator<(const char*s){
    return strcmp(p,s) ;
}
int mystring::operator<(const mystring &s){
    return strcmp(p,s.p);
}

int mystring::operator>(const char*s){
    return strcmp(p,s);
}

bool mystring::operator!=(const mystring &s){

    if(!strcmp(p,s.p)){
        return false ;
    }
    return true ;
}

bool mystring::operator!=(const char * s){
    if(p==NULL){
        if(len ==0)
             return false ;
        else{
            return true ;
        }
    }
    if(!strcmp(p,s)){
        return false ;
    }
    else{
        return true;
    }
}
bool mystring::operator==(const mystring&s){

    if(strcmp(s.p,p)==0){
        return true;
    }
    else{
        return false;
    }
}

bool mystring::operator==(const char *s){
    if(s==NULL){
        if(len == 0){
            return true ;
        }
        else{
            return false ;
        }
    }
        if(strcmp(s,p)==0){
            return true ;
        }
        else{
            return false ;
        }
}

ostream&operator<<(ostream &out,mystring &s){
    out<<s.p;
    return out;
}

char mystring::operator[](const int i){
    return p[i];
}

mystring &mystring::operator=(const char*q){
    if(p!= NULL){
        delete[]p ;
        len = 0 ;
    }
    if(q==NULL){
        len = 0 ;
        p = new char[len+1];
        strcpy(p,"");
    }
    else{
        int lenth = strlen(q);
        p = new char[lenth];
        len = lenth ;
        len = strlen(q);
        strcpy(p,q);
    }
    return *this ;
}

mystring &mystring::operator=(const mystring&s){
    if(p != NULL){
        delete[]p;
        len = 0 ;
    }
    len = s.len ;
    p = new char[len+1];
    strcpy(p,s.p);
    return *this ;
}

mystring ::mystring(int len){
    if(len == 0){
        (*this).len = 0 ;
        p = strcpy(p,"");
    }
    else{
        (*this).len = len ;
        p = new char[len];
        bzero(p,strlen(p));
    }
} 
mystring::mystring(){
    len = 0 ;
     p = new char[len+1];
     strcpy(p,"");
}

mystring::mystring(const char *s){
    if(p==NULL){
        len = 0 ;
        p = new char[len+1];
        strcpy(p , "");
    }
    else{
        len = strlen(s);
        p = new char[len+1];
        strcpy(p,s);
    }
}

mystring::mystring(const mystring& s){
    int lenth = s.len;
    p = new char[lenth];
    strcpy(p,s.p);
}
mystring::~mystring(){

    if( p != NULL){
        delete[]p ;
        len = 0 ;
    }
}
#endif