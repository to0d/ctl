#include "test.h"

extern "C"{
    
class C1
{
public:
    C1(int val):value(val){}; 
    int get_value(){return value+1;}
private:
    int value;
};

int func(int x)
{
    C1 c(1);
    return x + c.get_value();
}

}