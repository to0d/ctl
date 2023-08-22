#ifndef __LT_CPP_VECTOR__
#define __LT_CPP_VECTOR__

#include <lt_help/cpp/lt_cpp_base.h>

template <typename T>
void outputVector(const T& output)
{   std::cout << output;
}


template <typename T>
void outputVector(const std::vector<T>& output)
{
    std::cout << "[";
    for(int i =0 ;i < output.size(); ++i)
    {   
        if( i != 0 )
            std::cout << ",";
        outputVector(output[i]);
    }
    
    std::cout << "]";
}


template <typename T>
void outputVector(const std::vector<std::vector<T>>& output)
{
    std::cout << "[";
    for(int i =0 ;i < output.size(); ++i)
    {   
        if( i != 0 )
            std::cout << ",";
        outputVector(output[i]);
    }
    
    std::cout << "]";
}

    
#endif //__LT_CPP_VECTOR__