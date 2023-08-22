#include <iostream>

//#################################################################################
//
//
//
//#################################################################################

using namespace std;

void test_xxx_1();

int  main(void)
{
   test_xxx_1();
   return 0;
}

class A
{
	char a[7];
public:
	virtual void foo() { cout << "A";}
	virtual void fa(){};
};

class B :public A
{
	char b[7];
public:
	virtual void foo() { cout << "B";}
	virtual void fb(){};
};

class C :public B
{
	char c[7];
public:
	virtual void foo() { cout << "C";}
	virtual void fc(){};
};

void test_xxx_1()
{
    std::cout <<"\n==>  test_xxx_1: \n\n";
        
    A* pa = new A();
	pa->foo();
	B* pb = (B*) pa;
	pb->foo();
 	delete pa,pb;

	int i = 2;
	pa = new B();
	pa->foo();
	pb = (B*) pa;
	pb->foo();
	cout << endl;

	cout << "sizeof(A)=" << sizeof(A) << endl;
	cout << "sizeof(B)=" << sizeof(B) << endl;
	cout << "sizeof(C)=" << sizeof(C) << endl;

    cout << "output: done!" << endl;
}
