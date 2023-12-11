#include <iostream>

int add2(int* __restrict a, int* __restrict b) 
{
    *a = 1;
    *b = 2;
    return *a + *b ;
}

int main(void)
{
    {
        int x = 0, y = 0;
        int z = add2(&x, &x);
        std::cout<< "bad : x=" << x << ", y=" << y << ", z=" << z << std::endl;
    }
    
    {
        int x = 0, y = 0;
        int z = add2(&x, &y);
        std::cout<< "good: x=" << x << ", y=" << y << ", z=" << z << std::endl;
    }

    return 0;
}