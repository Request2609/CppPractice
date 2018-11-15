/*************************************************************************
	> File Name: 145.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Oct 2018 05:33:57 PM PDTmZ
#ifndef STACK_H_
#define STACK_H_
class father{
    
protected: 
    int data ;
    
public:
    father();
    ~father();
};

class stack :public father{

private:
    stack* next ;
    stack** top ;
public:
    stack();
    ~stack();
    void pop();
    void push();
    void destroy();
};

father :: father();
father :: ~father();
stack :: stack():
stack :: ~stack();
void stack :: pop();
void stack :: push();
void stack :: destroy();
#endif
