#ifndef __LT_CPP_MAP__
#define __LT_CPP_MAP__

#include <lt_help/cpp/lt_cpp_base.h>

template <typename T>
void outputMap(const T& output)
{   std::cout << output;
}


template <typename K, typename V>
void outputMap(const std::map<K, V>& _map)
{
    std::cout << "{";
    int i = 0;
    for(auto it = _map.begin(); it != _map.end(); ++it, ++i)
    {   if( i != 0 )
            std::cout << ",";
        std::cout << it->first << "=" << it->second; 
    }   
    std::cout << "}";
}
    
#endif //__LT_CPP_MAP__