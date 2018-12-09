/*************************************************************************
	> File Name: 4.c
	> Author: 
	> Mail: 
	> Created Time: Sun 18 Nov 2018 10:11:04 PM PST
 ************************************************************************/

#include<stdio.h>
//编程：请实现一个字符串拷贝函数
//并对实现做出解释，测试函数如下
#define N 100
#include<stdlib.h>
#include<string.h>
void my_strcpy(char *str1,char * str){
	if((*str) == '\0'){
		*str1='\0';
	}
	else{
        int i=0 ;
        while((*(str1++)=*(str++))!='\0');
    }
}
int main(){
	
	char str[N]="Hello Linux!";
	char str1[N];
	bzero(str1,strlen(str1));
	my_strcpy(str1,str);
	printf("str = %s\n",str);
	printf("str1 = %s\n",str1); 
} 


