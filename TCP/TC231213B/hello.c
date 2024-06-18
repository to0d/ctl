#include <stdio.h>

void func(int x)
{
    x = 0;
    
    if( x > 1 )
        printf("never run here\n");
    else
        printf("should run here\n");
    
    
}

