/*************************************************************************
	> File Name: 12.c
	> Author: 
	> Mail: 
	> Created Time: Sun 18 Nov 2018 05:03:09 AM PST
 ************************************************************************/

#include<stdio.h>
int main(int argc, char *argv[]) {
  FILE *fp = fopen("s.txt", "wb");
  int a = 1414550872;
  fwrite(&a, sizeof(a), 1, fp);
}

