#include <iostream>
#include <stdio.h>

using namespace std;

class A
{
    public:
        int c;
        int d;
        
        int fund();
        int func() const { return c; };
        
        A(const A& a)
        {
            *this = a;
        }

        A();
};

A::A() : c(3), d(4)
{
}

int A::fund()
{
    return d;
}

int main(void)
{

    int A:: *pc = &A::c;   
    int (A:: *pfc)() const = &A::func;    
    int (A:: *pfd)() = &A::fund;
    
    A a;
    A* pa = &a;
    
    printf("%-20s:%-10s= %d\n", "int A:: *pc = &A::c;", "a.*p1"  , a.*pc);
    printf("%-20s:%-10s= %d\n", "A* pa = &a;",          "pa->*pc", pa->*pc);
    
    printf("%-20s:%-10s= ","int (A:: *pfc)() const = &A::func;","(a.*pfc)()"); std::cout << (a.*pfc)() << std::endl;
    printf("%-20s:%-10s= ","int (A:: *pfd)() = &A::fund;","(a.*pfd)()"); std::cout << (a.*pfd)() << std::endl;

    std::cout << "output: done!" << endl;
    
    return 0;
}

