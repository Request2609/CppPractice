/*************************************************************************
	> File Name: gamehead.h
	> Author: 
	> Mail: 
	> Created Time: Wed 14 Nov 2018 06:36:08 AM PST
 ************************************************************************/

#ifndef _GAMEHEAD_H
#define _GAMEHEAD_H
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<stdio.h>
using namespace std;
#include <termio.h>
#include<string>
#define  N 16
typedef struct qi{
    int x,y ;
    string msg ;
    char keys ;
    char arr[N][N];
}pan;
#endif
