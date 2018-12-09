/*************************************************************************
	> File Name: 2.c
	> Author: 
	> Mail: 
	> Created Time: Sun 18 Nov 2018 04:49:48 AM PST
 ************************************************************************/

#include<stdio.h>
typedef struct A {
  int a;
  char *b;
  char c[8];
} A;

int main(int argc, char *argv[]) {
  char *str = "Linux";
  A test = { .a = 8, .b = str, .c = "Linux" };
  
  char *ptr1 = (char *)(&test + 1) - test.a;
  int **ptr2 = (int **)(&test.a + test.a);

  printf("%c, %c\n", *ptr1, **ptr2);
}
