#include <iostream>

using namespace std;

int main(void)
{
    std::cout << "output: ";
    
    class InnerA
    {
    public:
        class Inner2A
        {
        public:
            Inner2A()
            {
                std::cout << "Inner2A::Inner2A()" << ", ";
            }
        };

    public:
        InnerA()
        {
            std::cout << "InnerA::InnerA()" << std::endl;
        }
    private:
        Inner2A a;

    }; 

    {
        InnerA a;
    }      
    
    return 0;
}
