#include <stdio.h>

void func(int val){
    printf("hello, val=%d\n", val);
}


int main() {
   int x = 1;
   printf("Cons 0  : ");
   func(0);
   printf("Var  x  : ");
   func(x);
   printf("Expr x+1: ");
   func(x+1);
   return 0;
}