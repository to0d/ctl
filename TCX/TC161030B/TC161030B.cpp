#include <lt_help/lt.h>
#include <lfc/trace/lfc_dump_mem_hex.h>
#include "new_1.h"
#include "new_2.h"

using namespace std;

class A
{
public:

    A()
    { cout << "A::A()" << endl;}
    
    A(int v) : value(v)
    { cout << "A::A("<<v<<")" << endl;}
    
    ~A()
    { cout << "A::~A()" << endl;}
    
    int value;
    
    virtual void fun()
    {}
};

int main(void)
{
    /* *********************************************** */
    /*  Usage about new operator                       */
    /* *********************************************** */
    {   
        cout << "---------------------------------------------\n" 
             << "Test 01: Usage about new operator \n";    
        
        cout << " sizeof(class A)=" <<  sizeof(A) << endl;
        cout << " sizeof(int)=" <<  sizeof(int) << endl;
        
        A* pA = new A(204); // HEX CC
        lfc_dump_memory_hex((void *) pA, sizeof(A));
        delete pA;
        
        /* HEX OUTPUT:                                  */
        /*  sizeof(class A)=8                           */
        /*  sizeof(int)=4                               */
        /* A::A(204) ==> HEX CC                         */
        /*    00000     D88E0408 CC000000 ........ .....*/
        /*              -------- --------               */
        /*                  |       |                   */
        /*                  V       V                   */
        /*                V Table  A.value              */
        /*               (virtual)                      */
    }
    
    {   
        cout << "---------------------------------------------\n" 
             << "Test 02: Usage about new operator \n"; 

        char buf[8] = {0};
        cout << "1st HEX of buf:\n";
        lfc_dump_memory_hex((void *) buf, sizeof(buf));
        
        A* pA = new(buf) A;
        pA->value = 0XF1F1F1F1;
        printf("pA->value=%x\n", pA->value);
        
        cout << "2st HEX of buf:\n";
        lfc_dump_memory_hex((void *) buf, sizeof(buf));
        
        // delete pA; will lead to "Segmentation fault"
    }
    
    {
        cout << "---------------------------------------------\n" 
             << "Test 03: override new operator - void* operator new (size_t sz)\n"; 
        test_new_operator_1();
    }
    
    {
        cout << "---------------------------------------------\n" 
             << "Test 04: override replacement new operator - void* class::operator new (size_t sz, void* ptr)\n"; 
        test_new_operator_2();
    }
    
    std::cout << "output: ";
    
    return 0;
}

