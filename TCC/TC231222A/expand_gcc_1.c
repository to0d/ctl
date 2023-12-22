# 1 "test.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "test.c"
int foo1();
int foo2();
# 21 "test.c"
void foo()
{
  int x = 0, y = 0;
  foo1(); foo2(); if( simd_block ) { printf("x=%d", x); } foo1();;
  if( simd_block ) { printf("y=%d", y); };
}
