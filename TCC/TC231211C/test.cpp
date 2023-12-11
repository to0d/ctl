#include <stdio.h>

class TestClass
{
public:
    void set_value(int val){
        value = val;
    }

    int value;
};

void fun1(){
    TestClass o1;
    printf("value=%d", o1.value);
    o1.set_value(1);
}
			

