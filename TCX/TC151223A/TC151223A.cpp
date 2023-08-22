#include <lt_help/lt.h>

struct A 
{
    long a1;
    short a2;
} a;

struct B
{
    char   a1;  //1
    int    a2;  //4
    short  a3;  //2
    char   a4;  //1
    double a5;  //8
} b;

class EmptyClass
{};

struct EmptyStruct
{};
    
class BaseClassWithVirtualFunction
{
   public:
        virtual ~BaseClassWithVirtualFunction() = 0;
};

class BaseClassWithoutVirtualFunction
{};

class DerivedClassWithoutVirtualFunction1 : public BaseClassWithVirtualFunction
{};

class DerivedClassWithVirtualFunction2 : public BaseClassWithVirtualFunction
{       
    public:
        virtual void fun(){}
};

class VirtualDerivedClass : public virtual BaseClassWithoutVirtualFunction
{};

int main(void)
{
    cout <<"sizeof(char)  ="<< sizeof(char) << endl;
    cout <<"sizeof(short) ="<< sizeof(short) << endl;
    cout <<"sizeof(int)   ="<< sizeof(int) << endl;
    cout <<"sizeof(long)  ="<< sizeof(long) << endl;
    cout <<"sizeof(float) ="<< sizeof(float) << endl;
    cout <<"sizeof(double)="<< sizeof(double) << endl;
      
    cout <<"sizeof(A)="<< sizeof(A) <<", sizeof(B)="<< sizeof(B) << endl;
     
    cout <<"Offset B::a1 char  = "<< ( (long)&(b.a1) - (long)&(b)) << endl;
    cout <<"Offset B::a2 int   = "<< ( (long)&(b.a2) - (long)&(b)) << endl;
    cout <<"Offset B::a3 short = "<< ( (long)&(b.a3) - (long)&(b)) << endl;
    cout <<"Offset B::a4 char  = "<< ( (long)&(b.a4) - (long)&(b)) << endl;
    cout <<"Offset B::a5 doubl = "<< ( (long)&(b.a5) - (long)&(b)) << endl << endl;
    
    cout <<"sizeof(EmptyClass)  = "<< sizeof(EmptyClass) << endl;
    cout <<"sizeof(EmptyStruct) = "<< sizeof(EmptyStruct) << endl << endl;
     
    void* pVoid = NULL;
    
    cout <<"sizeof(pVoid)       = "<< sizeof(pVoid) << endl;
    cout <<"sizeof(BaseClassWithVirtualFunction)        = "<< sizeof(BaseClassWithVirtualFunction) << endl;
    cout <<"sizeof(DerivedClassWithoutVirtualFunction1) = "<< sizeof(DerivedClassWithoutVirtualFunction1) << endl;
    cout <<"sizeof(DerivedClassWithVirtualFunction2)    = "<< sizeof(DerivedClassWithVirtualFunction2) << endl;
    cout <<"sizeof(BaseClassWithoutVirtualFunction)     = "<< sizeof(BaseClassWithoutVirtualFunction) << endl;
    cout <<"sizeof(VirtualDerivedClass)                 = "<< sizeof(VirtualDerivedClass) << endl;
    
    std::cout << "output: done!" << endl;
}
