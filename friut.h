/*************************************************************************
	> File Name: friut.h
	> Author: 
	> Mail: 
	> Created Time: Thu 01 Nov 2018 01:54:32 AM PDT
 ************************************************************************/

#ifndef _FRIUT_H
#define _FRIUT_H

class friut{
    
public :
    friut(){};
    virtual ~friut(){};
    virtual void plant() ;
    virtual void grow() = 0 ;
    virtual void harvest() ;
};

class apple:public friut{

public:
    apple(){};
    ~apple() {};
    void plant() ;
    void grow() ;
    void harvest() ;
};

class grape:public friut{
    
public:
    grape() {};
    ~grape() {};
    void plant();
    void grow() ;
    void harvest() ;
};

enum type{app= 0 , gra =1};
class garden{

public:
    garden(){};
    ~garden(){};
    friut * getFriut(int i);
private:
    grape *grapes = NULL ;
    apple *apples = NULL ;
};
#endif
