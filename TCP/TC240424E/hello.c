#include <stdio.h>

void f1();
void f2();

int func(int x)
{
    if( x > 1 ){
        printf("x\n");
    }
    
    f1();
    
    if( x > 1 ){
        printf("x2\n");
    }

    f2();
    return x;
}

