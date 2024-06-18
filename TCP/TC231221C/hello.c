#include <stdio.h>

int foo1();
int foo2();

int simd_block = 1;

void foo() {
    foo1();
    foo2();
    
    if( simd_block )
    {
        int x = 1;
        printf("x=%d", x);
    }
    
    foo1();
} 
