#include <stdio.h>

int func() 
{
    int x = 1;
    int *y = &x;
    x = 1;
    *y = 2;
    return x + *y;
}

