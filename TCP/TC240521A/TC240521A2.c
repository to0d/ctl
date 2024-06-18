void foo( int* __restrict__ a
        , int* __restrict__ b
        , int* __restrict__ c
        , unsigned N
        )
{
    for(unsigned i = 1; i < N; ++i){
       c[i] = b[i];
       a[i] = c[i-1];
    }
}