#include <stdio.h>

int func(int x)
{
    if( x > 1 ){
        x++;
    }

    for(int i = 0; i < 3; ++i)
        x++;
    
    return x;
}

