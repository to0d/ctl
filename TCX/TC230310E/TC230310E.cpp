#include <lt_help/lt.h>

using namespace std;

static int init1 = 0;
static int init2 = 0;

class XX
{
public:
    XX() {init1++;}
    ~XX(){init2++;};
    XX(const XX& x) {}
    XX& operator=(const XX &src)
    {   return *this;
    }
};

class YY
{
public:
    YY() {init1++;}
    ~YY(){init2++;};
    YY(const YY&& x) {}
    YY& operator=(const YY &&src)
    {   return *this;
    }
};

XX fun1()
{   XX x;
    return x;
}

YY fun2()
{   YY y;
    return y;
}

void print()
{   cout << "init1=" << init1 << ", init2=" << init2; 
}

int main(void)
{
    int &&var = 10;
    
    cout << "output: "; 
    XX x = fun1();
    print();
    
    cout << "; "; 
    YY y = fun2();
    print();
    
    cout << endl;
}
