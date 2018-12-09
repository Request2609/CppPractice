/*************************************************************************
	> File Name: 11.c
	> Author: 
	> Mail: 
	> Created Time: Sun 18 Nov 2018 05:01:42 AM PST
 ************************************************************************/

#include<stdio.h>
int func(unsigned int num) {
  unsigned int i;
  for (i = 0; num; i++) {
    num &= (num - 1);
  }
  return i;
}
int main(int argc, char *argv[]) {

}
