#include "stdio.h"

void foo1(int val);
void foo2(int val);

__attribute__((always_inline)) void func(int x){
    int positions_src0[3] = {0, 2, 3};
    printf("call inline func\n");
    printf("xx=%d\n", positions_src0[1]);
    int y = x + 1;
    foo1(y);
    foo2(2);
}
