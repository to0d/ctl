#include "stdio.h"

void foo1(int val);
void foo2(int val);

__attribute__((always_inline)) void func(int x){
    int y = x + 1;
    foo1(y);
    foo2(2);
}

__attribute__((always_inline)) void func2(int x);