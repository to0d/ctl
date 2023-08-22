#include <iostream>
#include <stdio.h>

using namespace std;

class A
{
    public:
        A() {}
        A(const A& a) { *this = a;  }
        
        A& operator = ( const A& a );
};


A& A::operator =(const A&a)
{
    std::cout << "Copy-";
            
    if( this != &a)
    {
        std::cout << "Yes";
    }                
    else
    {
        std::cout << "No";
    }
            
    return *this;
}

class B
{
    public:
        B() {  std::cout << "New-B;"; }
       
};

int main(void)
{
    {
        std::cout <<"----------------------------------\n";

        A a;  
        printf("%-20s:%-10s= ","a = a;","NO"); a = a; std::cout <<std::endl;    
        printf("%-20s:%-10s= ","A c(a);","Yes"); A c(a); std::cout <<std::endl;
        printf("%-20s:%-10s= ","A b = a;","Yes"); A b = a; std::cout <<std::endl;
    }

    {
        std::cout <<"----------------------------------\n";
        printf("%-20s:%-10s= ","B b1[2]; ","Yes"); B b1[2]; std::cout <<std::endl;
        printf("%-20s:%-10s= ","B b2[] = {B(),B()}; ","Yes"); B b2[] = {B(),B()}; std::cout <<std::endl;
    }
    
    std::cout << "output: done!" << endl;
    
   return 0;
}

