#include <stdio.h>

struct XX
{
   int val;
};

void foo(XX* x1, XX& x2) {
    XX x3;
    
    printf("x=%d", x1->val);
    printf("x=%d", x2.val);
    printf("x=%d", x3.val);
} 


void foo2(double* x, int y) {
    printf("x=%f", *x);
    printf("y=%d", y);
}