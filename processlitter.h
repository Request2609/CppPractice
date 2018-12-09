#ifndef _PROCESSLITTER_H_
#define  _PROCESSLITTER_H_
#include"hafuman.h"
using namespace std;
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
    static void countchars(const char* arr,const char*zimu,array<shared_ptr<record>,MAXLINE>&ls);
    static void Cout(array<shared_ptr<record>,MAXLINE>&ls,int len );
};

void record::Cout(array<shared_ptr<record>,MAXLINE>&ls,int len){

    int  i = 0 ;
    for(i = 0 ; i < len ; i++){
        cout<<ls[i]->cc.ch<<"     "<<ls[i]->cc.a<<endl ;
    }
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
    Cout(ss,count-1);
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
    // Cout(ss,count);
}
#endif
