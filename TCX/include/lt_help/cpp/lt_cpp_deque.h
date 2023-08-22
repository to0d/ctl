#ifndef __LT_CPP_DEQUE__
#define __LT_CPP_DEQUE__

#include <lt_help/cpp/lt_cpp_base.h>

template <typename T>
void outputDeque(const T& output)
{   std::cout << output;
}


template <typename T>
void outputDeque(const std::deque<T>& _deque)
{
    std::cout << "[";
    for(int i =0 ;i < _deque.size(); ++i)
    {   
        if( i != 0 )
            std::cout << ",";
        std::cout << _deque[i];
    }
    
    std::cout << "]";
}


    
#endif //__LT_CPP_DEQUE__