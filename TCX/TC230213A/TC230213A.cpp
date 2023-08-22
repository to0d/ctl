#include <lt_help/lt.h>

using namespace std;
 
int main(void)
{
    const int constant = 10;
    const int* const_p = &constant;
    int* modifier = const_cast<int*>(&constant); 
    
    *modifier = 7;

    cout << "constant: addr=" << &constant << ", value=" << constant  << endl ;
    cout << "const_p : addr=" << const_p   << ", value=" << *const_p  << endl ;
    cout << "modifier: addr=" << modifier  << ", value=" << *modifier << endl ;  
    
    std::cout << "output: ";
}
