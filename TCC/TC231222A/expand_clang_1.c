# 1 "test.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 361 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "test.c" 2
int foo1();
int foo2();
# 21 "test.c"
void foo()
{
  int x = 0, y = 0;
  foo1(); foo2(); if( simd_block ) { printf("x=%d", x); } foo1();;
  if( simd_block ) { printf("y=%d", y); };
}
