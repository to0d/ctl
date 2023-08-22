#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include "new_2.h"

using namespace std;

//  全局replacement new 重载是不可行的
//   void* operator new (size_t sz, void* ptr)
//   {
//       printf("operator replacement new: %d Bytes, addr=%p\n",sz,ptr);
//       return ptr;
//   }
    
class B
{
public:

    B()
    { cout << "B::B()" << endl;}
    
    B(int v) : value(v)
    { cout << "B::B("<<v<<")" << endl;}
    
    ~B()
    { cout << "B::~B()" << endl;}
    
    int value;
    
    virtual void fun()
    {}
    
    void* operator new (size_t sz, void* ptr)
    {
        printf("operator replacement new: %d Bytes, addr=%p\n",sz,ptr);
        return ptr;
    }
    
};

void test_new_operator_2()
{ 
    char buf[246];
    
    printf("buf: addr=%p\n", buf);
    
    B* pB = new(buf) B;
}