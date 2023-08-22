#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include "new_1.h"

using namespace std;

void* operator new (size_t sz)
{
    printf("operator new: %d Bytes\n",sz);
    void* m = malloc(sz);
    if (!m) 
    {   cerr <<  "out of memory" << endl;
    }
    
    return m;
}

void operator delete(void * p)
{
    printf("operator delete: %p\n",p);
    free(p);
}

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
};

void test_new_operator_1()
{ 
    B* pB = new B;
    delete pB;
}