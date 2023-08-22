#ifndef __LT_CPP_SET__
#define __LT_CPP_SET__

#include <lt_help/cpp/lt_cpp_base.h>

template <typename T>
void outputSet(const T& _set)
{
}


template <typename T>
void outputSet(const std::set<T>& _set)
{
    std::cout << "(";
    int i = 0;
    for(auto it = _set.begin(); it != _set.end(); ++it, ++i)
    {   if( i != 0 )
            std::cout << ",";
        std::cout << *it; 
    } 
    std::cout << ")";
}


#endif //__LT_CPP_SET__