#include <stdio.h>

void func1(int a1);
void func2(double c);

int global_a = 1;

void test()
{
    int a = 0;
    float b = 0;
    double c = 0;
    
    func1(1);
    func1(a);
    func1(global_a);
    func2(c);
}

