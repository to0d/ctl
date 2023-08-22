#include <iostream>

using namespace std;

class A
{
    friend class FriendOfA;
    friend void print(A& a);
        
    public:        
        
        A(int x);
        A(const A& a);
        
        ~A();
        
    public:
    
        A fun1(A a);  
        static void fun2(A& a);
     
    private:
        int mx;  
        static int ms;
        const static int ms2;
        const int   mc;
        const int & mr;
};

int A::ms = 10;
const int A::ms2 = 20;

class FriendOfA
{
    public:
    
        static void print(A& a)
        {
            std::cout << "FriendOfA::print( ( A(" <<a.mx << ") )" << std::endl; 
        }
};

void A::fun2(A& a)
{
    std::cout << "A::fun2( A(" <<a.mx << ") )" << std::endl;
    std::cout << "static A::ms("<<A::ms<<")" << std::endl;
    std::cout << "const static A::ms2("<<A::ms2<<")" << std::endl;
    std::cout << "const a.mc("<<a.mc<<")" << std::endl;
    std::cout << "const ref a.mr("<<a.mr<<")" << std::endl;
}

A A::fun1(A a)
{    
    std::cout << "A("<<mx<<").fun1( A(" <<a.mx << ") )" << std::endl;
    return a;
}

A::A(int x): mx(x), mc(mx + 1), mr(mc)
{
    std::cout << "A::A("<<mx<<")" << std::endl;
}

A::A(const A& a):mx(a.mx), mc(mx + 1), mr(mc)
{
    std::cout << "A::Copyof A("<<a.mx<<")" << std::endl;
}

A::~A()
{
    std::cout << "A::~A("<<mx<<")" << std::endl;
}

void print(A& a)
{
   std::cout << "friend::print( ( A(" <<a.mx << ") )" << std::endl; 
}

int main(void)
{
    A a(1);
    A b(2);

    A* pc = new A(a);

    a.fun1(b);       

    delete pc; 

    std::cout <<"-----------static-----------------\n";
    A::fun2(a);      

    std::cout <<"-----------friend-----------------\n";
    print(a); 
    FriendOfA::print(a);
    
    std::cout << "output: done!" << endl;
    
    return 0;
}
