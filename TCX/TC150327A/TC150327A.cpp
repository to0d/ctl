#include <lt_help/lt.h>

int main( void )
{
    
    // construction uses aggregate initialization
    std::array<int, 3> a1{ {1,2,3} };  // double-braces required
    std::array<int, 3> a2 = {1, 2, 3}; // except after =
    std::array<std::string, 2> a3 = { std::string("a"), "b" };
    
    std::cout << "output: ";

    // container operations are supported
    std::sort(a1.begin(), a1.end());
    std::cout << "reverse_copy a2: ";
    std::reverse_copy(a2.begin(), a2.end(),std::ostream_iterator<int>(std::cout, " "));                  
    std::cout << "; ";

    //ranged for loop is supported
    std::cout << "auto a3: ";
    for(auto s: a3) std::cout << s << ' ';
    std::cout << endl;  
    
    return 0;
}
