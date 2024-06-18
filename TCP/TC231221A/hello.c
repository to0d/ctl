#include <stdio.h>


int foo1() {
    int x = 1;
    int *y = &x;
    x = 1;
    *y = 2;
    return x + *y;
}

int foo2();

void foo() {
    foo1();
    foo2();
}
