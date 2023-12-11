#include <stdio.h>

int add2(int* __restrict a, int* __restrict b) 
{
    *a = 1;
    *b = 2;
    return *a + *b ;
}

