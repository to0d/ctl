#include <lt_help/lt.h>

using namespace std;
 
struct Base {
  virtual int doSomething() const {
    return 0;
  }
};

struct Derivied1 : Base {
  virtual int doSomething() {
   return 1;
  }
};

struct Derivied2 : Base {
  //virtual int doSomething() override { // compiler error ==> marked ‘override’, but does not override
  virtual int doSomething() const override {
    return 2;
  }
};
 
int func(Base& base) {
    return base.doSomething();
}
 
int main(void)
{
    Derivied1 d1;
    Derivied2 d2;
    std::cout << "output: d1=" << func(d1) << ", d2=" << func(d2) << endl;
}
