#include "stdio.h"

int main(void)
{
    int b = 5;
    #define b  1
    #define f(x) b*(x)
    printf("macro b(1)* 1    = %d\n", f(1)); 

    #undef b
    printf("variable b(5)* 1 = %d\n", f(1)); 
    
    printf( "output: done. \n" );
    
    return 0;
}
