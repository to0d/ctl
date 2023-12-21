#include <stdio.h>
#include "test.h"

int foo1();
int foo2();

void foo() {
    foo1();
    foo2();
    
    if( simd_block )
    {
        int x = 1;
        printf("x=%d", x);
    }
    
    foo1();
    
    if( simd_block )
    {
        int x = 1;
        printf("x=%d", x);
    }
} 
