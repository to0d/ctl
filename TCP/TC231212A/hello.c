#include <stdio.h>

int func() 
{
    int x = 1;
    int *y = &x;
    int z = *y;
    return x + *y + z;
}

