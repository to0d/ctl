int foo1();
int foo2();

#define FOO1(__XX__)            \
    foo1();                     \
    foo2();                     \
                                \
    if( simd_block )            \
    {                           \
        printf("x=%d", __XX__); \
    }                           \
                                \
    foo1();

#define FOO2(__XX__)            \
    if( simd_block )            \
    {                           \
        printf("y=%d", __XX__); \
    } 

void foo()
{
  int x = 0, y = 0;
  FOO1(x);
  FOO2(y);
}