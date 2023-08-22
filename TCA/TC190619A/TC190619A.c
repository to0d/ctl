#include <string.h>
#include <stdio.h>  
#include <stdlib.h> 
#include <ctype.h>  
#include <stdarg.h>

int* makeNext(const char *p){
    int len   = strlen(p);
    int* next = (int*) malloc(sizeof(int)*len); 
    memset(next, 0, sizeof(int)*len);
    next[0] = -1;

    int j = 0, k = -1;
    while( j < (len-1) )
    {   if( k == -1 || p[j] == p[k] )
            next[++j] = ++k;
        else
            k = next[k];
    }

    return next;
}

int strStr(const char* s, const char* t) {  //KMP algorithm
    int t_len = strlen(t);
    if(t_len == 0)
        return 0;
    
    int s_len = strlen(s);
    if(s_len == 0)
        return -1;
    
    int *next = makeNext(t);
    int i = 0, j = 0; 
    while( i < s_len && j != t_len)
    {   if( j == -1 || s[i] == t[j] )
        {   ++i;
            ++j;
        }
        else
            j = next[j];
    }

    free(next);
    return j == t_len ? i - t_len : -1;
}


void main()
{
    int pos = strStr( "[2019-05-19 02:30:34]: Call QteStartViewCreation:"
                     ,"Call QteStartViewCreation:"
                     );
    printf("output: location=%d\n", pos);
}