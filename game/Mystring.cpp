#include<stdio.h>
#include<iostream>
using namespace std ;
class My_string{

private:
    char* str;
    int len;
public:
    My_string();
    My_string(const My_string&str);
    My_string(char * p);
    ~My_string();
};

My_string::My_string(){

    len = 0 ;
    strcpy(str,"");
}

My_string::My_string()