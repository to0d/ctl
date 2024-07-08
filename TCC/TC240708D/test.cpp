void fun1();

class A{
public:
  ~A(){
     fun1();
  };
};

static A a;

int foo(int x){
  return x;
}