/*************************************************************************
	> File Name: readline.h
	> Author: 
	> Mail: 
	> Created Time: Sun 18 Nov 2018 03:14:38 AM PST
 ************************************************************************/

#ifndef _READLINE_H
#define _READLINE_H
#include"unp.h"
ssize_t readline(int fd,void*vptr,size_t maxlen){
    
    ssize_t n,rc;
    char c;
    char *ptr ;
    ptr = (char*) vptr ;
    for(n =1 ; n< maxlen;n++){
    again:
        if((rc = read(fd,&c,1))==1){
            *ptr++ = c ;
            if(c== '\n'){
                break ;
            }
        }
        else if(rc==0){
                *ptr = 0 ;
                return (n-1);
            }
        else{
            if(errno==EINTR)
                goto again;
            return -1;
            }
        }
    *ptr = 0 ;
    return n;
}
#endif
